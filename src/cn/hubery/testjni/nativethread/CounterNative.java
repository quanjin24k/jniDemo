package cn.hubery.testjni.nativethread;

/**
 * 用来测试  C／C++层创建线程 进入Java层进行操作的Test
 * @author hubery
 *
 */
public class CounterNative {
	
	static {
		System.loadLibrary("NativeThread");
	}
	
	public CounterNative() {
		init();
	}
	
	private static void callback(int a) {
		System.out.println("hello.... a="+a);
	}

	private native void init();
	public native void execute(int numb);
}
