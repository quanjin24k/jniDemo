package cn.hubery.testjni.exams;

public class HelloNDK {

	static {
		System.loadLibrary("HelloNDK");
	}
	
	public native String sayHello();
}
