
#pragma once


#include <string>
#include <iosfwd>

#include <eglbinding-aux/eglbinding-aux_api.h>
#include <eglbinding-aux/eglbinding-aux_features.h>

#include <eglbinding/egl/types.h>
#include <eglbinding/Value.h>


namespace egl
{


EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const EGLBoolean & value);
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const EGLenum & value);
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const EGLextension & value);
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const EGLContextFlagMask & value);
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const EGLContextProfileMask & value);
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const EGLDRMBufferUseMESAMask & value);
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const EGLLockUsageHintKHRMask & value);
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const EGLRenderableTypeMask & value);
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const EGLSurfaceTypeMask & value);
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const EGLSyncFlagsKHR & value);
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const UnusedMask & value);


} // namespace egl


namespace eglbinding
{


class Version;


/**
*  @brief
*    Generic ostream operator for the Value template
*/
template <typename T>
EGLBINDING_AUX_TEMPLATE_API std::ostream & operator<<(std::ostream & stream, const Value<T> & value);

/**
*  @brief
*    Generic ostream operator for the Value template with pointer types
*/
template <typename T>
EGLBINDING_AUX_TEMPLATE_API std::ostream & operator<<(std::ostream & stream, const Value<T *> & value);

/**
*  @brief
*    A specialized ostream operator for the gl::GLenum Value template
*/
template <>
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const Value<egl::EGLenum> & value);

/* <- ToDo: Add back second * when implementing this function again
*  @brief
*    A specialized ostream operator for the gl::GLbitfield Value template
*/
/*template <>
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const Value<egl::EGLbitfield> & value);*/

/**
*  @brief
*    A specialized ostream operator for the gl::GLenum Value template
*/
template <>
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const Value<egl::EGLBoolean> & value);



/**
*  @brief
*    The operator to allow Versions to be printed onto a std::ostream
*/
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const Version & version);

/**
*  @brief
*    The operator to allow AbstractValues to be printed onto a std::ostream
*/
EGLBINDING_AUX_API std::ostream & operator<<(std::ostream & stream, const AbstractValue * value);


} // namespace eglbinding


#include <eglbinding-aux/types_to_string.inl>