
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

template <>
std::ostream & operator<<(std::ostream & stream, const Value<const char *> & value)
{
    auto s = aux::wrapString(value.value());
    stream.write(s.c_str(), static_cast<std::streamsize>(s.size()));

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

    if (typeid(*value) == typeid(Value<char>))
    {
        return stream << *reinterpret_cast<const Value<char>*>(value);
    }

    if (typeid(*value) == typeid(Value<double>))
    {
        return stream << *reinterpret_cast<const Value<double>*>(value);
    }

    if (typeid(*value) == typeid(Value<float>))
    {
        return stream << *reinterpret_cast<const Value<float>*>(value);
    }

    if (typeid(*value) == typeid(Value<int>))
    {
        return stream << *reinterpret_cast<const Value<int>*>(value);
    }

    if (typeid(*value) == typeid(Value<long>))
    {
        return stream << *reinterpret_cast<const Value<long>*>(value);
    }

    if (typeid(*value) == typeid(Value<long long>))
    {
        return stream << *reinterpret_cast<const Value<long long>*>(value);
    }

    if (typeid(*value) == typeid(Value<unsigned char>))
    {
        return stream << *reinterpret_cast<const Value<unsigned char>*>(value);
    }

    if (typeid(*value) == typeid(Value<unsigned int>))
    {
        return stream << *reinterpret_cast<const Value<unsigned int>*>(value);
    }

    if (typeid(*value) == typeid(Value<unsigned long>))
    {
        return stream << *reinterpret_cast<const Value<unsigned long>*>(value);
    }

    if (typeid(*value) == typeid(Value<unsigned long long>))
    {
        return stream << *reinterpret_cast<const Value<unsigned long long>*>(value);
    }
if (typeid(*value) == typeid(Value<const char *>))
    {
        return stream << *reinterpret_cast<const Value<const char *>*>(value);
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

    
    if (typeid(*value) == typeid(Value<egl::EGLint>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLint>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLint *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLint *>*>(value);
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

    
    if (typeid(*value) == typeid(Value<egl::EGLRenderableTypeMask>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLRenderableTypeMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLRenderableTypeMask *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLRenderableTypeMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLSurfaceTypeMask>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSurfaceTypeMask>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLSurfaceTypeMask *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSurfaceTypeMask *>*>(value);
    }

    
    if (typeid(*value) == typeid(Value<egl::EGLSyncFlagsKHR>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSyncFlagsKHR>*>(value);
    }
    
    
    if (typeid(*value) == typeid(Value<egl::EGLSyncFlagsKHR *>))
    {
        return stream << *reinterpret_cast<const Value<egl::EGLSyncFlagsKHR *>*>(value);
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