
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLBoolean eglUnbindWaylandDisplayWL(EGLDisplay dpy, wl_display * display)
{
    return eglbinding::Binding::UnbindWaylandDisplayWL(dpy, display);
}

EGLBoolean eglUnlockSurfaceKHR(EGLDisplay dpy, EGLSurface surface)
{
    return eglbinding::Binding::UnlockSurfaceKHR(dpy, surface);
}

EGLBoolean eglUnsignalSyncEXT(EGLDisplay dpy, EGLSync sync, const EGLAttrib * attrib_list)
{
    return eglbinding::Binding::UnsignalSyncEXT(dpy, sync, attrib_list);
}


} // namespace egl