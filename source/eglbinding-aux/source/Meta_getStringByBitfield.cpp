
#include <eglbinding-aux/Meta.h>

#include <eglbinding/egl/bitfield.h>

#include "Meta_Maps.h"


using namespace egl;


namespace
{


const auto none = std::string{};


} // namespace


namespace eglbinding { namespace aux
{


const std::string & Meta::getString(const EGLContextFlagMask eglbitfield)
{
    const auto i = Meta_StringsByEGLContextFlagMask.find(eglbitfield);
    if (i != Meta_StringsByEGLContextFlagMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const EGLContextProfileMask eglbitfield)
{
    const auto i = Meta_StringsByEGLContextProfileMask.find(eglbitfield);
    if (i != Meta_StringsByEGLContextProfileMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const EGLDRMBufferUseMESAMask eglbitfield)
{
    const auto i = Meta_StringsByEGLDRMBufferUseMESAMask.find(eglbitfield);
    if (i != Meta_StringsByEGLDRMBufferUseMESAMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const EGLLockUsageHintKHRMask eglbitfield)
{
    const auto i = Meta_StringsByEGLLockUsageHintKHRMask.find(eglbitfield);
    if (i != Meta_StringsByEGLLockUsageHintKHRMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const EGLRenderableTypeMask eglbitfield)
{
    const auto i = Meta_StringsByEGLRenderableTypeMask.find(eglbitfield);
    if (i != Meta_StringsByEGLRenderableTypeMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const EGLSurfaceTypeMask eglbitfield)
{
    const auto i = Meta_StringsByEGLSurfaceTypeMask.find(eglbitfield);
    if (i != Meta_StringsByEGLSurfaceTypeMask.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const EGLSyncFlagsKHR eglbitfield)
{
    const auto i = Meta_StringsByEGLSyncFlagsKHR.find(eglbitfield);
    if (i != Meta_StringsByEGLSyncFlagsKHR.end())
    {
        return i->second;
    }
    return none;
}

const std::string & Meta::getString(const UnusedMask eglbitfield)
{
    const auto i = Meta_StringsByUnusedMask.find(eglbitfield);
    if (i != Meta_StringsByUnusedMask.end())
    {
        return i->second;
    }
    return none;
}


} } // namespace eglbinding::aux