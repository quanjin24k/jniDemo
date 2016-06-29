#include "jni.h"
#include "Adder.h"

/*
 * Class:     cn_hubery_testjni_exams_NativeJniAdder
 * Method:    newObject
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_cn_hubery_testjni_exams_NativeJniAdder_newObject
  (JNIEnv *env, jclass jclazz)
{
	Adder *ar = (Adder *)AdderNew();//创建C对象
	return (jlong)ar;
}

/*
 * Class:     cn_hubery_testjni_exams_NativeJniAdder
 * Method:    excute
 * Signature: (JII)J
 */
JNIEXPORT jlong JNICALL Java_cn_hubery_testjni_exams_NativeJniAdder_excute
  (JNIEnv *env, jclass jclazz, jlong refer, jint digit_1, jint digit_2)
{
	Adder *pa = (Adder *)refer;//转成对象指针
	long result = pa->exec(digit_1, digit_2);
	return result;
}
