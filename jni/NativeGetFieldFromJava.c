#include <jni.h>
#include <android/log.h>
#include <stdio.h>

jclass mClass;
jobject mObject;
jmethodID mMethodID;
jfieldID mFieldID;

/*
 * Class:     cn_hubery_testjni_exams_NativeGetFieldFromJava
 * Method:    nativeSetup
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_hubery_testjni_exams_NativeGetFieldFromJava_nativeSetup
  (JNIEnv *env, jobject thiz)
{
	jclass clazz = (*env)->GetObjectClass(env, thiz);
	mClass = (jclass)(*env)->NewGlobalRef(env, clazz);
	mObject = (jobject)(*env)->NewGlobalRef(env, thiz);
	mMethodID = (*env)->GetMethodID(env, mClass, "showMessage", "(I)V");
	mFieldID = (*env)->GetFieldID(env, mClass, "numberInJava", "I");
}

/*
 * Class:     cn_hubery_testjni_exams_NativeGetFieldFromJava
 * Method:    nativeBusiness
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_hubery_testjni_exams_NativeGetFieldFromJava_nativeBusiness
  (JNIEnv *env, jobject thiz)
{
	int numberInC = 10;
	int sum = 0;
	numberInC = (*env)->GetObjectField(env, mObject, mFieldID);

	sum = numberInC * 3;
	(*env)->CallVoidMethod(env, mObject, mMethodID, sum);
	return;
}
