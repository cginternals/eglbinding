
#include <iostream>
#include <map>
#include <array>
#include <set>
#include <cstring>

// EGL

#include <eglbinding-aux/Meta.h>
#include <eglbinding/AbstractFunction.h>
#include <eglbinding-aux/ContextInfo.h>
#include <eglbinding/Version.h>
#include <eglbinding/eglbinding.h>

#include <eglbinding/egl/egl.h>

#include <eglbinding-aux/ValidVersions.h>
#include <eglbinding-aux/types_to_string.h>

// OpenGL

#include <glbinding/glbinding.h>
#include <glbinding-aux/ContextInfo.h>

// OpenGL ES

#include <glesbinding/glesbinding.h>
#include <glesbinding-aux/ContextInfo.h>

// Local

#include "getProcAddress.h"


using namespace egl;


bool testContext(EGLDisplay eglDpy, EGLConfig config, EGLenum api, EGLint & majorVersion, EGLint & minorVersion)
{
    static const EGLint ctxattr[] = {
        static_cast<EGLint>(EGL_CONTEXT_MAJOR_VERSION), majorVersion,
        static_cast<EGLint>(EGL_CONTEXT_MINOR_VERSION), minorVersion,
        static_cast<EGLint>(EGL_NONE),
        static_cast<EGLint>(EGL_CONTEXT_CLIENT_VERSION), majorVersion,
        static_cast<EGLint>(EGL_NONE)
    };

    eglBindAPI(api);

    //auto context = eglCreateContext(eglDpy, reinterpret_cast<egl::EGLSurface>(EGL_NO_CONFIG_KHR), nullptr, ctxattr);
    auto context = eglCreateContext(eglDpy, config, nullptr, ctxattr + (api == egl::EGL_OPENGL_API ? 0 : 5));

    if (!context)
    {
        majorVersion = 0;
        minorVersion = 0;
        return false;
    }

    EGLenum providedApi;
    eglQueryContext(eglDpy, context, static_cast<EGLint>(EGL_CONTEXT_CLIENT_TYPE), reinterpret_cast<EGLint *>(&providedApi));

    if (api != providedApi)
    {
        majorVersion = 0;
        minorVersion = 0;
        eglDestroyContext(eglDpy, context);

        return false;
    }

    if (!eglMakeCurrent(eglDpy, reinterpret_cast<egl::EGLSurface>(egl::EGL_NO_SURFACE), reinterpret_cast<egl::EGLSurface>(egl::EGL_NO_SURFACE), context))
    {
        eglDestroyContext(eglDpy, context);
        majorVersion = 0;
        minorVersion = 0;

        return false;
    }

    if (api == egl::EGL_OPENGL_API)
    {
        glbinding::initialize(getProcAddress, false);

        const auto glVersion = glbinding::aux::ContextInfo::version();

        if (glVersion != glbinding::Version(majorVersion, minorVersion))
        {
            glbinding::releaseCurrentContext();
            eglDestroyContext(eglDpy, context);
            majorVersion = glVersion.majorVersion();
            minorVersion = glVersion.minorVersion();

            return false;
        }
    }
    else if (api == egl::EGL_OPENGL_ES_API)
    {
        glesbinding::initialize(getProcAddress, false);

        const auto glesVersion = glesbinding::aux::ContextInfo::version();

        if (glesVersion != glesbinding::Version(majorVersion, minorVersion))
        {
            glesbinding::releaseCurrentContext();
            eglDestroyContext(eglDpy, context);
            majorVersion = glesVersion.majorVersion();
            minorVersion = glesVersion.minorVersion();

            return false;
        }
    }

    eglDestroyContext(eglDpy, context);

    return true;
}


