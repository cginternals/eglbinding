
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLBoolean eglGetConfigAttrib(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint * value)
{
    return eglbinding::Binding::GetConfigAttrib(dpy, config, attribute, value);
}

EGLBoolean eglGetConfigs(EGLDisplay dpy, EGLConfig * configs, EGLint config_size, EGLint * num_config)
{
    return eglbinding::Binding::GetConfigs(dpy, configs, config_size, num_config);
}

EGLContext eglGetCurrentContext()
{
    return eglbinding::Binding::GetCurrentContext();
}

EGLDisplay eglGetCurrentDisplay()
{
    return eglbinding::Binding::GetCurrentDisplay();
}

EGLSurface eglGetCurrentSurface(EGLint readdraw)
{
    return eglbinding::Binding::GetCurrentSurface(readdraw);
}

EGLDisplay eglGetDisplay(EGLNativeDisplayType display_id)
{
    return eglbinding::Binding::GetDisplay(display_id);
}

char * eglGetDisplayDriverConfig(EGLDisplay dpy)
{
    return eglbinding::Binding::GetDisplayDriverConfig(dpy);
}

const char * eglGetDisplayDriverName(EGLDisplay dpy)
{
    return eglbinding::Binding::GetDisplayDriverName(dpy);
}

EGLint eglGetError()
{
    return eglbinding::Binding::GetError();
}

EGLBoolean eglGetOutputLayersEXT(EGLDisplay dpy, const EGLAttrib * attrib_list, EGLOutputLayerEXT * layers, EGLint max_layers, EGLint * num_layers)
{
    return eglbinding::Binding::GetOutputLayersEXT(dpy, attrib_list, layers, max_layers, num_layers);
}

EGLBoolean eglGetOutputPortsEXT(EGLDisplay dpy, const EGLAttrib * attrib_list, EGLOutputPortEXT * ports, EGLint max_ports, EGLint * num_ports)
{
    return eglbinding::Binding::GetOutputPortsEXT(dpy, attrib_list, ports, max_ports, num_ports);
}

EGLDisplay eglGetPlatformDisplay(EGLenum platform, void * native_display, const EGLAttrib * attrib_list)
{
    return eglbinding::Binding::GetPlatformDisplay(platform, native_display, attrib_list);
}

EGLDisplay eglGetPlatformDisplayEXT(EGLenum platform, void * native_display, const EGLint * attrib_list)
{
    return eglbinding::Binding::GetPlatformDisplayEXT(platform, native_display, attrib_list);
}

__eglMustCastToProperFunctionPointerType eglGetProcAddress(const char * procname)
{
    return eglbinding::Binding::GetProcAddress(procname);
}

EGLNativeFileDescriptorKHR eglGetStreamFileDescriptorKHR(EGLDisplay dpy, EGLStreamKHR stream)
{
    return eglbinding::Binding::GetStreamFileDescriptorKHR(dpy, stream);
}

EGLBoolean eglGetSyncAttrib(EGLDisplay dpy, EGLSync sync, EGLint attribute, EGLAttrib * value)
{
    return eglbinding::Binding::GetSyncAttrib(dpy, sync, attribute, value);
}

EGLBoolean eglGetSyncAttribKHR(EGLDisplay dpy, EGLSyncKHR sync, EGLint attribute, EGLint * value)
{
    return eglbinding::Binding::GetSyncAttribKHR(dpy, sync, attribute, value);
}

EGLBoolean eglGetSyncAttribNV(EGLSyncNV sync, EGLint attribute, EGLint * value)
{
    return eglbinding::Binding::GetSyncAttribNV(sync, attribute, value);
}

EGLuint64NV eglGetSystemTimeFrequencyNV()
{
    return eglbinding::Binding::GetSystemTimeFrequencyNV();
}

EGLuint64NV eglGetSystemTimeNV()
{
    return eglbinding::Binding::GetSystemTimeNV();
}


} // namespace egl