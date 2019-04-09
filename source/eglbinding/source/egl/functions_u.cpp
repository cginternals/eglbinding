
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


using namespace eglbinding;


namespace egl
{


EGLBoolean eglUnlockSurfaceKHR(EGLDisplay dpy, EGLSurface surface)
{
    return Binding::UnlockSurfaceKHR(dpy, surface);
}

EGLBoolean eglUnsignalSyncEXT(EGLDisplay dpy, EGLSync sync, const EGLAttrib * attrib_list)
{
    return Binding::UnsignalSyncEXT(dpy, sync, attrib_list);
}




} // namespace egl
