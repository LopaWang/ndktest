#include <jni.h>
#include <string>


extern "C" { // 由于库，是c编写的，所有采用c的编译方式
extern int add(int ,int); //
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_wzj_ndktest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_wzj_ndktest_MainActivity_add(JNIEnv *env, jobject thiz, jint a, jint b) {
    // TODO: implement add()
    return add(a,b);
}