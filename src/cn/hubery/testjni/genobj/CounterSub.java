package cn.hubery.testjni.genobj;

public class CounterSub extends CounterNative5 {

	@Override
	protected int getNum() {
		return 20;
	}
}