int main(int argc, char * argv[])
{
    eglbinding::initialize(getProcAddress);

    static const EGLint configAttribs[] = {
        static_cast<EGLint>(EGL_SURFACE_TYPE), static_cast<EGLint>(EGL_PBUFFER_BIT),
        static_cast<EGLint>(EGL_BLUE_SIZE), 8,
        static_cast<EGLint>(EGL_GREEN_SIZE), 8,
        static_cast<EGLint>(EGL_RED_SIZE), 8,
        static_cast<EGLint>(EGL_RENDERABLE_TYPE), static_cast<EGLint>(EGL_OPENGL_BIT | EGL_OPENGL_ES3_BIT | EGL_OPENGL_ES2_BIT),
        static_cast<EGLint>(EGL_NONE)
    };

    EGLDisplay eglDpy = eglGetDisplay(static_cast<EGLint>(EGL_DEFAULT_DISPLAY));

    if (eglDpy == nullptr)
    {
        std::cerr << "Could not load display" << std::endl;
        return -1;
    }
    else
    {
        std::clog << "Load display " << eglDpy << std::endl;
    }

    EGLint vmajor, vminor;

    if (!eglInitialize(eglDpy, &vmajor, &vminor))
    {
        std::cerr << "Could not initialize EGL: " << std::hex << eglGetError() << std::endl;
    }
    else
    {
        std::clog << "Initialize EGL " << vmajor << "." << vminor << std::endl;
    }

    std::clog << "APIs: " << eglQueryString(eglDpy, static_cast<EGLint>(EGL_CLIENT_APIS)) << std::endl;
    std::clog << "Extensions: " << eglQueryString(eglDpy, static_cast<EGLint>(EGL_EXTENSIONS)) << std::endl;
    std::clog << "Vendor: " << eglQueryString(eglDpy, static_cast<EGLint>(EGL_VENDOR)) << std::endl;
    std::clog << "Version: " << eglQueryString(eglDpy, static_cast<EGLint>(EGL_VERSION)) << std::endl;

    // 2. Select an appropriate configuration
    EGLint numConfigs;
    std::array<EGLConfig, 128> eglCfgs;

    eglChooseConfig(eglDpy, configAttribs, eglCfgs.data(), eglCfgs.size(), &numConfigs);

    std::clog << std::endl << numConfigs << " framebuffer configurations available" <<  std::endl;

    std::clog << std::endl << "Testing Contexts" << std::endl << std::endl;

    using ContextDescription = std::pair<EGLenum, std::pair<EGLint, EGLint>>;

    for (const auto & description : {
         //ContextDescription{ EGL_OPENGL_API, { 1, 0 } },
         //ContextDescription{ EGL_OPENGL_API, { 1, 1 } },
         ContextDescription{ EGL_OPENGL_API, { 2, 0 } },
         ContextDescription{ EGL_OPENGL_API, { 2, 1 } },
         ContextDescription{ EGL_OPENGL_API, { 3, 0 } },
         ContextDescription{ EGL_OPENGL_API, { 3, 1 } },
         ContextDescription{ EGL_OPENGL_API, { 3, 2 } },
         ContextDescription{ EGL_OPENGL_API, { 3, 3 } },
         ContextDescription{ EGL_OPENGL_API, { 4, 0 } },
         ContextDescription{ EGL_OPENGL_API, { 4, 1 } },
         ContextDescription{ EGL_OPENGL_API, { 4, 2 } },
         ContextDescription{ EGL_OPENGL_API, { 4, 3 } },
         ContextDescription{ EGL_OPENGL_API, { 4, 4 } },
         ContextDescription{ EGL_OPENGL_API, { 4, 5 } },
         ContextDescription{ EGL_OPENGL_API, { 4, 6 } },
         ContextDescription{ EGL_OPENGL_API, { 4, 7 } },
         ContextDescription{ EGL_OPENGL_API, { 5, 0 } },
    })
    {
        auto majorVersion = description.second.first;
        auto minorVersion = description.second.second;

        std::cout << "OpenGL    " << majorVersion << "." << minorVersion << " ";

        if (testContext(eglDpy, eglCfgs[0], description.first, majorVersion, minorVersion))
        {
            std::cout << "Success" << std::endl;
        }
        else
        {
            if (majorVersion > 0)
            {
                std::cout << "Fallback to " << majorVersion << "." << minorVersion << std::endl;
            }
            else
            {
                std::cout << "Failed" << std::endl;
            }
        }
    }

    std::clog << std::endl;

    for (const auto & description : {
         ContextDescription{ EGL_OPENGL_ES_API, { 0, 0 } },
         ContextDescription{ EGL_OPENGL_ES_API, { 1, 0 } },
         ContextDescription{ EGL_OPENGL_ES_API, { 2, 0 } },
         ContextDescription{ EGL_OPENGL_ES_API, { 3, 0 } },
         ContextDescription{ EGL_OPENGL_ES_API, { 3, 1 } },
         ContextDescription{ EGL_OPENGL_ES_API, { 3, 2 } },
         ContextDescription{ EGL_OPENGL_ES_API, { 3, 3 } },
         ContextDescription{ EGL_OPENGL_ES_API, { 3, 4 } },
    })
    {
        auto majorVersion = description.second.first;
        auto minorVersion = description.second.second;

        std::cout << "OpenGL ES " << majorVersion << "." << minorVersion << " ";

        if (testContext(eglDpy, eglCfgs[0], description.first, majorVersion, minorVersion))
        {
            std::cout << "Success" << std::endl;
        }
        else
        {
            if (majorVersion > 0)
            {
                std::cout << "Fallback to " << majorVersion << "." << minorVersion << std::endl;
            }
            else
            {
                std::cout << "Failed" << std::endl;
            }
        }
    }

    eglTerminate(eglDpy);

    return 0;
}
