
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLBoolean eglBindAPI(EGLenum api)
{
    return eglbinding::Binding::BindAPI(api);
}

EGLBoolean eglBindTexImage(EGLDisplay dpy, EGLSurface surface, EGLint buffer)
{
    return eglbinding::Binding::BindTexImage(dpy, surface, buffer);
}


} // namespace egl