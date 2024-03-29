
#include "Binding_pch.h"


using namespace egl;


namespace eglbinding
{


Function<EGLBoolean, EGLDisplay, EGLSurface, EGLint *, EGLint> Binding::SetDamageRegionKHR("eglSetDamageRegionKHR");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR, EGLenum, EGLAttrib> Binding::SetStreamAttribKHR("eglSetStreamAttribKHR");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR, EGLint, EGLint, EGLint, const void *> Binding::SetStreamMetadataNV("eglSetStreamMetadataNV");
Function<EGLBoolean, EGLDisplay, EGLSyncKHR, EGLenum> Binding::SignalSyncKHR("eglSignalSyncKHR");
Function<EGLBoolean, EGLSyncNV, EGLenum> Binding::SignalSyncNV("eglSignalSyncNV");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR, EGLImage *, EGLSync> Binding::StreamAcquireImageNV("eglStreamAcquireImageNV");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR, EGLenum, EGLint> Binding::StreamAttribKHR("eglStreamAttribKHR");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR, const EGLAttrib *> Binding::StreamConsumerAcquireAttribKHR("eglStreamConsumerAcquireAttribKHR");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR> Binding::StreamConsumerAcquireKHR("eglStreamConsumerAcquireKHR");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR, const EGLAttrib *> Binding::StreamConsumerGLTextureExternalAttribsNV("eglStreamConsumerGLTextureExternalAttribsNV");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR> Binding::StreamConsumerGLTextureExternalKHR("eglStreamConsumerGLTextureExternalKHR");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR, EGLOutputLayerEXT> Binding::StreamConsumerOutputEXT("eglStreamConsumerOutputEXT");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR, const EGLAttrib *> Binding::StreamConsumerReleaseAttribKHR("eglStreamConsumerReleaseAttribKHR");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR> Binding::StreamConsumerReleaseKHR("eglStreamConsumerReleaseKHR");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR> Binding::StreamFlushNV("eglStreamFlushNV");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR, EGLint, const EGLuint64KHR *, const EGLAttrib *> Binding::StreamImageConsumerConnectNV("eglStreamImageConsumerConnectNV");
Function<EGLBoolean, EGLDisplay, EGLStreamKHR, EGLImage, EGLSync> Binding::StreamReleaseImageNV("eglStreamReleaseImageNV");
Function<EGLBoolean, EGLDisplay, EGLSurface, EGLint, EGLint> Binding::SurfaceAttrib("eglSurfaceAttrib");
Function<EGLBoolean, EGLDisplay, EGLSurface> Binding::SwapBuffers("eglSwapBuffers");
Function<EGLBoolean, EGLDisplay, EGLSurface, EGLint, const EGLint *> Binding::SwapBuffersRegion2NOK("eglSwapBuffersRegion2NOK");
Function<EGLBoolean, EGLDisplay, EGLSurface, EGLint, const EGLint *> Binding::SwapBuffersRegionNOK("eglSwapBuffersRegionNOK");
Function<EGLBoolean, EGLDisplay, EGLSurface, const EGLint *, EGLint> Binding::SwapBuffersWithDamageEXT("eglSwapBuffersWithDamageEXT");
Function<EGLBoolean, EGLDisplay, EGLSurface, const EGLint *, EGLint> Binding::SwapBuffersWithDamageKHR("eglSwapBuffersWithDamageKHR");
Function<EGLBoolean, EGLDisplay, EGLint> Binding::SwapInterval("eglSwapInterval");


} // namespace eglbinding