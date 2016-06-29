package cn.hubery.testjni.exams;

public class NativeJniAdder {

	static{
		System.loadLibrary("NativeJniAdder");
	}
	
	public static native long newObject();
	public static native long excute(long refer, int digit_1, int digit_2);
}
