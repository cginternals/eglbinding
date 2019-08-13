
#include <eglbinding-aux/types_to_string.h>

#include <ostream>
#include <bitset>
#include <sstream>

#include <eglbinding/Version.h>
#include <eglbinding-aux/Meta.h>

#include "types_to_string_private.h"


namespace egl
{


std::ostream & operator<<(std::ostream & stream, const EGLBoolean & value)
{
    stream << eglbinding::aux::Meta::getString(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const EGLenum & value)
{
    stream << eglbinding::aux::Meta::getString(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const EGLextension & value)
{
    stream << eglbinding::aux::Meta::getString(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const EGLContextFlagMask & value)
{
    stream << eglbinding::aux::bitfieldString<EGLContextFlagMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const EGLContextProfileMask & value)
{
    stream << eglbinding::aux::bitfieldString<EGLContextProfileMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const EGLDRMBufferUseMESAMask & value)
{
    stream << eglbinding::aux::bitfieldString<EGLDRMBufferUseMESAMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const EGLLockUsageHintKHRMask & value)
{
    stream << eglbinding::aux::bitfieldString<EGLLockUsageHintKHRMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const EGLRenderableTypeMask & value)
{
    stream << eglbinding::aux::bitfieldString<EGLRenderableTypeMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const EGLSurfaceTypeMask & value)
{
    stream << eglbinding::aux::bitfieldString<EGLSurfaceTypeMask>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const EGLSyncFlagsKHR & value)
{
    stream << eglbinding::aux::bitfieldString<EGLSyncFlagsKHR>(value);
    return stream;
}

std::ostream & operator<<(std::ostream & stream, const UnusedMask & value)
{
    stream << eglbinding::aux::bitfieldString<UnusedMask>(value);
    return stream;
}


} // namespace egl


namespace eglbinding
{


template <>
std::ostream & operator<<(std::ostream & stream, const Value<egl::EGLenum> & value)
{
    const auto & name = aux::Meta::getString(value.value());
    stream.write(name.c_str(), static_cast<std::streamsize>(name.size()));

    return stream;
}

/*template <>
std::ostream & operator<<(std::ostream & stream, const Value<egl::EGLbitfield> & value)
{
    std::stringstream ss;
    ss << "0x" << std::hex << static_cast<unsigned>(value.value());
    stream << ss.str();

    return stream;
}*/

template <>
std::ostream & operator<<(std::ostream & stream, const Value<egl::EGLBoolean> & value)
{
    const auto & name = aux::Meta::getString(value.value());
    stream.write(name.c_str(), static_cast<std::streamsize>(name.size()));

    return stream;
}



std::ostream & operator<<(std::ostream & stream, const Version & version)
{
    stream << version.toString();

    return stream;
}

std::ostream & operator<<(std::ostream & stream, const AbstractValue * value)
{
    if (typeid(*value) == typeid(AbstractValue))
    {
        return stream << reinterpret_cast<const void*>(value);
    }

    /*
    if (typeid(*value) == typeid(Value<egl::__eglMustCastToProperFunctionPointerType>))
    {
        return stream << *reinterpret_cast<const Value<egl::__eglMustCastToProperFunctionPointerType>*>(value);
    }
    */
    
    if (typeid(*value) == typeid(Value<egl::__eglMustCastToProperFunctionPointerType *>))
    {
        return stream << *reinterpret_cast<const Value<egl::__eglMustCastToProperFunctionPointerType *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLAttrib>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLAttrib>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLAttrib *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLAttrib *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLAttribKHR>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLAttribKHR>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLAttribKHR *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLAttribKHR *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLbitfield>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLbitfield>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLbitfield *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLbitfield *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLClientBuffer>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLClientBuffer>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLClientBuffer *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLClientBuffer *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLConfig>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLConfig>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLConfig *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLConfig *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLContext>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLContext>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLContext *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLContext *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLContextFlagMask>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLContextFlagMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLContextFlagMask *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLContextFlagMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLContextProfileMask>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLContextProfileMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLContextProfileMask *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLContextProfileMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLDEBUGPROCKHR>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLDEBUGPROCKHR>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLDEBUGPROCKHR *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLDEBUGPROCKHR *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLDeviceEXT>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLDeviceEXT>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLDeviceEXT *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLDeviceEXT *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLDisplay>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLDisplay>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLDisplay *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLDisplay *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLDRMBufferUseMESAMask>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLDRMBufferUseMESAMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLDRMBufferUseMESAMask *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLDRMBufferUseMESAMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLenum>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLenum>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLenum *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLenum *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLextension>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLextension>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLextension *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLextension *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLImage>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLImage>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLImage *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLImage *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLImageKHR>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLImageKHR>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLImageKHR *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLImageKHR *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLint>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLint>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLint *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLint *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLLabelKHR>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLLabelKHR>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLLabelKHR *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLLabelKHR *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLLockUsageHintKHRMask>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLLockUsageHintKHRMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLLockUsageHintKHRMask *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLLockUsageHintKHRMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLNativeDisplayType>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLNativeDisplayType>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLNativeDisplayType *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLNativeDisplayType *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLNativeFileDescriptorKHR>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLNativeFileDescriptorKHR>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLNativeFileDescriptorKHR *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLNativeFileDescriptorKHR *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLNativePixmapType>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLNativePixmapType>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLNativePixmapType *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLNativePixmapType *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLNativeWindowType>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLNativeWindowType>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLNativeWindowType *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLNativeWindowType *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLObjectKHR>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLObjectKHR>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLObjectKHR *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLObjectKHR *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLOutputLayerEXT>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLOutputLayerEXT>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLOutputLayerEXT *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLOutputLayerEXT *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLOutputPortEXT>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLOutputPortEXT>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLOutputPortEXT *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLOutputPortEXT *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLRenderableTypeMask>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLRenderableTypeMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLRenderableTypeMask *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLRenderableTypeMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLStreamKHR>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLStreamKHR>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLStreamKHR *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLStreamKHR *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLSurface>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSurface>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLSurface *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSurface *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLSurfaceTypeMask>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSurfaceTypeMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLSurfaceTypeMask *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSurfaceTypeMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLSync>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSync>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLSync *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSync *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLSyncFlagsKHR>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSyncFlagsKHR>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLSyncFlagsKHR *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSyncFlagsKHR *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLSyncKHR>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSyncKHR>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLSyncKHR *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSyncKHR *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLSyncNV>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSyncNV>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLSyncNV *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSyncNV *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLTime>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLTime>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLTime *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLTime *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLTimeKHR>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLTimeKHR>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLTimeKHR *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLTimeKHR *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLTimeNV>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLTimeNV>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLTimeNV *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLTimeNV *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLuint>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLuint>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLuint *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLuint *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLuint64KHR>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLuint64KHR>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLuint64KHR *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLuint64KHR *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLuint64NV>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLuint64NV>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLuint64NV *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLuint64NV *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::UnusedMask>))
    {
        return stream << *reinterpret_cast<const Value<egl::UnusedMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::UnusedMask *>))
    {
        return stream << *reinterpret_cast<const Value<egl::UnusedMask *>*>(value);
    }

    // expect an AbstractValue with a pointer in first member
    return stream << *reinterpret_cast<const Value<void *>*>(value);
}


} // namespace eglbinding