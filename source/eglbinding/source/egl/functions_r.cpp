
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLBoolean eglReleaseTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    return eglbinding::Binding::ReleaseTexImage(dpy, surface, buffer);
}

EGLBoolean eglReleaseThread()
{
    return eglbinding::Binding::ReleaseThread();
}

EGLBoolean eglResetStreamNV(EGLDisplay dpy, EGLStreamKHR stream)
{
    return eglbinding::Binding::ResetStreamNV(dpy, stream);
}


} // namespace egl