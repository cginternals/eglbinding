
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLBoolean eglInitialize(EGLDisplay dpy, EGLint * major, EGLint * minor)
{
    return eglbinding::Binding::Initialize(dpy, major, minor);
}


} // namespace egl