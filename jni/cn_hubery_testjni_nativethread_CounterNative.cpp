#include <stdio.h>
#include <pthread.h>
//#include "cn_hubery_testjni_nativethread_CounterNative.h"
#include <android/log.h>
#include <jni.h>


#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, "System.out", __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG , "System.out", __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO  , "System.out", __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN  , "System.out", __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , "System.out", __VA_ARGS__)


jmethodID mid;
jclass mClass;
JavaVM* jvm;
pthread_t thread;
int n, sum;

void* trRun(void*);

/*
 * Class:     cn_hubery_testjni_nativethread_CounterNative
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_hubery_testjni_nativethread_CounterNative_nativeSetup
  (JNIEnv *env, jobject thiz)
{
	jclass clazz = env->GetObjectClass(thiz);
	mClass = (jclass)env->NewGlobalRef(clazz);
	mid = env->GetStaticMethodID(mClass, "callback", "(I)V");
}

/*
 * Class:     cn_hubery_testjni_nativethread_CounterNative
 * Method:    execute
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_cn_hubery_testjni_nativethread_CounterNative_nativeExec
  (JNIEnv *env, jobject thiz, jint numb)
{
	n = numb;
	pthread_create(&thread, NULL, trRun, NULL);//创建本地线程
}

/**
 * Native thread function
 */
void* trRun(void*)
{
	int status;
	JNIEnv *env;
	bool isAttached = false;

	status = jvm->GetEnv((void**) &env, JNI_VERSION_1_4);
	if(status < 0)
	{
		//向VM注册线程，让VM产生JNIEnv对象，并将指针存入env里；
		status = jvm->AttachCurrentThread(&env, NULL);
		if(status < 0)
		{
			return NULL;
			isAttached = true;
		}
	}

	sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += i;
	}
	//有了env， 就可以调用java层的函数
	env->CallStaticVoidMethod(mClass, mid, sum);
	if(isAttached)
	{
		jvm->DetachCurrentThread();
	}

	return NULL;
}

/*dynamic regist methods into VM*/
static const char *classPathName = "cn/hubery/testjni/nativethread/CounterNative";

/**
 * 映射本地函数与Java层函数 init即对应本地函数nativeSetup
 */
static JNINativeMethod methods[] ={
	{"init", "()V",(void*)Java_cn_hubery_testjni_nativethread_CounterNative_nativeSetup},
	{"execute", "(I)V", (void*)Java_cn_hubery_testjni_nativethread_CounterNative_nativeExec}
};

static int registerNativeMethods(JNIEnv *env, const char* className, JNINativeMethod *gMethods, int numMethods)
{
	jclass clazz = env->FindClass(className);
	env->RegisterNatives(clazz, gMethods, numMethods);
	return JNI_TRUE;
}

static int registerNatives(JNIEnv *env)
{
	registerNativeMethods(env, classPathName, methods, sizeof(methods)/sizeof(methods[0]));
	return JNI_TRUE;
}

/**
 * VM加载JNI模块时，先调用该函数，并且向VM动态注册JNI本地函数
 */
jint JNI_Onload(JavaVM *vm, void *reserved)
{
	LOGI("JNI_Onload");

	JNIEnv *env;
	jvm = vm;
	if(registerNatives(env) != JNI_TRUE)
	{
		return -1;
	}

	return JNI_VERSION_1_4;
}












