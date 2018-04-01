
#include <gmock/gmock.h>

#include <eglbinding/egl/egl.h>
#include <eglbinding/egl10/egl.h>
#include <eglbinding/egl10ext/egl.h>
#include <eglbinding/egl11/egl.h>
#include <eglbinding/egl11ext/egl.h>
#include <eglbinding/egl12/egl.h>
#include <eglbinding/egl12ext/egl.h>
#include <eglbinding/egl13/egl.h>
#include <eglbinding/egl13ext/egl.h>
#include <eglbinding/egl14/egl.h>
#include <eglbinding/egl14ext/egl.h>
#include <eglbinding/egl15/egl.h>
#include <eglbinding/egl15ext/egl.h>


TEST(AllVersions, Compilation)
{
    SUCCEED();  // compiling this file without errors and warnings results in successful test
}
