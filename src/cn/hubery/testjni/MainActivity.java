package cn.hubery.testjni;

import cn.hubery.testjni.ccpp.TestHello;
import cn.hubery.testjni.encode.EncodeDecodePwd;
import cn.hubery.testjni.exams.CounterNative;
import cn.hubery.testjni.exams.HelloNDK;
import cn.hubery.testjni.exams.NativeGetFieldFromJava;
import cn.hubery.testjni.exams.NativeJniAdder;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;


public class MainActivity extends Activity implements OnClickListener {

	public static final String TAG = "MainActivity";
	
	private TextView tv_result;
	private EditText et_pwd;
	private TextView show_result_2;
	
	private CounterNative cn;
	private EncodeDecodePwd encodePwd;
	private String encodeStr;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        tv_result = (TextView) findViewById(R.id.tv_result);
        show_result_2 = (TextView) findViewById(R.id.show_result_2);
        et_pwd = (EditText) findViewById(R.id.et_pwd);
        findViewById(R.id.btn_101).setOnClickListener(this);
        findViewById(R.id.btn_102).setOnClickListener(this);
        findViewById(R.id.btn_103).setOnClickListener(this);
        findViewById(R.id.btn_104).setOnClickListener(this);
        findViewById(R.id.btn_105).setOnClickListener(this);
        findViewById(R.id.btn_106).setOnClickListener(this);
        findViewById(R.id.btn_107).setOnClickListener(this);
        
        cn = new CounterNative();
        encodePwd = new EncodeDecodePwd();
        
        int a = 11;
        int b = 10;
        long refer = NativeJniAdder.newObject();
        int cs = (int)NativeJniAdder.excute(refer, a, b);
        int sum = cs % 10;
        int carry = cs / 10;
        String carry_sum_str = String.valueOf(carry) + String.valueOf(sum);
        
        tv_result.setText("stringFromJNI:"+new TestHello().stringFromJNI()+"\n"
        				+"\r"+new TestHello().add(5, 7)+"\n"
        				+"\r"+new HelloNDK().sayHello()+"\n"
        				+"\r"+carry_sum_str);
    }

	@Override
	public void onClick(View v) {
		switch (v.getId()) {
		case R.id.btn_101:
			cn.nativeExec(10);
			break;
		case R.id.btn_102:
			CounterNative.nativeExcute(11);
			break;
		case R.id.btn_103:
//			finish();
//			cn.nativeGetField();
			break;
		case R.id.btn_104:
//			new NativeGetFieldFromJava().nativeBusiness();//有问题
			break;
		case R.id.btn_105:
			
			break;
		case R.id.btn_106://encode
			String originalStr = et_pwd.getText().toString();
			if (!TextUtils.isEmpty(originalStr)) {
				encodeStr = encodePwd.encode(originalStr);	
				show_result_2.setText("加密后:"+encodeStr);
			} else {
				Toast.makeText(this, "待加密的String不能为空", Toast.LENGTH_SHORT).show();
			}
			break;
		case R.id.btn_107://decode
			if (!TextUtils.isEmpty(encodeStr)) {
				String retStr = encodePwd.decode(encodeStr);	
				show_result_2.setText("解密后:"+retStr);
			} else {
				Toast.makeText(this, "待解码的String不能为空", Toast.LENGTH_SHORT).show();
			}
			
			break;
		default:
			break;
		}
	}

}
