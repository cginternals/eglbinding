
#include "Binding_pch.h"


using namespace egl;


namespace eglbinding
{


Function<EGLBoolean, EGLDisplay, wl_display *> Binding::UnbindWaylandDisplayWL("eglUnbindWaylandDisplayWL");
Function<EGLBoolean, EGLDisplay, EGLSurface> Binding::UnlockSurfaceKHR("eglUnlockSurfaceKHR");
Function<EGLBoolean, EGLDisplay, EGLSync, const EGLAttrib *> Binding::UnsignalSyncEXT("eglUnsignalSyncEXT");


} // namespace eglbinding