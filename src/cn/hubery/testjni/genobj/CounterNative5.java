package cn.hubery.testjni.genobj;

public abstract class CounterNative5 {

	private int number;
	
	static{
		System.loadLibrary("CounterNative5");
	}
	
	public CounterNative5() {
		number = getNum();
		nativeSetup();
	}
	
//	public void setV(int value) {
//		System.out.println("setV:: value="+value);
//	}
	
	protected abstract int getNum();
	private native void nativeSetup();
	public native void nativeExec(int number);
}
