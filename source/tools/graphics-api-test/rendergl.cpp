#include "rendergl.h"

#include <glbinding/gl/gl.h>
#include <glbinding/glbinding.h>

#include <eglbinding/egl/functions.h>

using namespace gl;

void initializeGL()
{
    glbinding::initialize(egl::eglGetProcAddress);
}

void uninitializeGL()
{
    glbinding::releaseCurrentContext();
}

void resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void renderGL()
{
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}
