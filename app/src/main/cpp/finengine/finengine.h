//
// Created by iFinVer on 2016/11/27.
//
//
#include <jni.h>
#include <android/log.h>

#ifndef MYOPENGLES_FINEGINE_H
#define MYOPENGLES_FINEGINE_H
extern "C" {
JNIEXPORT jlong JNICALL
Java_com_ifinver_myopengles_sdk_FinEngine_startEngine(JNIEnv *env, jclass type);
};
#endif //MYOPENGLES_FINEGINE_H
