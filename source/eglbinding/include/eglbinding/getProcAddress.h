
#pragma once


#include <eglbinding/eglbinding_api.h>

#include <eglbinding/ProcAddress.h>


namespace eglbinding
{


EGLBINDING_API ProcAddress getProcAddress(const char * name);


} // namespace eglbinding
