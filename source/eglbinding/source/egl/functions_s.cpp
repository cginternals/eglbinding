
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLBoolean eglSetDamageRegionKHR(EGLDisplay dpy, EGLSurface surface, EGLint * rects, EGLint n_rects)
{
    return eglbinding::Binding::SetDamageRegionKHR(dpy, surface, rects, n_rects);
}

EGLBoolean eglSetStreamAttribKHR(EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLAttrib value)
{
    return eglbinding::Binding::SetStreamAttribKHR(dpy, stream, attribute, value);
}

EGLBoolean eglSetStreamMetadataNV(EGLDisplay dpy, EGLStreamKHR stream, EGLint n, EGLint offset, EGLint size, const void * data)
{
    return eglbinding::Binding::SetStreamMetadataNV(dpy, stream, n, offset, size, data);
}

EGLBoolean eglSignalSyncKHR(EGLDisplay dpy, EGLSyncKHR sync, EGLenum mode)
{
    return eglbinding::Binding::SignalSyncKHR(dpy, sync, mode);
}

EGLBoolean eglSignalSyncNV(EGLSyncNV sync, EGLenum mode)
{
    return eglbinding::Binding::SignalSyncNV(sync, mode);
}

EGLBoolean eglStreamAttribKHR(EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLint value)
{
    return eglbinding::Binding::StreamAttribKHR(dpy, stream, attribute, value);
}

EGLBoolean eglStreamConsumerAcquireAttribKHR(EGLDisplay dpy, EGLStreamKHR stream, const EGLAttrib * attrib_list)
{
    return eglbinding::Binding::StreamConsumerAcquireAttribKHR(dpy, stream, attrib_list);
}

EGLBoolean eglStreamConsumerAcquireKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    return eglbinding::Binding::StreamConsumerAcquireKHR(dpy, stream);
}

EGLBoolean eglStreamConsumerGLTextureExternalAttribsNV(EGLDisplay dpy, EGLStreamKHR stream, const EGLAttrib * attrib_list)
{
    return eglbinding::Binding::StreamConsumerGLTextureExternalAttribsNV(dpy, stream, attrib_list);
}

EGLBoolean eglStreamConsumerGLTextureExternalKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    return eglbinding::Binding::StreamConsumerGLTextureExternalKHR(dpy, stream);
}

EGLBoolean eglStreamConsumerOutputEXT(EGLDisplay dpy, EGLStreamKHR stream, EGLOutputLayerEXT layer)
{
    return eglbinding::Binding::StreamConsumerOutputEXT(dpy, stream, layer);
}

EGLBoolean eglStreamConsumerReleaseAttribKHR(EGLDisplay dpy, EGLStreamKHR stream, const EGLAttrib * attrib_list)
{
    return eglbinding::Binding::StreamConsumerReleaseAttribKHR(dpy, stream, attrib_list);
}

EGLBoolean eglStreamConsumerReleaseKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    return eglbinding::Binding::StreamConsumerReleaseKHR(dpy, stream);
}

EGLBoolean eglStreamFlushNV(EGLDisplay dpy, EGLStreamKHR stream)
{
    return eglbinding::Binding::StreamFlushNV(dpy, stream);
}

EGLBoolean eglSurfaceAttrib(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value)
{
    return eglbinding::Binding::SurfaceAttrib(dpy, surface, attribute, value);
}

EGLBoolean eglSwapBuffers(EGLDisplay dpy, EGLSurface surface)
{
    return eglbinding::Binding::SwapBuffers(dpy, surface);
}

EGLBoolean eglSwapBuffersRegion2NOK(EGLDisplay dpy, EGLSurface surface, EGLint numRects, const EGLint * rects)
{
    return eglbinding::Binding::SwapBuffersRegion2NOK(dpy, surface, numRects, rects);
}

EGLBoolean eglSwapBuffersRegionNOK(EGLDisplay dpy, EGLSurface surface, EGLint numRects, const EGLint * rects)
{
    return eglbinding::Binding::SwapBuffersRegionNOK(dpy, surface, numRects, rects);
}

EGLBoolean eglSwapBuffersWithDamageEXT(EGLDisplay dpy, EGLSurface surface, const EGLint * rects, EGLint n_rects)
{
    return eglbinding::Binding::SwapBuffersWithDamageEXT(dpy, surface, rects, n_rects);
}

EGLBoolean eglSwapBuffersWithDamageKHR(EGLDisplay dpy, EGLSurface surface, const EGLint * rects, EGLint n_rects)
{
    return eglbinding::Binding::SwapBuffersWithDamageKHR(dpy, surface, rects, n_rects);
}

EGLBoolean eglSwapInterval(EGLDisplay dpy, EGLint interval)
{
    return eglbinding::Binding::SwapInterval(dpy, interval);
}


} // namespace egl