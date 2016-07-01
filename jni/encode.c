#include <jni.h>
#include <string.h>

char* Jstring2CStr(JNIEnv* env, jstring jstr)
{
	char* rtn = NULL;
	jclass clsstring = (*env)->FindClass(env, "java/lang/String");
	jstring strencode = (*env)->NewStringUTF(env, "GB2312");
	jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode);//String.getByte("GB2312");
	jsize alen = (*env)->GetArrayLength(env, barr);
	jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);

	if(alen > 0)
	{
		rtn = (char *)malloc(alen + 1);// "\0"
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;// "\0"
	}

	(*env)->ReleaseByteArrayElements(env, barr, ba, 0);

	return rtn;
}

/*
 * Class:     cn_hubery_testjni_encode_EncodeDecodePwd
 * Method:    encodePwd
 * Signature: (Ljava/lang/String;I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cn_hubery_testjni_encode_EncodeDecodePwd_encodePwd
  (JNIEnv *env, jobject thiz, jstring pwd, jint length)
{
	// Java string -->> C string
	char* cstr = Jstring2CStr(env, pwd);

	int i = 0;
	for(i = 0; i < length; i++)
	{
		*(cstr + i) += 1;
	}
	return (*env)->NewStringUTF(env, cstr);
}

/*
 * Class:     cn_hubery_testjni_encode_EncodeDecodePwd
 * Method:    decodePwd
 * Signature: (Ljava/lang/String;I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cn_hubery_testjni_encode_EncodeDecodePwd_decodePwd
  (JNIEnv *env, jobject thiz, jstring pwd, jint length)
{
	//Java String -->> C String
	char* cstr = Jstring2CStr(env, pwd);

	int i = 0;
	for(i = 0; i < length; i++)
	{
		*(cstr + i) -= 1;
	}
	return (*env)->NewStringUTF(env, cstr);
}

/*
 * Class:     cn_hubery_testjni_encode_EncodeDecodePwd
 * Method:    transmit
 * Signature: ([I)V
 */
JNIEXPORT void JNICALL Java_cn_hubery_testjni_encode_EncodeDecodePwd_transmit
  (JNIEnv *env, jobject thiz, jintArray array)
{

	return;
}
