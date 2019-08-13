
#include <eglbinding/getProcAddress.h>

#include "eglGetProcAddress.h"


namespace eglbinding
{


ProcAddress getProcAddress(const char * name)
{
    return ::eglGetProcAddress(name);
}


} // namespace eglbinding
