#include "jni.h"
/*
 * Class:     cn_hubery_testjni_exams_HelloNDK
 * Method:    sayHello
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cn_hubery_testjni_exams_HelloNDK_sayHello
  (JNIEnv *env, jobject thiz)
{

	return (* env)->NewStringUTF(env, "hello NDK...");
}
