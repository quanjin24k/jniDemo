package cn.hubery.testjni.encode;

public class EncodeDecodePwd {

	static {
		try {
			System.loadLibrary("encode");
		} catch (UnsatisfiedLinkError e) {
			
		}
	}
	
	public String encode(String originalPwd) {
		System.out.println("originalStr::: "+originalPwd);
		String retStr = encodePwd(originalPwd, originalPwd.length());
		System.out.println("encodeResult::: "+retStr);
		return retStr;
	}
	
	public String decode(String originalPwd) {
		String retStr = decodePwd(originalPwd, originalPwd.length());
		System.out.println("decodeResult::: "+retStr);
		return retStr;
	}
	
	public void handleArray(int[] array) {
		transmit(array);
		for(int i = 0; i < array.length; i++){
			System.out.println(array[i]);
		}
	}
	
	public native String encodePwd(String pwd, int length);
	public native String decodePwd(String pwd, int length);
	
	public native void transmit(int[] array);//传递数组
}
