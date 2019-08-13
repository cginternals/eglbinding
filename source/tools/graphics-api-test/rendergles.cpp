#include "rendergles.h"

#include <glesbinding/glesbinding.h>
#include <glesbinding/gles/gles.h>

#include <eglbinding/egl/functions.h>

using namespace gles;

void initializeGLES()
{
    glesbinding::initialize(egl::eglGetProcAddress);
}

void uninitializeGLES()
{
    glesbinding::releaseCurrentContext();
}

void resizeGLES(int width, int height)
{
    glViewport(0, 0, width, height);
}

void renderGLES()
{
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
