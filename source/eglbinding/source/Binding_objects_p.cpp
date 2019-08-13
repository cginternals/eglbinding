
#include "Binding_pch.h"


using namespace egl;


namespace eglbinding
{


Function<EGLBoolean, EGLDisplay, EGLSurface, EGLint, EGLint, EGLint, EGLint> Binding::PostSubBufferNV("eglPostSubBufferNV");


} // namespace eglbinding