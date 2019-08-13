
#pragma once


#include <cstddef>
#include <cstdint>
#include <array>
#include <string>

#include <KHR/khrplatform.h>
#include <EGL/eglplatform.h>

#ifdef _MSC_VER
#define EGL_APIENTRY __stdcall
#else
#define EGL_APIENTRY
#endif

#include <eglbinding/noegl.h>
#include <eglbinding/eglbinding_api.h>
#include <eglbinding/eglbinding_features.h>
#include <eglbinding/egl/boolean.h>


namespace egl
{

using EGLbitfield = unsigned int;

enum class EGLextension : int;
enum class EGLenum : unsigned int;
using ::EGLNativeDisplayType;
using ::EGLNativePixmapType;
using ::EGLNativeWindowType;
using ::EGLint;
using EGLAttribKHR = intptr_t;
using EGLAttrib = intptr_t;
using EGLClientBuffer = void *;
using EGLConfig = void *;
using EGLContext = void *;
using EGLDeviceEXT = void *;
using EGLDisplay = void *;
using EGLImage = void *;
using EGLImageKHR = void *;
using EGLLabelKHR = void *;
using EGLObjectKHR = void *;
using EGLOutputLayerEXT = void *;
using EGLOutputPortEXT = void *;
using EGLStreamKHR = void *;
using EGLSurface = void *;
using EGLSync = void *;
using EGLSyncKHR = void *;
using EGLSyncNV = void *;
using __eglMustCastToProperFunctionPointerType = void (*)(void);
using EGLTimeKHR = khronos_utime_nanoseconds_t;
using EGLTime = khronos_utime_nanoseconds_t;
using EGLTimeNV = khronos_utime_nanoseconds_t;
using EGLuint64NV = khronos_utime_nanoseconds_t;
using EGLuint64KHR = khronos_uint64_t;
using EGLNativeFileDescriptorKHR = int;
struct EGLClientPixmapHI {
    void  *pData;
    EGLint iWidth;
    EGLint iHeight;
    EGLint iStride;
};
using EGLDEBUGPROCKHR = void (EGL_APIENTRY *)(EGLenum error,const char *command,EGLint messageType,EGLLabelKHR threadLabel,EGLLabelKHR objectLabel,const char* message);
enum class UnusedMask : unsigned int;

} // namespace egl


#include <eglbinding/egl/types.inl>