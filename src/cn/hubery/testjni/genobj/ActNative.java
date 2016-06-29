package cn.hubery.testjni.genobj;

public class ActNative {

	static {
		System.loadLibrary("ActNative");
	}
	
	public static native Object nativeExec();
}
