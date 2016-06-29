jniDemo readme.

实现步骤：
1.配置环境：配置jdk，android SDK，NDK环境变量；
2.先写拥有native函数的类，比如：cn/hubery/testjni/ccpp TestHello.java ， 而后eclipse自动会在bin/classes....对应目录下生成TestHello.class文件；
3.通过命令行到jni目录下，通过 javah -classpath ../bin/classes cn.hubery.testjni.ccpp.TestHello 在jni目录下会生成对应头文件；
4.将头文件中的函数签名复制到jni目录下的C/C++文件中，对应实现逻辑；
5.准备好这些，配置android.mk application.mk, 命令行输入ndk-build 回车进行编译；

有疑问可以发我邮件934531487@qq.com
