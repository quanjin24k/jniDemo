package cn.hubery.testjni.exams;

public class NativeGetFieldFromJava {

	static {
		System.loadLibrary("NativeGetFieldFromJava");
	}
	
	private int numberInJava;
	
	public NativeGetFieldFromJava() {
		numberInJava = 100;
		nativeSetup();
	}
	
	private void showMessage(int value) {
		System.out.println("value="+value+" is from C.");
	}
	
	private native void nativeSetup();
	public native void nativeBusiness();
}
