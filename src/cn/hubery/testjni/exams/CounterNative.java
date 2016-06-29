package cn.hubery.testjni.exams;

public class CounterNative {

	private int numb = 10;//供C层直接存取.
	
	static {
		System.loadLibrary("CounterNative");
	}
	
	public CounterNative() {
		numb = 6;
		nativeSetup();
		System.out.println("nativeSetup, numb="+numb);
//		nativeGetField();//阻塞UI
	}
	
	//C层调用
	private static void setValue(int value) {
		String str = "Value(static)="+String.valueOf(value);
		System.out.println(str);
	}
	
	//C层调用
	private void setV(int value) {
		String str = "Value="+String.valueOf(value);
		System.out.println(str);
	}
	
	//如果不知道函数的jni签名，可以写出来 用javah生成以下 就有了；不需要死记硬背了；
//	public native String testNativeMethod(String a, String b);
//	public native String[] testNativeMethod2(String a[], String b);
	
	private native void nativeSetup();
	public native static void nativeExcute(int n);
	public native void nativeExec(int n);
	public native void nativeGetField();
}
