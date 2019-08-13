
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLBoolean eglTerminate(EGLDisplay dpy)
{
    return eglbinding::Binding::Terminate(dpy);
}


} // namespace egl