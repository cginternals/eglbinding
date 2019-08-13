
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLint eglLabelObjectKHR(EGLDisplay display, EGLenum objectType, EGLObjectKHR object, EGLLabelKHR label)
{
    return eglbinding::Binding::LabelObjectKHR(display, objectType, object, label);
}

EGLBoolean eglLockSurfaceKHR(EGLDisplay dpy, EGLSurface surface, const EGLint * attrib_list)
{
    return eglbinding::Binding::LockSurfaceKHR(dpy, surface, attrib_list);
}


} // namespace egl