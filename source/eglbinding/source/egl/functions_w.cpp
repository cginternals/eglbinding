
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLBoolean eglWaitClient()
{
    return eglbinding::Binding::WaitClient();
}

EGLBoolean eglWaitGL()
{
    return eglbinding::Binding::WaitGL();
}

EGLBoolean eglWaitNative(EGLint engine)
{
    return eglbinding::Binding::WaitNative(engine);
}

EGLBoolean eglWaitSync(EGLDisplay dpy, EGLSync sync, EGLint flags)
{
    return eglbinding::Binding::WaitSync(dpy, sync, flags);
}

EGLint eglWaitSyncKHR(EGLDisplay dpy, EGLSyncKHR sync, EGLint flags)
{
    return eglbinding::Binding::WaitSyncKHR(dpy, sync, flags);
}


} // namespace egl