//
// Created by iFinVer on 2016/12/15.
//

#include <cwchar>
#include "facedetector.h"
#include "log.h"
#include "arcsoft/arcsoft.h"

#define LOG_TAG "facedetector"

ArcSoftSpotlight *mXcFaceDetector;

JNIEXPORT jint JNICALL Java_com_ifinver_facedetect_FaceDetector_nativeInit(JNIEnv *env, jclass ,jobject ctx, jstring trackDataPath) {
    if (mXcFaceDetector == NULL) {
        mXcFaceDetector = new ArcSoftSpotlight();
        const char *path = env->GetStringUTFChars(trackDataPath, 0);
        int ret = mXcFaceDetector->init(env, ctx, path);
        env->ReleaseStringUTFChars(trackDataPath, path);
        return ret;
    }
    return 0;
}

JNIEXPORT jlong JNICALL
Java_com_ifinver_facedetect_FaceDetector_nativeProcess(JNIEnv *env, jclass, jbyteArray data_, jint width, jint height) {
    jlong result = 0;
    if (mXcFaceDetector != NULL) {
        jbyte *data = env->GetByteArrayElements(data_, NULL);
        result = mXcFaceDetector->process(data, width, height);
        env->ReleaseByteArrayElements(data_, data, 0);
    }
    return result;
}

JNIEXPORT void JNICALL Java_com_ifinver_facedetect_FaceDetector_nativeRelease(JNIEnv *, jclass ) {
    if (mXcFaceDetector != NULL) {
        delete mXcFaceDetector;
        mXcFaceDetector = NULL;
    }
}

JNIEXPORT void JNICALL Java_com_ifinver_facedetect_FaceDetector_nativeSetProcessModel(JNIEnv *, jclass , jlong model){
    if(mXcFaceDetector != NULL){
        mXcFaceDetector->setProcessModel((long) model);
    }
}
JNIEXPORT void JNICALL Java_com_ifinver_facedetect_FaceDetector_nativeSetFaceBrightLevel(JNIEnv *, jclass , jint brightLevel){
    if(mXcFaceDetector != NULL){
        mXcFaceDetector->setFaceBrightLevel(brightLevel);
    }
}
JNIEXPORT void JNICALL Java_com_ifinver_facedetect_FaceDetector_nativeSetFaceSkinSoftenLevel(JNIEnv *, jclass , jint skinSoftenLevel){
    if(mXcFaceDetector != NULL){
        mXcFaceDetector->setFaceSkinSoftenLevel(skinSoftenLevel);
    }
}