
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
#include <eglbinding/eglGetProcAddress.h>

#include <eglbinding-aux/ValidVersions.h>
#include <eglbinding-aux/types_to_string.h>

// OpenGL

#include <glbinding/glbinding.h>
#include <glbinding-aux/ContextInfo.h>

// OpenGL ES

#include <glesbinding/glesbinding.h>
#include <glesbinding-aux/ContextInfo.h>


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
        glbinding::initialize(::eglGetProcAddress, false);

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
        glesbinding::initialize(::eglGetProcAddress, false);

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
    else if (api == egl::EGL_OPENVG_API)
    {
        majorVersion = -1;
        minorVersion = -1;
    }

    eglDestroyContext(eglDpy, context);

    return true;
}


void outputConfigs(EGLDisplay display)
{
    EGLint numConfigs;
    std::array<EGLConfig, 128> eglCfgs;

    eglGetConfigs(display, eglCfgs.data(), eglCfgs.size(), &numConfigs);

    std::cout << std::endl << numConfigs << " framebuffer configurations available" <<  std::endl;

    for (int i = 0; i < numConfigs; ++i)
    {
        const auto & config = eglCfgs[i];

        EGLint red;
        EGLint green;
        EGLint blue;
        EGLint alpha;
        EGLint depth;
        EGLint stencil;
        EGLint luminance;
        EGLint multisamples;
        EGLint multisamplingBuffers;

        eglGetConfigAttrib(display, config, static_cast<EGLint>(EGL_RED_SIZE), &red);
        eglGetConfigAttrib(display, config, static_cast<EGLint>(EGL_GREEN_SIZE), &green);
        eglGetConfigAttrib(display, config, static_cast<EGLint>(EGL_BLUE_SIZE), &blue);
        eglGetConfigAttrib(display, config, static_cast<EGLint>(EGL_ALPHA_SIZE), &alpha);
        eglGetConfigAttrib(display, config, static_cast<EGLint>(EGL_DEPTH_SIZE), &depth);
        eglGetConfigAttrib(display, config, static_cast<EGLint>(EGL_STENCIL_SIZE), &stencil);
        eglGetConfigAttrib(display, config, static_cast<EGLint>(EGL_LUMINANCE_SIZE), &luminance);
        eglGetConfigAttrib(display, config, static_cast<EGLint>(EGL_SAMPLES), &multisamples);
        eglGetConfigAttrib(display, config, static_cast<EGLint>(EGL_SAMPLE_BUFFERS), &multisamplingBuffers);

        std::cout << "Config " << (i+1) << ":";
        std::cout << " R" << red << " G" << green << " B" << blue << " A" << alpha << " D" << depth << " S" << stencil << " L" << luminance;
        std::cout << " M" << multisamples << ":" << multisamplingBuffers;

        EGLint surfaceAttribs;
        if (eglGetConfigAttrib(display, config, static_cast<EGLint>(EGL_SURFACE_TYPE), &surfaceAttribs))
        {
            if (surfaceAttribs & static_cast<EGLint>(EGL_PBUFFER_BIT))
            {
                std::cout << " Pixelbuffer";
            }

            if (surfaceAttribs & static_cast<EGLint>(EGL_PIXMAP_BIT))
            {
                std::cout << " Pixmap";
            }

            if (surfaceAttribs & static_cast<EGLint>(EGL_WINDOW_BIT))
            {
                std::cout << " Window";
            }
        }

        EGLint apis;
        if (eglGetConfigAttrib(display, config, static_cast<EGLint>(EGL_CONFORMANT), &apis))
        {
            if (apis & static_cast<EGLint>(EGL_OPENGL_BIT))
            {
                std::cout << " GL";
            }

            if (apis & static_cast<EGLint>(EGL_OPENGL_ES2_BIT))
            {
                std::cout << " ES2";
            }

            if (apis & static_cast<EGLint>(EGL_OPENGL_ES2_BIT))
            {
                std::cout << " ES3";
            }

            if (apis & static_cast<EGLint>(EGL_OPENVG_BIT))
            {
                std::cout << " VG";
            }
        }

        EGLint nativeSurface;
        if (eglGetConfigAttrib(display, config, static_cast<EGLint>(EGL_NATIVE_RENDERABLE), &nativeSurface))
        {
            std::cout << (nativeSurface ? " (native)" : " (virtual)");
        }

        std::cout << std::endl;
    }
}


