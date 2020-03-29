
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLenum eglQueryAPI()
{
    return eglbinding::Binding::QueryAPI();
}

EGLBoolean eglQueryContext(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint * value)
{
    return eglbinding::Binding::QueryContext(dpy, ctx, attribute, value);
}

EGLBoolean eglQueryDebugKHR(EGLint attribute, EGLAttrib * value)
{
    return eglbinding::Binding::QueryDebugKHR(attribute, value);
}

EGLBoolean eglQueryDeviceAttribEXT(EGLDeviceEXT device, EGLint attribute, EGLAttrib * value)
{
    return eglbinding::Binding::QueryDeviceAttribEXT(device, attribute, value);
}

EGLBoolean eglQueryDevicesEXT(EGLint max_devices, EGLDeviceEXT * devices, EGLint * num_devices)
{
    return eglbinding::Binding::QueryDevicesEXT(max_devices, devices, num_devices);
}

const char * eglQueryDeviceStringEXT(EGLDeviceEXT device, EGLint name)
{
    return eglbinding::Binding::QueryDeviceStringEXT(device, name);
}

EGLBoolean eglQueryDisplayAttribEXT(EGLDisplay dpy, EGLint attribute, EGLAttrib * value)
{
    return eglbinding::Binding::QueryDisplayAttribEXT(dpy, attribute, value);
}

EGLBoolean eglQueryDisplayAttribKHR(EGLDisplay dpy, EGLint name, EGLAttrib * value)
{
    return eglbinding::Binding::QueryDisplayAttribKHR(dpy, name, value);
}

EGLBoolean eglQueryDisplayAttribNV(EGLDisplay dpy, EGLint attribute, EGLAttrib * value)
{
    return eglbinding::Binding::QueryDisplayAttribNV(dpy, attribute, value);
}

EGLBoolean eglQueryDmaBufFormatsEXT(EGLDisplay dpy, EGLint max_formats, EGLint * formats, EGLint * num_formats)
{
    return eglbinding::Binding::QueryDmaBufFormatsEXT(dpy, max_formats, formats, num_formats);
}

EGLBoolean eglQueryDmaBufModifiersEXT(EGLDisplay dpy, EGLint format, EGLint max_modifiers, EGLuint64KHR * modifiers, EGLBoolean * external_only, EGLint * num_modifiers)
{
    return eglbinding::Binding::QueryDmaBufModifiersEXT(dpy, format, max_modifiers, modifiers, external_only, num_modifiers);
}

EGLBoolean eglQueryNativeDisplayNV(EGLDisplay dpy, EGLNativeDisplayType * display_id)
{
    return eglbinding::Binding::QueryNativeDisplayNV(dpy, display_id);
}

EGLBoolean eglQueryNativePixmapNV(EGLDisplay dpy, EGLSurface surf, EGLNativePixmapType * pixmap)
{
    return eglbinding::Binding::QueryNativePixmapNV(dpy, surf, pixmap);
}

EGLBoolean eglQueryNativeWindowNV(EGLDisplay dpy, EGLSurface surf, EGLNativeWindowType * window)
{
    return eglbinding::Binding::QueryNativeWindowNV(dpy, surf, window);
}

EGLBoolean eglQueryOutputLayerAttribEXT(EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint attribute, EGLAttrib * value)
{
    return eglbinding::Binding::QueryOutputLayerAttribEXT(dpy, layer, attribute, value);
}

const char * eglQueryOutputLayerStringEXT(EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint name)
{
    return eglbinding::Binding::QueryOutputLayerStringEXT(dpy, layer, name);
}

EGLBoolean eglQueryOutputPortAttribEXT(EGLDisplay dpy, EGLOutputPortEXT port, EGLint attribute, EGLAttrib * value)
{
    return eglbinding::Binding::QueryOutputPortAttribEXT(dpy, port, attribute, value);
}

const char * eglQueryOutputPortStringEXT(EGLDisplay dpy, EGLOutputPortEXT port, EGLint name)
{
    return eglbinding::Binding::QueryOutputPortStringEXT(dpy, port, name);
}

EGLBoolean eglQueryStreamAttribKHR(EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLAttrib * value)
{
    return eglbinding::Binding::QueryStreamAttribKHR(dpy, stream, attribute, value);
}

EGLBoolean eglQueryStreamKHR(EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLint * value)
{
    return eglbinding::Binding::QueryStreamKHR(dpy, stream, attribute, value);
}

EGLBoolean eglQueryStreamMetadataNV(EGLDisplay dpy, EGLStreamKHR stream, EGLenum name, EGLint n, EGLint offset, EGLint size, void * data)
{
    return eglbinding::Binding::QueryStreamMetadataNV(dpy, stream, name, n, offset, size, data);
}

EGLBoolean eglQueryStreamTimeKHR(EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLTimeKHR * value)
{
    return eglbinding::Binding::QueryStreamTimeKHR(dpy, stream, attribute, value);
}

EGLBoolean eglQueryStreamu64KHR(EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLuint64KHR * value)
{
    return eglbinding::Binding::QueryStreamu64KHR(dpy, stream, attribute, value);
}

const char * eglQueryString(EGLDisplay dpy, EGLint name)
{
    return eglbinding::Binding::QueryString(dpy, name);
}

EGLBoolean eglQuerySurface(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint * value)
{
    return eglbinding::Binding::QuerySurface(dpy, surface, attribute, value);
}

EGLBoolean eglQuerySurface64KHR(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLAttribKHR * value)
{
    return eglbinding::Binding::QuerySurface64KHR(dpy, surface, attribute, value);
}

EGLBoolean eglQuerySurfacePointerANGLE(EGLDisplay dpy, EGLSurface surface, EGLint attribute, void ** value)
{
    return eglbinding::Binding::QuerySurfacePointerANGLE(dpy, surface, attribute, value);
}

EGLBoolean eglQueryWaylandBufferWL(EGLDisplay dpy, wl_resource * buffer, EGLint attribute, EGLint * value)
{
    return eglbinding::Binding::QueryWaylandBufferWL(dpy, buffer, attribute, value);
}


} // namespace egl