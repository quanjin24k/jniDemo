package cn.hubery.testjni.ccpp;

public class TestHello {

	static {
		System.loadLibrary("testc");
	}
	
	public native String stringFromJNI();
	public native int add(int x, int y);
}
