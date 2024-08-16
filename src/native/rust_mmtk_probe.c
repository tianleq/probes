#include <jni.h>
#include <stdio.h>
#include <dlfcn.h>

/* JNI Functions */

JNIEXPORT void JNICALL Java_probe_RustMMTkProbe_begin_1native(JNIEnv *env, jobject o, jstring benchmark, jint iteration, jboolean warmup, jlong thread_id)
{
  void *handle = dlopen(NULL, RTLD_LAZY);
  void (*harness_begin)(jlong) = dlsym(handle, "harness_begin");
  (*harness_begin)(thread_id);
}

JNIEXPORT void JNICALL Java_probe_RustMMTkProbe_end_1native(JNIEnv *env, jobject o, jstring benchmark, jint iteration, jboolean warmup, jlong thread_id)
{
  void *handle = dlopen(NULL, RTLD_LAZY);
  void (*harness_end)(jlong) = dlsym(handle, "harness_end");
  (*harness_end)(thread_id);
}

JNIEXPORT void JNICALL Java_probe_RustMMTk32Probe_begin_1native(JNIEnv *env, jobject o, jstring benchmark, jint iteration, jboolean warmup, jlong thread_id)
{
  void *handle = dlopen(NULL, RTLD_LAZY);
  void (*harness_begin)(jlong) = dlsym(handle, "harness_begin");
  (*harness_begin)(thread_id);
}

JNIEXPORT void JNICALL Java_probe_RustMMTk32Probe_end_1native(JNIEnv *env, jobject o, jstring benchmark, jint iteration, jboolean warmup, jlong thread_id)
{
  void *handle = dlopen(NULL, RTLD_LAZY);
  void (*harness_end)(jlong) = dlsym(handle, "harness_end");
  (*harness_end)(thread_id);
}

/*
 * Class:     probe_DacapoChopinCallback
 * Method:    request_start_native
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_probe_DacapoChopinCallback_request_1start_1native(JNIEnv *env, jobject o)
{
  void *handle = dlopen(NULL, RTLD_LAZY);
  void (*start)(JNIEnv *env) = dlsym(handle, "mmtk_request_start");
  start(env);
}

/*
 * Class:     probe_DacapoChopinCallback
 * Method:    request_finish_native
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_probe_DacapoChopinCallback_request_1finish_1native(JNIEnv *env, jobject o)
{
  void *handle = dlopen(NULL, RTLD_LAZY);
  void (*finish)(JNIEnv *env) = dlsym(handle, "mmtk_request_end");
  finish(env);
}

/*
 * Class:     DacapoChopinCallback
 * Method:    requests_starting_native
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_probe_DacapoChopinCallback_requests_1starting_1native(JNIEnv *env, jobject o)
{
  void *handle = dlopen(NULL, RTLD_LAZY);
  void (*request_starting)() = dlsym(handle, "requests_starting");
  if (request_starting != NULL)
  {
    (*request_starting)();
    return;
  }
  request_starting = dlsym(handle, "mmtk_request_starting");
  if (request_starting != NULL)
  {
    (*request_starting)(env);
    return;
  }
}

/*
 * Class:     DacapoChopinCallback
 * Method:    requests_finished_native
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_probe_DacapoChopinCallback_requests_1finished_1native(JNIEnv *env, jobject o)
{
  void *handle = dlopen(NULL, RTLD_LAZY);
  void (*requests_finished)() = dlsym(handle, "requests_finished");
  if (requests_finished != NULL)
  {
    (*requests_finished)();
    return;
  }
  requests_finished = dlsym(handle, "mmtk_request_finished");
  if (requests_finished != NULL)
  {
    (*requests_finished)(env);
    return;
  }
}