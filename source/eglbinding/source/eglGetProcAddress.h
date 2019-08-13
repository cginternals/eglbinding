
#pragma once

#include <KHR/khrplatform.h>

#ifndef EGLAPI
#define EGLAPI KHRONOS_APICALL
#endif

#ifndef EGLAPIENTRY
#define EGLAPIENTRY  KHRONOS_APIENTRY
#endif
#define EGLAPIENTRYP EGLAPIENTRY*

typedef void (*__eglMustCastToProperFunctionPointerType)(void);

#ifdef __cplusplus
extern "C" {
#endif

EGLAPI __eglMustCastToProperFunctionPointerType EGLAPIENTRY eglGetProcAddress (const char *procname);

#ifdef __cplusplus
}
#endif
