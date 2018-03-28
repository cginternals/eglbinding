
#include "getProcAddress.h"

#include <EGL/egl.h>


ProcAddress getProcAddress(const char * name)
{
    return eglGetProcAddress(name);
}
