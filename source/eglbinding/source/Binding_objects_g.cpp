
#include "Binding_pch.h"


using namespace egl;


namespace eglbinding
{


Function<EGLBoolean, EGLDisplay, EGLConfig, EGLint, EGLint *> Binding::GetConfigAttrib("eglGetConfigAttrib");
Function<EGLBoolean, EGLDisplay, EGLConfig *, EGLint, EGLint *> Binding::GetConfigs("eglGetConfigs");
Function<EGLContext> Binding::GetCurrentContext("eglGetCurrentContext");
Function<EGLDisplay> Binding::GetCurrentDisplay("eglGetCurrentDisplay");
Function<EGLSurface, EGLint> Binding::GetCurrentSurface("eglGetCurrentSurface");
Function<EGLDisplay, EGLNativeDisplayType> Binding::GetDisplay("eglGetDisplay");
Function<char *, EGLDisplay> Binding::GetDisplayDriverConfig("eglGetDisplayDriverConfig");
Function<const char *, EGLDisplay> Binding::GetDisplayDriverName("eglGetDisplayDriverName");
Function<EGLint> Binding::GetError("eglGetError");
Function<EGLBoolean, EGLDisplay, EGLSurface, EGLint *, EGLint *> Binding::GetMscRateANGLE("eglGetMscRateANGLE");
Function<EGLBoolean, EGLDisplay, const EGLAttrib *, EGLOutputLayerEXT *, EGLint, EGLint *> Binding::GetOutputLayersEXT("eglGetOutputLayersEXT");
Function<EGLBoolean, EGLDisplay, const EGLAttrib *, EGLOutputPortEXT *, EGLint, EGLint *> Binding::GetOutputPortsEXT("eglGetOutputPortsEXT");
Function<EGLDisplay, EGLenum, void *, const EGLAttrib *> Binding::GetPlatformDisplay("eglGetPlatformDisplay");
Function<EGLDisplay, EGLenum, void *, const EGLint *> Binding::GetPlatformDisplayEXT("eglGetPlatformDisplayEXT");
Function<__eglMustCastToProperFunctionPointerType, const char *> Binding::GetProcAddress("eglGetProcAddress");
Function<EGLNativeFileDescriptorKHR, EGLDisplay, EGLStreamKHR> Binding::GetStreamFileDescriptorKHR("eglGetStreamFileDescriptorKHR");
Function<EGLBoolean, EGLDisplay, EGLSync, EGLint, EGLAttrib *> Binding::GetSyncAttrib("eglGetSyncAttrib");
Function<EGLBoolean, EGLDisplay, EGLSyncKHR, EGLint, EGLint *> Binding::GetSyncAttribKHR("eglGetSyncAttribKHR");
Function<EGLBoolean, EGLSyncNV, EGLint, EGLint *> Binding::GetSyncAttribNV("eglGetSyncAttribNV");
Function<EGLuint64NV> Binding::GetSystemTimeFrequencyNV("eglGetSystemTimeFrequencyNV");
Function<EGLuint64NV> Binding::GetSystemTimeNV("eglGetSystemTimeNV");


} // namespace eglbinding