
#include "../Binding_pch.h"

#include <eglbinding/egl/functions.h>


namespace egl
{


EGLBoolean eglFenceNV(EGLSyncNV sync)
{
    return eglbinding::Binding::FenceNV(sync);
}


} // namespace egl