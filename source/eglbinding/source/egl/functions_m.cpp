
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLBoolean eglMakeCurrent(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx)
{
    return eglbinding::Binding::MakeCurrent(dpy, draw, read, ctx);
}


} // namespace egl