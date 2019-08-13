
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLint eglDebugMessageControlKHR(EGLDEBUGPROCKHR callback, const EGLAttrib * attrib_list)
{
    return eglbinding::Binding::DebugMessageControlKHR(callback, attrib_list);
}

EGLBoolean eglDestroyContext(EGLDisplay dpy, EGLContext ctx)
{
    return eglbinding::Binding::DestroyContext(dpy, ctx);
}

EGLBoolean eglDestroyImage(EGLDisplay dpy, EGLImage image)
{
    return eglbinding::Binding::DestroyImage(dpy, image);
}

EGLBoolean eglDestroyImageKHR(EGLDisplay dpy, EGLImageKHR image)
{
    return eglbinding::Binding::DestroyImageKHR(dpy, image);
}

EGLBoolean eglDestroyStreamKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    return eglbinding::Binding::DestroyStreamKHR(dpy, stream);
}

EGLBoolean eglDestroySurface(EGLDisplay dpy, EGLSurface surface)
{
    return eglbinding::Binding::DestroySurface(dpy, surface);
}

EGLBoolean eglDestroySync(EGLDisplay dpy, EGLSync sync)
{
    return eglbinding::Binding::DestroySync(dpy, sync);
}

EGLBoolean eglDestroySyncKHR(EGLDisplay dpy, EGLSyncKHR sync)
{
    return eglbinding::Binding::DestroySyncKHR(dpy, sync);
}

EGLBoolean eglDestroySyncNV(EGLSyncNV sync)
{
    return eglbinding::Binding::DestroySyncNV(sync);
}


} // namespace egl