
#pragma once


namespace eglbinding
{


EGLBINDING_CONSTEXPR Boolean8::Boolean8()
: Boolean8(false)
{
}

EGLBINDING_CONSTEXPR Boolean8::Boolean8(bool value)
: m_value(static_cast<underlying_type>(value))
{
}

EGLBINDING_CONSTEXPR Boolean8::Boolean8(char value)
: m_value(value)
{
}

EGLBINDING_CONSTEXPR Boolean8::Boolean8(unsigned char value)
: m_value(static_cast<underlying_type>(value))
{
}

EGLBINDING_CONSTEXPR Boolean8::Boolean8(int value)
: m_value(static_cast<underlying_type>(value))
{
}

EGLBINDING_CONSTEXPR Boolean8::Boolean8(unsigned int value)
: m_value(static_cast<underlying_type>(value))
{
}

EGLBINDING_CONSTEXPR Boolean8::operator bool() const
{
    return m_value != 0;
}

EGLBINDING_CONSTEXPR Boolean8::operator char() const
{
    return m_value;
}

EGLBINDING_CONSTEXPR Boolean8::operator unsigned char() const
{
    return m_value;
}

EGLBINDING_CONSTEXPR Boolean8::operator int() const
{
    return m_value;
}

EGLBINDING_CONSTEXPR Boolean8::operator unsigned int() const
{
    return m_value;
}

Boolean8 & Boolean8::operator=(const Boolean8 & other)
{
    m_value = other.m_value;

    return *this;
}

EGLBINDING_CONSTEXPR bool Boolean8::operator<(const Boolean8 & other) const
{
    return m_value < other.m_value;
}

EGLBINDING_CONSTEXPR bool Boolean8::operator>(const Boolean8 & other) const
{
    return m_value > other.m_value;
}

EGLBINDING_CONSTEXPR bool Boolean8::operator<=(const Boolean8 & other) const
{
    return m_value <= other.m_value;
}

EGLBINDING_CONSTEXPR bool Boolean8::operator>=(const Boolean8 & other) const
{
    return m_value >= other.m_value;
}

EGLBINDING_CONSTEXPR bool Boolean8::operator==(const Boolean8 & other) const
{
    return m_value == other.m_value;
}

EGLBINDING_CONSTEXPR bool Boolean8::operator!=(const Boolean8 & other) const
{
    return m_value != other.m_value;
}


} // namespace eglbinding


namespace std
{


template<>
struct hash<eglbinding::Boolean8>
{
    std::size_t operator()(const eglbinding::Boolean8 & boolean) const
    {
        return hash<eglbinding::Boolean8::underlying_type>()(static_cast<eglbinding::Boolean8::underlying_type>(boolean));
    }
};


} // namespace std