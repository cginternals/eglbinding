
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLBoolean eglOutputLayerAttribEXT(EGLDisplay dpy, EGLOutputLayerEXT layer, EGLint attribute, EGLAttrib value)
{
    return eglbinding::Binding::OutputLayerAttribEXT(dpy, layer, attribute, value);
}

EGLBoolean eglOutputPortAttribEXT(EGLDisplay dpy, EGLOutputPortEXT port, EGLint attribute, EGLAttrib value)
{
    return eglbinding::Binding::OutputPortAttribEXT(dpy, port, attribute, value);
}


} // namespace egl