
#pragma once


#include <eglbinding/egl/types.h>


namespace std
{


template<>
struct hash<egl::EGLextension>
{
    std::size_t operator()(const egl::EGLextension & t) const
    {
        return hash<std::underlying_type<egl::EGLextension>::type>()(static_cast<std::underlying_type<egl::EGLextension>::type>(t));
    }
};


} // namespace std


namespace std
{


template<>
struct hash<egl::EGLenum>
{
    std::size_t operator()(const egl::EGLenum & t) const
    {
        return hash<std::underlying_type<egl::EGLenum>::type>()(static_cast<std::underlying_type<egl::EGLenum>::type>(t));
    }
};


} // namespace std


namespace egl
{


EGLBINDING_CONSTEXPR inline EGLenum operator+(const EGLenum & a, const std::underlying_type<EGLenum>::type b)
{
    return static_cast<EGLenum>(static_cast<std::underlying_type<EGLenum>::type>(a) + b);
}

EGLBINDING_CONSTEXPR inline EGLenum operator-(const EGLenum & a, const std::underlying_type<EGLenum>::type b)
{
    return static_cast<EGLenum>(static_cast<std::underlying_type<EGLenum>::type>(a) - b);
}

EGLBINDING_CONSTEXPR inline bool operator==(const EGLenum & a, std::underlying_type<EGLenum>::type b)
{
    return static_cast<std::underlying_type<EGLenum>::type>(a) == b;
}

EGLBINDING_CONSTEXPR inline bool operator!=(const EGLenum & a, std::underlying_type<EGLenum>::type b)
{
    return static_cast<std::underlying_type<EGLenum>::type>(a) != b;
}

EGLBINDING_CONSTEXPR inline bool operator< (const EGLenum & a, std::underlying_type<EGLenum>::type b)
{
    return static_cast<std::underlying_type<EGLenum>::type>(a) < b;
}

EGLBINDING_CONSTEXPR inline bool operator<=(const EGLenum & a, std::underlying_type<EGLenum>::type b)
{
    return static_cast<std::underlying_type<EGLenum>::type>(a) <= b;
}

EGLBINDING_CONSTEXPR inline bool operator> (const EGLenum & a, std::underlying_type<EGLenum>::type b)
{
    return static_cast<std::underlying_type<EGLenum>::type>(a) > b;
}

EGLBINDING_CONSTEXPR inline bool operator>=(const EGLenum & a, std::underlying_type<EGLenum>::type b)
{
    return static_cast<std::underlying_type<EGLenum>::type>(a) >= b;
}

EGLBINDING_CONSTEXPR inline bool operator==(std::underlying_type<EGLenum>::type a, const EGLenum & b)
{
    return a == static_cast<std::underlying_type<EGLenum>::type>(b);
}

EGLBINDING_CONSTEXPR inline bool operator!=(std::underlying_type<EGLenum>::type a, const EGLenum & b)
{
    return a != static_cast<std::underlying_type<EGLenum>::type>(b);
}

EGLBINDING_CONSTEXPR inline bool operator< (std::underlying_type<EGLenum>::type a, const EGLenum & b)
{
    return a < static_cast<std::underlying_type<EGLenum>::type>(b);
}

EGLBINDING_CONSTEXPR inline bool operator<=(std::underlying_type<EGLenum>::type a, const EGLenum & b)
{
    return a <= static_cast<std::underlying_type<EGLenum>::type>(b);
}

EGLBINDING_CONSTEXPR inline bool operator> (std::underlying_type<EGLenum>::type a, const EGLenum & b)
{
    return a > static_cast<std::underlying_type<EGLenum>::type>(b);
}

EGLBINDING_CONSTEXPR inline bool operator>=(std::underlying_type<EGLenum>::type a, const EGLenum & b)
{
    return a >= static_cast<std::underlying_type<EGLenum>::type>(b);
}


} // namespace egl


namespace std
{


template<>
struct hash<egl::EGLContextFlagMask>
{
    std::size_t operator()(const egl::EGLContextFlagMask & t) const
    {
        return hash<std::underlying_type<egl::EGLContextFlagMask>::type>()(static_cast<std::underlying_type<egl::EGLContextFlagMask>::type>(t));
    }
};


} // namespace std