int main(int argc, char * argv[])
{
    eglbinding::initialize(::eglGetProcAddress);

    //const auto supportedExtensions = eglbinding::aux::ContextInfo::extensions();

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
        std::cout << "Load display " << eglDpy << std::endl;
    }

    EGLint vmajor, vminor;

    if (!eglInitialize(eglDpy, &vmajor, &vminor))
    {
        std::cerr << "Could not initialize EGL: " << std::hex << eglGetError() << std::endl;
    }
    else
    {
        std::cout << "Initialize EGL " << vmajor << "." << vminor << std::endl;
    }

    const auto apiString = eglQueryString(eglDpy, static_cast<EGLint>(EGL_CLIENT_APIS));
    std::cout << "APIs: " << (strlen(apiString) > 0 ? apiString : "unspecified") << std::endl;
    std::cout << "Extensions: " << eglQueryString(eglDpy, static_cast<EGLint>(EGL_EXTENSIONS)) << std::endl;
    std::cout << "Vendor: " << eglQueryString(eglDpy, static_cast<EGLint>(EGL_VENDOR)) << std::endl;
    std::cout << "Version: " << eglQueryString(eglDpy, static_cast<EGLint>(EGL_VERSION)) << std::endl;

    outputConfigs(eglDpy);

    // 2. Select an appropriate configuration
    EGLint numConfigs = 1;
    EGLConfig eglCfg;

    eglChooseConfig(eglDpy, configAttribs, &eglCfg, numConfigs, &numConfigs);

    std::cout << std::endl << "Testing Contexts" << std::endl << std::endl;

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

        if (testContext(eglDpy, eglCfg, description.first, majorVersion, minorVersion))
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

    std::cout << std::endl;

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

        if (testContext(eglDpy, eglCfg, description.first, majorVersion, minorVersion))
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

    std::cout << std::endl;

    for (const auto & description : {
         ContextDescription{ EGL_OPENVG_API, { 0, 0 } },
         ContextDescription{ EGL_OPENVG_API, { 1, 0 } },
         ContextDescription{ EGL_OPENVG_API, { 1, 1 } },
         ContextDescription{ EGL_OPENVG_API, { 2, 0 } },
    })
    {
        auto majorVersion = description.second.first;
        auto minorVersion = description.second.second;

        std::cout << "OpenVG    " << majorVersion << "." << minorVersion << " ";

        if (testContext(eglDpy, eglCfg, description.first, majorVersion, minorVersion))
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

    std::cout << std::endl;

    std::cout << "Enumerating Devices: ";

    std::array<EGLDeviceEXT, 255> devices;

    EGLint numDevices = 0;

    if (eglQueryDevicesEXT(255, devices.data(), &numDevices))
    {
        std::cout << numDevices << " available" << std::endl;

        for (auto i = 0; i < numDevices; ++i)
        {
            const auto & device = devices[i];

            std::cout << std::endl << "Device " << (i+1) << std::endl;

            const auto deviceDisplay = eglGetPlatformDisplayEXT(EGL_PLATFORM_DEVICE_EXT, device, nullptr);

            EGLAttrib attribValue;
            auto stringValue = eglQueryDeviceStringEXT(device, static_cast<EGLint>(EGL_EXTENSIONS));
            if (stringValue)
            {
                std::cout << "Extensions: " << stringValue << std::endl;
            }

            stringValue = eglQueryDeviceStringEXT(device, static_cast<EGLint>(EGL_DRM_DEVICE_FILE_EXT));
            if (stringValue)
            {
                std::cout << "Direct Device File: " << stringValue << std::endl;
            }

            if (eglQueryDeviceAttribEXT(device, static_cast<EGLint>(EGL_CUDA_DEVICE_NV), &attribValue))
            {
                std::cout << "Cuda Device ID: " << attribValue << std::endl;
            }

            if (eglQueryDeviceAttribEXT(device, static_cast<EGLint>(EGL_OPENWF_DEVICE_ID_EXT), &attribValue))
            {
                std::cout << "OpenWF Device ID: " << attribValue << std::endl;
            }

            if (eglInitialize(deviceDisplay, nullptr, nullptr))
            {
                outputConfigs(deviceDisplay);

                eglTerminate(deviceDisplay);
            }
            else
            {
                std::cout << "Could not initialize device display" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "unsupported" << std::endl;
    }

    eglTerminate(eglDpy);

    return 0;
}
