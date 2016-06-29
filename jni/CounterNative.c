#include <jni.h>

jclass m_class;//全局类
jobject m_object;//全局对象
jmethodID m_mid_static;//静态方法ID
jmethodID m_mid;//普通方法ID
jfieldID m_fid;//java变量ID

/*
 * Class:     cn_hubery_testjni_exams_CounterNative
 * Method:    nativeSetup
 * Signature: ()V
 * thiz:java层当前对象引用；即CounterNative类对象引用；
 */
JNIEXPORT void JNICALL Java_cn_hubery_testjni_exams_CounterNative_nativeSetup
  (JNIEnv *env, jobject thiz)
{
	jclass clazz = (*env)->GetObjectClass(env, thiz);//向VM查询thiz所引用对象的类是啥(CounterNative)
	m_class = (jclass)(*env)->NewGlobalRef(env, clazz);//通过,clazz 构造全局类对象 因为函数执行完，局部变量clazz清零；
	m_object = (*env)->NewGlobalRef(env, thiz);//拿到对象 放到全局环境中 供其他函数调用
	m_mid_static = (*env)->GetStaticMethodID(env, m_class, "setValue", "(I)V");//拿到setValue方法ID
	m_mid = (*env)->GetMethodID(env, m_class, "setV", "(I)V");//拿到setV方法ID
	m_fid = (*env)->GetFieldID(env, clazz, "numb", "I");//拿到java层具体变量
	return;
}

/*
 * Class:     cn_hubery_testjni_exams_CounterNative
 * Method:    nativeExcute
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_cn_hubery_testjni_exams_CounterNative_nativeExcute
  (JNIEnv *env, jclass jclazz, jint n)
{
	int i = 0;
	int sum = 0;
	for(i = 0; i <= n ; i++)
	{
		sum += i;
	}
	//根据m_object和m_mid，通过VM能够调用当前对象的setV函数；把数据传送到java层；
	(*env)->CallVoidMethod(env, m_object, m_mid, sum);
	return;

}

/*
 * Class:     cn_hubery_testjni_exams_CounterNative
 * Method:    nativeExec
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_cn_hubery_testjni_exams_CounterNative_nativeExec
  (JNIEnv *env, jobject jthiz, jint n)
{
	int i = 0;
	int sum = 0;
	for(i = 0; i <= n; i++)
	{
		sum += i;
	}
	(*env)->CallStaticVoidMethod(env, m_class, m_mid_static, sum);
	return;
}

/*
 * Class:     cn_hubery_testjni_exams_CounterNative
 * Method:    nativeGetField
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_hubery_testjni_exams_CounterNative_nativeGetField
  (JNIEnv *env, jobject thiz)
{
	int n = 0;//从java层直接读取变量
	int i = 0;
	int sum = 0;//将递归和 计算完成发送回java层
	n = (int)(*env)->GetObjectField(env, m_object, m_fid);
//	for(i = 0; i < n; i++)
//	{
//		sum += i;
//	}
	(*env)->CallVoidMethod(env, m_object, m_mid, n);
	return;
}

