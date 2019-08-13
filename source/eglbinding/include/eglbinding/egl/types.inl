
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