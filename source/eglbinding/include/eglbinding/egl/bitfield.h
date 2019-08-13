
#pragma once


#include <eglbinding/noegl.h>

#include <eglbinding/eglbinding_features.h>

#include <eglbinding/SharedBitfield.h>


namespace egl
{


enum class UnusedMask : unsigned int
{
    GL_UNUSED_BIT = 0x00000000
};


// import bitfields to namespace

EGLBINDING_CONSTEXPR static const UnusedMask GL_UNUSED_BIT = UnusedMask::GL_UNUSED_BIT;


} // namespace egl