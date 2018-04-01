
#pragma once


#include <functional>

#include <eglbinding/eglbinding_api.h>
#include <eglbinding/eglbinding_features.h>


namespace eglbinding
{


class EGLBINDING_API Boolean32
{
public:
    using underlying_type = unsigned int;

public:
    EGLBINDING_CONSTEXPR inline Boolean32();
    EGLBINDING_CONSTEXPR inline Boolean32(bool on);
    EGLBINDING_CONSTEXPR inline Boolean32(char on);
    EGLBINDING_CONSTEXPR inline Boolean32(unsigned char on);
    EGLBINDING_CONSTEXPR inline Boolean32(int on);
    EGLBINDING_CONSTEXPR inline Boolean32(unsigned int on);

    EGLBINDING_CONSTEXPR inline explicit operator bool() const;
    EGLBINDING_CONSTEXPR inline explicit operator char() const;
    EGLBINDING_CONSTEXPR inline explicit operator unsigned char() const;
    EGLBINDING_CONSTEXPR inline explicit operator int() const;
    EGLBINDING_CONSTEXPR inline explicit operator unsigned int() const;

    inline Boolean32 & operator=(const Boolean32 & other);
    EGLBINDING_CONSTEXPR inline bool operator<(const Boolean32 & other) const;
    EGLBINDING_CONSTEXPR inline bool operator>(const Boolean32 & other) const;
    EGLBINDING_CONSTEXPR inline bool operator<=(const Boolean32 & other) const;
    EGLBINDING_CONSTEXPR inline bool operator>=(const Boolean32 & other) const;

    EGLBINDING_CONSTEXPR inline bool operator==(const Boolean32 & other) const;
    EGLBINDING_CONSTEXPR inline bool operator!=(const Boolean32 & other) const;

public:
    underlying_type m_value;
};


} // namespace gl


#include <eglbinding/Boolean32.inl>