namespace egl
{


EGLBINDING_CONSTEXPR inline EGLContextFlagMask operator|(const EGLContextFlagMask & a, const EGLContextFlagMask & b)
{
    return static_cast<EGLContextFlagMask>(static_cast<std::underlying_type<EGLContextFlagMask>::type>(a) | static_cast<std::underlying_type<EGLContextFlagMask>::type>(b));
}

inline EGLContextFlagMask & operator|=(EGLContextFlagMask & a, const EGLContextFlagMask & b)
{
    a = static_cast<EGLContextFlagMask>(static_cast<std::underlying_type<EGLContextFlagMask>::type>(a) | static_cast<std::underlying_type<EGLContextFlagMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLContextFlagMask operator&(const EGLContextFlagMask & a, const EGLContextFlagMask & b)
{
    return static_cast<EGLContextFlagMask>(static_cast<std::underlying_type<EGLContextFlagMask>::type>(a) & static_cast<std::underlying_type<EGLContextFlagMask>::type>(b));
}

inline EGLContextFlagMask & operator&=(EGLContextFlagMask & a, const EGLContextFlagMask & b)
{
    a = static_cast<EGLContextFlagMask>(static_cast<std::underlying_type<EGLContextFlagMask>::type>(a) & static_cast<std::underlying_type<EGLContextFlagMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLContextFlagMask operator^(const EGLContextFlagMask & a, const EGLContextFlagMask & b)
{
    return static_cast<EGLContextFlagMask>(static_cast<std::underlying_type<EGLContextFlagMask>::type>(a) ^ static_cast<std::underlying_type<EGLContextFlagMask>::type>(b));
}

inline EGLContextFlagMask & operator^=(EGLContextFlagMask & a, const EGLContextFlagMask & b)
{
    a = static_cast<EGLContextFlagMask>(static_cast<std::underlying_type<EGLContextFlagMask>::type>(a) ^ static_cast<std::underlying_type<EGLContextFlagMask>::type>(b));

    return a;
}


} // namespace egl


namespace std
{


template<>
struct hash<egl::EGLContextProfileMask>
{
    std::size_t operator()(const egl::EGLContextProfileMask & t) const
    {
        return hash<std::underlying_type<egl::EGLContextProfileMask>::type>()(static_cast<std::underlying_type<egl::EGLContextProfileMask>::type>(t));
    }
};


} // namespace std


namespace egl
{


EGLBINDING_CONSTEXPR inline EGLContextProfileMask operator|(const EGLContextProfileMask & a, const EGLContextProfileMask & b)
{
    return static_cast<EGLContextProfileMask>(static_cast<std::underlying_type<EGLContextProfileMask>::type>(a) | static_cast<std::underlying_type<EGLContextProfileMask>::type>(b));
}

inline EGLContextProfileMask & operator|=(EGLContextProfileMask & a, const EGLContextProfileMask & b)
{
    a = static_cast<EGLContextProfileMask>(static_cast<std::underlying_type<EGLContextProfileMask>::type>(a) | static_cast<std::underlying_type<EGLContextProfileMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLContextProfileMask operator&(const EGLContextProfileMask & a, const EGLContextProfileMask & b)
{
    return static_cast<EGLContextProfileMask>(static_cast<std::underlying_type<EGLContextProfileMask>::type>(a) & static_cast<std::underlying_type<EGLContextProfileMask>::type>(b));
}

inline EGLContextProfileMask & operator&=(EGLContextProfileMask & a, const EGLContextProfileMask & b)
{
    a = static_cast<EGLContextProfileMask>(static_cast<std::underlying_type<EGLContextProfileMask>::type>(a) & static_cast<std::underlying_type<EGLContextProfileMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLContextProfileMask operator^(const EGLContextProfileMask & a, const EGLContextProfileMask & b)
{
    return static_cast<EGLContextProfileMask>(static_cast<std::underlying_type<EGLContextProfileMask>::type>(a) ^ static_cast<std::underlying_type<EGLContextProfileMask>::type>(b));
}

inline EGLContextProfileMask & operator^=(EGLContextProfileMask & a, const EGLContextProfileMask & b)
{
    a = static_cast<EGLContextProfileMask>(static_cast<std::underlying_type<EGLContextProfileMask>::type>(a) ^ static_cast<std::underlying_type<EGLContextProfileMask>::type>(b));

    return a;
}


} // namespace egl


namespace std
{


template<>
struct hash<egl::EGLDRMBufferUseMESAMask>
{
    std::size_t operator()(const egl::EGLDRMBufferUseMESAMask & t) const
    {
        return hash<std::underlying_type<egl::EGLDRMBufferUseMESAMask>::type>()(static_cast<std::underlying_type<egl::EGLDRMBufferUseMESAMask>::type>(t));
    }
};


} // namespace std


namespace egl
{


EGLBINDING_CONSTEXPR inline EGLDRMBufferUseMESAMask operator|(const EGLDRMBufferUseMESAMask & a, const EGLDRMBufferUseMESAMask & b)
{
    return static_cast<EGLDRMBufferUseMESAMask>(static_cast<std::underlying_type<EGLDRMBufferUseMESAMask>::type>(a) | static_cast<std::underlying_type<EGLDRMBufferUseMESAMask>::type>(b));
}

inline EGLDRMBufferUseMESAMask & operator|=(EGLDRMBufferUseMESAMask & a, const EGLDRMBufferUseMESAMask & b)
{
    a = static_cast<EGLDRMBufferUseMESAMask>(static_cast<std::underlying_type<EGLDRMBufferUseMESAMask>::type>(a) | static_cast<std::underlying_type<EGLDRMBufferUseMESAMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLDRMBufferUseMESAMask operator&(const EGLDRMBufferUseMESAMask & a, const EGLDRMBufferUseMESAMask & b)
{
    return static_cast<EGLDRMBufferUseMESAMask>(static_cast<std::underlying_type<EGLDRMBufferUseMESAMask>::type>(a) & static_cast<std::underlying_type<EGLDRMBufferUseMESAMask>::type>(b));
}

inline EGLDRMBufferUseMESAMask & operator&=(EGLDRMBufferUseMESAMask & a, const EGLDRMBufferUseMESAMask & b)
{
    a = static_cast<EGLDRMBufferUseMESAMask>(static_cast<std::underlying_type<EGLDRMBufferUseMESAMask>::type>(a) & static_cast<std::underlying_type<EGLDRMBufferUseMESAMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLDRMBufferUseMESAMask operator^(const EGLDRMBufferUseMESAMask & a, const EGLDRMBufferUseMESAMask & b)
{
    return static_cast<EGLDRMBufferUseMESAMask>(static_cast<std::underlying_type<EGLDRMBufferUseMESAMask>::type>(a) ^ static_cast<std::underlying_type<EGLDRMBufferUseMESAMask>::type>(b));
}

inline EGLDRMBufferUseMESAMask & operator^=(EGLDRMBufferUseMESAMask & a, const EGLDRMBufferUseMESAMask & b)
{
    a = static_cast<EGLDRMBufferUseMESAMask>(static_cast<std::underlying_type<EGLDRMBufferUseMESAMask>::type>(a) ^ static_cast<std::underlying_type<EGLDRMBufferUseMESAMask>::type>(b));

    return a;
}


} // namespace egl


namespace std
{


template<>
struct hash<egl::EGLLockUsageHintKHRMask>
{
    std::size_t operator()(const egl::EGLLockUsageHintKHRMask & t) const
    {
        return hash<std::underlying_type<egl::EGLLockUsageHintKHRMask>::type>()(static_cast<std::underlying_type<egl::EGLLockUsageHintKHRMask>::type>(t));
    }
};


} // namespace std


namespace egl
{


EGLBINDING_CONSTEXPR inline EGLLockUsageHintKHRMask operator|(const EGLLockUsageHintKHRMask & a, const EGLLockUsageHintKHRMask & b)
{
    return static_cast<EGLLockUsageHintKHRMask>(static_cast<std::underlying_type<EGLLockUsageHintKHRMask>::type>(a) | static_cast<std::underlying_type<EGLLockUsageHintKHRMask>::type>(b));
}

inline EGLLockUsageHintKHRMask & operator|=(EGLLockUsageHintKHRMask & a, const EGLLockUsageHintKHRMask & b)
{
    a = static_cast<EGLLockUsageHintKHRMask>(static_cast<std::underlying_type<EGLLockUsageHintKHRMask>::type>(a) | static_cast<std::underlying_type<EGLLockUsageHintKHRMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLLockUsageHintKHRMask operator&(const EGLLockUsageHintKHRMask & a, const EGLLockUsageHintKHRMask & b)
{
    return static_cast<EGLLockUsageHintKHRMask>(static_cast<std::underlying_type<EGLLockUsageHintKHRMask>::type>(a) & static_cast<std::underlying_type<EGLLockUsageHintKHRMask>::type>(b));
}

inline EGLLockUsageHintKHRMask & operator&=(EGLLockUsageHintKHRMask & a, const EGLLockUsageHintKHRMask & b)
{
    a = static_cast<EGLLockUsageHintKHRMask>(static_cast<std::underlying_type<EGLLockUsageHintKHRMask>::type>(a) & static_cast<std::underlying_type<EGLLockUsageHintKHRMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLLockUsageHintKHRMask operator^(const EGLLockUsageHintKHRMask & a, const EGLLockUsageHintKHRMask & b)
{
    return static_cast<EGLLockUsageHintKHRMask>(static_cast<std::underlying_type<EGLLockUsageHintKHRMask>::type>(a) ^ static_cast<std::underlying_type<EGLLockUsageHintKHRMask>::type>(b));
}

inline EGLLockUsageHintKHRMask & operator^=(EGLLockUsageHintKHRMask & a, const EGLLockUsageHintKHRMask & b)
{
    a = static_cast<EGLLockUsageHintKHRMask>(static_cast<std::underlying_type<EGLLockUsageHintKHRMask>::type>(a) ^ static_cast<std::underlying_type<EGLLockUsageHintKHRMask>::type>(b));

    return a;
}


} // namespace egl


namespace std
{


template<>
struct hash<egl::EGLRenderableTypeMask>
{
    std::size_t operator()(const egl::EGLRenderableTypeMask & t) const
    {
        return hash<std::underlying_type<egl::EGLRenderableTypeMask>::type>()(static_cast<std::underlying_type<egl::EGLRenderableTypeMask>::type>(t));
    }
};


} // namespace std


namespace egl
{


EGLBINDING_CONSTEXPR inline EGLRenderableTypeMask operator|(const EGLRenderableTypeMask & a, const EGLRenderableTypeMask & b)
{
    return static_cast<EGLRenderableTypeMask>(static_cast<std::underlying_type<EGLRenderableTypeMask>::type>(a) | static_cast<std::underlying_type<EGLRenderableTypeMask>::type>(b));
}

inline EGLRenderableTypeMask & operator|=(EGLRenderableTypeMask & a, const EGLRenderableTypeMask & b)
{
    a = static_cast<EGLRenderableTypeMask>(static_cast<std::underlying_type<EGLRenderableTypeMask>::type>(a) | static_cast<std::underlying_type<EGLRenderableTypeMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLRenderableTypeMask operator&(const EGLRenderableTypeMask & a, const EGLRenderableTypeMask & b)
{
    return static_cast<EGLRenderableTypeMask>(static_cast<std::underlying_type<EGLRenderableTypeMask>::type>(a) & static_cast<std::underlying_type<EGLRenderableTypeMask>::type>(b));
}

inline EGLRenderableTypeMask & operator&=(EGLRenderableTypeMask & a, const EGLRenderableTypeMask & b)
{
    a = static_cast<EGLRenderableTypeMask>(static_cast<std::underlying_type<EGLRenderableTypeMask>::type>(a) & static_cast<std::underlying_type<EGLRenderableTypeMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLRenderableTypeMask operator^(const EGLRenderableTypeMask & a, const EGLRenderableTypeMask & b)
{
    return static_cast<EGLRenderableTypeMask>(static_cast<std::underlying_type<EGLRenderableTypeMask>::type>(a) ^ static_cast<std::underlying_type<EGLRenderableTypeMask>::type>(b));
}

inline EGLRenderableTypeMask & operator^=(EGLRenderableTypeMask & a, const EGLRenderableTypeMask & b)
{
    a = static_cast<EGLRenderableTypeMask>(static_cast<std::underlying_type<EGLRenderableTypeMask>::type>(a) ^ static_cast<std::underlying_type<EGLRenderableTypeMask>::type>(b));

    return a;
}


} // namespace egl


namespace std
{


template<>
struct hash<egl::EGLSurfaceTypeMask>
{
    std::size_t operator()(const egl::EGLSurfaceTypeMask & t) const
    {
        return hash<std::underlying_type<egl::EGLSurfaceTypeMask>::type>()(static_cast<std::underlying_type<egl::EGLSurfaceTypeMask>::type>(t));
    }
};


} // namespace std


namespace egl
{


EGLBINDING_CONSTEXPR inline EGLSurfaceTypeMask operator|(const EGLSurfaceTypeMask & a, const EGLSurfaceTypeMask & b)
{
    return static_cast<EGLSurfaceTypeMask>(static_cast<std::underlying_type<EGLSurfaceTypeMask>::type>(a) | static_cast<std::underlying_type<EGLSurfaceTypeMask>::type>(b));
}

inline EGLSurfaceTypeMask & operator|=(EGLSurfaceTypeMask & a, const EGLSurfaceTypeMask & b)
{
    a = static_cast<EGLSurfaceTypeMask>(static_cast<std::underlying_type<EGLSurfaceTypeMask>::type>(a) | static_cast<std::underlying_type<EGLSurfaceTypeMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLSurfaceTypeMask operator&(const EGLSurfaceTypeMask & a, const EGLSurfaceTypeMask & b)
{
    return static_cast<EGLSurfaceTypeMask>(static_cast<std::underlying_type<EGLSurfaceTypeMask>::type>(a) & static_cast<std::underlying_type<EGLSurfaceTypeMask>::type>(b));
}

inline EGLSurfaceTypeMask & operator&=(EGLSurfaceTypeMask & a, const EGLSurfaceTypeMask & b)
{
    a = static_cast<EGLSurfaceTypeMask>(static_cast<std::underlying_type<EGLSurfaceTypeMask>::type>(a) & static_cast<std::underlying_type<EGLSurfaceTypeMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLSurfaceTypeMask operator^(const EGLSurfaceTypeMask & a, const EGLSurfaceTypeMask & b)
{
    return static_cast<EGLSurfaceTypeMask>(static_cast<std::underlying_type<EGLSurfaceTypeMask>::type>(a) ^ static_cast<std::underlying_type<EGLSurfaceTypeMask>::type>(b));
}

inline EGLSurfaceTypeMask & operator^=(EGLSurfaceTypeMask & a, const EGLSurfaceTypeMask & b)
{
    a = static_cast<EGLSurfaceTypeMask>(static_cast<std::underlying_type<EGLSurfaceTypeMask>::type>(a) ^ static_cast<std::underlying_type<EGLSurfaceTypeMask>::type>(b));

    return a;
}


} // namespace egl


namespace std
{


template<>
struct hash<egl::EGLSyncFlagsKHR>
{
    std::size_t operator()(const egl::EGLSyncFlagsKHR & t) const
    {
        return hash<std::underlying_type<egl::EGLSyncFlagsKHR>::type>()(static_cast<std::underlying_type<egl::EGLSyncFlagsKHR>::type>(t));
    }
};


} // namespace std


namespace egl
{


EGLBINDING_CONSTEXPR inline EGLSyncFlagsKHR operator|(const EGLSyncFlagsKHR & a, const EGLSyncFlagsKHR & b)
{
    return static_cast<EGLSyncFlagsKHR>(static_cast<std::underlying_type<EGLSyncFlagsKHR>::type>(a) | static_cast<std::underlying_type<EGLSyncFlagsKHR>::type>(b));
}

inline EGLSyncFlagsKHR & operator|=(EGLSyncFlagsKHR & a, const EGLSyncFlagsKHR & b)
{
    a = static_cast<EGLSyncFlagsKHR>(static_cast<std::underlying_type<EGLSyncFlagsKHR>::type>(a) | static_cast<std::underlying_type<EGLSyncFlagsKHR>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLSyncFlagsKHR operator&(const EGLSyncFlagsKHR & a, const EGLSyncFlagsKHR & b)
{
    return static_cast<EGLSyncFlagsKHR>(static_cast<std::underlying_type<EGLSyncFlagsKHR>::type>(a) & static_cast<std::underlying_type<EGLSyncFlagsKHR>::type>(b));
}

inline EGLSyncFlagsKHR & operator&=(EGLSyncFlagsKHR & a, const EGLSyncFlagsKHR & b)
{
    a = static_cast<EGLSyncFlagsKHR>(static_cast<std::underlying_type<EGLSyncFlagsKHR>::type>(a) & static_cast<std::underlying_type<EGLSyncFlagsKHR>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline EGLSyncFlagsKHR operator^(const EGLSyncFlagsKHR & a, const EGLSyncFlagsKHR & b)
{
    return static_cast<EGLSyncFlagsKHR>(static_cast<std::underlying_type<EGLSyncFlagsKHR>::type>(a) ^ static_cast<std::underlying_type<EGLSyncFlagsKHR>::type>(b));
}

inline EGLSyncFlagsKHR & operator^=(EGLSyncFlagsKHR & a, const EGLSyncFlagsKHR & b)
{
    a = static_cast<EGLSyncFlagsKHR>(static_cast<std::underlying_type<EGLSyncFlagsKHR>::type>(a) ^ static_cast<std::underlying_type<EGLSyncFlagsKHR>::type>(b));

    return a;
}


} // namespace egl


namespace std
{


template<>
struct hash<egl::UnusedMask>
{
    std::size_t operator()(const egl::UnusedMask & t) const
    {
        return hash<std::underlying_type<egl::UnusedMask>::type>()(static_cast<std::underlying_type<egl::UnusedMask>::type>(t));
    }
};


} // namespace std


namespace egl
{


EGLBINDING_CONSTEXPR inline UnusedMask operator|(const UnusedMask & a, const UnusedMask & b)
{
    return static_cast<UnusedMask>(static_cast<std::underlying_type<UnusedMask>::type>(a) | static_cast<std::underlying_type<UnusedMask>::type>(b));
}

inline UnusedMask & operator|=(UnusedMask & a, const UnusedMask & b)
{
    a = static_cast<UnusedMask>(static_cast<std::underlying_type<UnusedMask>::type>(a) | static_cast<std::underlying_type<UnusedMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline UnusedMask operator&(const UnusedMask & a, const UnusedMask & b)
{
    return static_cast<UnusedMask>(static_cast<std::underlying_type<UnusedMask>::type>(a) & static_cast<std::underlying_type<UnusedMask>::type>(b));
}

inline UnusedMask & operator&=(UnusedMask & a, const UnusedMask & b)
{
    a = static_cast<UnusedMask>(static_cast<std::underlying_type<UnusedMask>::type>(a) & static_cast<std::underlying_type<UnusedMask>::type>(b));

    return a;
}

EGLBINDING_CONSTEXPR inline UnusedMask operator^(const UnusedMask & a, const UnusedMask & b)
{
    return static_cast<UnusedMask>(static_cast<std::underlying_type<UnusedMask>::type>(a) ^ static_cast<std::underlying_type<UnusedMask>::type>(b));
}

inline UnusedMask & operator^=(UnusedMask & a, const UnusedMask & b)
{
    a = static_cast<UnusedMask>(static_cast<std::underlying_type<UnusedMask>::type>(a) ^ static_cast<std::underlying_type<UnusedMask>::type>(b));

    return a;
}


} // namespace egl