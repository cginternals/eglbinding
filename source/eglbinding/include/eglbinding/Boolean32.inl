
#pragma once


namespace eglbinding
{


EGLBINDING_CONSTEXPR Boolean32::Boolean32()
: Boolean32(false)
{
}

EGLBINDING_CONSTEXPR Boolean32::Boolean32(bool value)
: m_value(static_cast<underlying_type>(value))
{
}

EGLBINDING_CONSTEXPR Boolean32::Boolean32(char value)
: m_value(value)
{
}

EGLBINDING_CONSTEXPR Boolean32::Boolean32(unsigned char value)
: m_value(static_cast<underlying_type>(value))
{
}

EGLBINDING_CONSTEXPR Boolean32::Boolean32(int value)
: m_value(static_cast<underlying_type>(value))
{
}

EGLBINDING_CONSTEXPR Boolean32::Boolean32(unsigned int value)
: m_value(static_cast<underlying_type>(value))
{
}

EGLBINDING_CONSTEXPR Boolean32::operator bool() const
{
    return m_value != 0;
}

EGLBINDING_CONSTEXPR Boolean32::operator char() const
{
    return m_value;
}

EGLBINDING_CONSTEXPR Boolean32::operator unsigned char() const
{
    return m_value;
}

EGLBINDING_CONSTEXPR Boolean32::operator int() const
{
    return m_value;
}

EGLBINDING_CONSTEXPR Boolean32::operator unsigned int() const
{
    return m_value;
}

Boolean32 & Boolean32::operator=(const Boolean32 & other)
{
    m_value = other.m_value;

    return *this;
}

EGLBINDING_CONSTEXPR bool Boolean32::operator<(const Boolean32 & other) const
{
    return m_value < other.m_value;
}

EGLBINDING_CONSTEXPR bool Boolean32::operator>(const Boolean32 & other) const
{
    return m_value > other.m_value;
}

EGLBINDING_CONSTEXPR bool Boolean32::operator<=(const Boolean32 & other) const
{
    return m_value <= other.m_value;
}

EGLBINDING_CONSTEXPR bool Boolean32::operator>=(const Boolean32 & other) const
{
    return m_value >= other.m_value;
}

EGLBINDING_CONSTEXPR bool Boolean32::operator==(const Boolean32 & other) const
{
    return m_value == other.m_value;
}

EGLBINDING_CONSTEXPR bool Boolean32::operator!=(const Boolean32 & other) const
{
    return m_value != other.m_value;
}


} // namespace eglbinding


namespace std
{


template<>
struct hash<eglbinding::Boolean32>
{
    std::size_t operator()(const eglbinding::Boolean32 & boolean) const
    {
        return hash<eglbinding::Boolean32::underlying_type>()(static_cast<eglbinding::Boolean32::underlying_type>(boolean));
    }
};


} // namespace std
