
#pragma once


#include <string>
#include <set>
#include <array>
#include <vector>
#include <functional>
#include <unordered_map>

#ifdef EGLBINDING_USE_BOOST_THREAD
#include <boost/thread.hpp>
namespace std_boost = boost;
#else
#include <mutex>
namespace std_boost = std;
#endif

#include <eglbinding/eglbinding_api.h>
#include <eglbinding/eglbinding_features.h>

#include <eglbinding/AbstractFunction.h>
#include <eglbinding/ContextHandle.h>
#include <eglbinding/Function.h>
#include <eglbinding/CallbackMask.h>
#include <eglbinding/FunctionCall.h>
#include <eglbinding/ProcAddress.h>

#include <eglbinding/egl/types.h>


namespace eglbinding
{


/**
*  @brief
*    The main interface to handle additional features to OpenGL functions besides regular function calls
*
*  Additional features include binding initialization (even for multi-threaded environments), additional function registration,
*  context switches (for multi-context environments) and basic reflection in form of accessors to the full list of functions.
*/
class EGLBINDING_API Binding
{
public:
    /**
    *  @brief
    *    The callback type of a simple function callback without parameters and return value
    */
    using SimpleFunctionCallback = std::function<void(const AbstractFunction &)>;

    /**
    *  @brief
    *    The callback type of a function callback with parameters and return value
    */
    using FunctionCallback = std::function<void(const FunctionCall &)>;

    /**
    *  @brief
    *    The callback type of a function log callback with parameters and return value
    */
    using FunctionLogCallback = std::function<void(FunctionCall *)>;

    using ContextSwitchCallback = std::function<void(ContextHandle)>;   ///< The signature of the context switch callback
    
    using array_t = std::array<AbstractFunction *, 140>; ///< The type of the build-in functions collection


public:
    /**
    *  @brief
    *    Deleted Constructor as all functions are static
    */
    Binding() = delete;

    /**
    *  @brief
    *    Initializes the binding for the current active OpenGL context
    *
    *  @param[in] functionPointerResolver
    *    A function pointer to resolve binding functions for this context.
    *    If `nullptr` is passed for first time initialization, `eglbinding::getProcAddress` is used for convenience.
    *  @param[in] resolveFunctions (optional)
    *    Whether to resolve function pointers lazy (\a resolveFunctions = `false`) or immediately
    *
    *  @remark
    *    After this call, the initialized context is already set active for the current thread.
    *
    *  @remark
    *    A functionPointerResolver with value 'nullptr' will get initialized with the function
    *    pointer from the initial thread.
    *
    *  @remark
    *    Using eglbinding::getProcAddress is provided for convenience only. Please don't use this in new code.
    *    Instead, use an external function resolution callback, e.g.,
    *     * wglGetProcAddress
    *     * glxGetProcAddress
    *     * glfwGetProcAddress
    *     * QOpenGlContext::getProcAddress
    */
    static void initialize(eglbinding::GetProcAddress functionPointerResolver, bool resolveFunctions = true);

    /**
    *  @brief
    *    Initializes the binding for a specific OpenGL context
    *
    *  @param[in] context
    *    The context handle of the context to initialize
    *  @param[in] functionPointerResolver
    *    A function pointer to resolve binding functions for this context
    *  @param[in] useContext
    *    Whether to set the context active (\a useContext = `true`) after the initialization
    *  @param[in] resolveFunctions (optional)
    *    Whether to resolve function pointers lazy (\a resolveFunctions = `false`) or immediately
    *
    *  @remark
    *    A functionPointerResolver with value 'nullptr' will get initialized with the function
    *    pointer from the initial thread.
    */
    static void initialize(ContextHandle context, eglbinding::GetProcAddress functionPointerResolver, bool useContext = true, bool resolveFunctions = true);

    /**
    *  @brief
    *    Registers an additional function for the additional features
    *
    *  @param[in] function
    *    The function to register
    */
    static void registerAdditionalFunction(AbstractFunction * function);

    /**
    *  @brief
    *    Resolve a single function pointer by given name
    *
    *  @param[in] name
    *    The name of the function
    */
    static ProcAddress resolveFunction(const char * name);

    /**
    *  @brief
    *    Resolves the funtion pointers of all registered OpenGL functions immediately for the current context
    */
    static void resolveFunctions();

    /**
    *  @brief
    *    Update the current context state in eglbinding
    *
    *  @remark
    *    This function queries the driver for the current OpenGL context
    */
    static void useCurrentContext();

    /**
    *  @brief
    *    Update the current context state in eglbinding
    *
    *  @param[in] context
    *    The context handle of the context to set current
    */
    static void useContext(ContextHandle context);

    /**
    *  @brief
    *    Removes the current context from the state of eglbinding
    *
    *  @remark
    *    This function queries the driver for the current OpenGL context
    */
    static void releaseCurrentContext();

    /**
    *  @brief
    *    Removes the current context from the state of eglbinding
    *
    *  @param[in] context
    *    The context handle of the context to remove
    */
    static void releaseContext(ContextHandle context);

    /**
    *  @brief
    *    Registers an additional callback that gets called each time the context is switched using the useContext method
    *
    *  @remark
    *    There may be multiple context switch callbacks registered at once
    */
    static void addContextSwitchCallback(ContextSwitchCallback callback);

    /**
    *  @brief
    *    Updates the callback mask of all registered OpenGL functions in the current state
    *
    *  @param[in] mask
    *    The new CallbackMask
    */
    static void setCallbackMask(CallbackMask mask);

    /**
    *  @brief
    *    Updates the callback mask of all registered OpenGL functions in the current state, excluding the blacklisted functions
    *
    *  @param[in] mask
    *    The new CallbackMask
    *  @param[in] blackList
    *    The blacklist of functions to exclude in this update
    */
    static void setCallbackMaskExcept(CallbackMask mask, const std::set<std::string> & blackList);

    /**
    *  @brief
    *    Updates the callback mask of all registered OpenGL functions in the current state to include the passed CallbackMask
    *
    *  @param[in] mask
    *    The CallbackMask to include
    */
    static void addCallbackMask(CallbackMask mask);

    /**
    *  @brief
    *    Updates the callback mask of all registered OpenGL functions in the current state to include the passed CallbackMask, excluding the blacklisted functions
    *
    *  @param[in] mask
    *    The CallbackMask to include
    *  @param[in] blackList
    *    The blacklist of functions to exclude in this update
    */
    static void addCallbackMaskExcept(CallbackMask mask, const std::set<std::string> & blackList);

    /**
    *  @brief
    *    Updates the callback mask of all registered OpenGL functions in the current state to exclude the passed CallbackMask
    *
    *  @param[in] mask
    *    The CallbackMask to exclude
    */
    static void removeCallbackMask(CallbackMask mask);

    /**
    *  @brief
    *    Updates the callback mask of all registered OpenGL functions in the current state to exclude the passed CallbackMask, excluding the blacklisted functions
    *
    *  @param[in] mask
    *    The CallbackMask to exclude
    *  @param[in] blackList
    *    The blacklist of functions to exclude in this update
    */
    static void removeCallbackMaskExcept(CallbackMask mask, const std::set<std::string> & blackList);

    /**
    *  @brief
    *    Unresolved callback accessor
    *
    *  @return
    *    The callback to use instead of unresolved function calls
    *
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the After flag to enable the callback
    */
    static SimpleFunctionCallback unresolvedCallback();

    /**
    *  @brief
    *    Updates the unresolved callback that is called upon invocation of an OpenGL function which has no counterpart in the OpenGL driver
    *
    *  @param[in] callback
    *    The callback to use instead of unresolved function calls
    *
    *  @remark
    *    This callback is registered globally across all states.
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the Unresolved flag to enable the callback
    */
    static void setUnresolvedCallback(SimpleFunctionCallback callback);

    /**
    *  @brief
    *    Before callback accessor
    *
    *  @return
    *    The callback to use before an OpenGL function call
    *
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the After flag to enable the callback
    */
    static FunctionCallback beforeCallback();

    /**
    *  @brief
    *    Updates the before callback that is called before the actual OpenGL function invocation
    *
    *  @param[in] callback
    *    The callback to use before an OpenGL function call
    *
    *  @remark
    *    This callback is registered globally across all states.
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the Before flag to enable the callback
    */
    static void setBeforeCallback(FunctionCallback callback);

    /**
    *  @brief
    *    After callback accessor
    *
    *  @return
    *    The callback to use after an OpenGL function call
    *
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the After flag to enable the callback
    */
    static FunctionCallback afterCallback();

    /**
    *  @brief
    *    Updates the after callback that is called after the actual OpenGL function invocation
    *
    *  @param[in] callback
    *    The callback to use after an OpenGL function call
    *
    *  @remark
    *    This callback is registered globally across all states.
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the After flag to enable the callback
    */
    static void setAfterCallback(FunctionCallback callback);

    /**
    *  @brief
    *    Logging callback accessor
    *
    *  @return
    *    The callback to use for logging an OpenGL function call
    *
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the Logging flag to enable the callback
    */
    static FunctionLogCallback logCallback();

    /**
    *  @brief
    *    Updates the logging callback that is called to log the actual OpenGL function invocation
    *
    *  @param[in] callback
    *    The callback to use for logging an OpenGL function call
    *
    *  @remark
    *    This callback is registered globally across all states.
    *
    *  @remark
    *    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the Logging flag to enable the callback
    */
    static void setLogCallback(FunctionLogCallback callback);
    
    /**
    *  @brief
    *    The accessor for all build-in functions
    * 
    *  @return
    *    The list of all build-in functions
    */
    static const array_t & functions();

    /**
    *  @brief
    *    Accessor for additional functions
    *
    *  @return
    *    List of additional functions
    */
    static const std::vector<AbstractFunction *> & additionalFunctions();

    /**
    *  @brief
    *    Get index of current state
    *
    *  @return
    *    Index of current state
    */
    static int currentPos();

    /**
    *  @brief
    *    Get highest state index currently used
    *
    *  @return
    *    Highest state index currently used
    */
    static int maxPos();

    /**
    *  @brief
    *    Query total number of functions
    *
    *  @return
    *    Total number of functions
    */
    static size_t size();

    /**
    *  @brief
    *    Call unresolved callback
    *
    *  @param[in] function
    *    Parameter for callback
    *
    *  @see Binding::unresolvedCallback()
    */
    static void unresolved(const AbstractFunction * function);

    /**
    *  @brief
    *    Call before callback
    *
    *  @param[in] call
    *    Parameter for callback
    *
    *  @see Binding::beforeCallback()
    */
    static void before(const FunctionCall & call);

    /**
    *  @brief
    *    Call after callback
    *
    *  @param[in] call
    *    Parameter for callback
    *
    *  @see Binding::afterCallback()
    */
    static void after(const FunctionCall & call);

    /**
    *  @brief
    *    Call log callback
    *
    *  @param[in] call
    *    Parameter for callback
    *
    *  @see Binding::logCallback()
    */
    static void log(FunctionCall && call);


public:
    static Function<egl::EGLBoolean, egl::EGLenum> BindAPI; ///< Wrapper for eglBindAPI
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, EGLint> BindTexImage; ///< Wrapper for eglBindTexImage
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::wl_display *> BindWaylandDisplayWL; ///< Wrapper for eglBindWaylandDisplayWL
    static Function<egl::EGLBoolean, egl::EGLDisplay, const egl::EGLint *, egl::EGLConfig *, EGLint, egl::EGLint *> ChooseConfig; ///< Wrapper for eglChooseConfig
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSync, const egl::EGLAttrib *> ClientSignalSyncEXT; ///< Wrapper for eglClientSignalSyncEXT
    static Function<EGLint, egl::EGLDisplay, egl::EGLSync, EGLint, egl::EGLTime> ClientWaitSync; ///< Wrapper for eglClientWaitSync
    static Function<EGLint, egl::EGLDisplay, egl::EGLSyncKHR, EGLint, egl::EGLTimeKHR> ClientWaitSyncKHR; ///< Wrapper for eglClientWaitSyncKHR
    static Function<EGLint, egl::EGLSyncNV, EGLint, egl::EGLTimeNV> ClientWaitSyncNV; ///< Wrapper for eglClientWaitSyncNV
    static Function<egl::EGLBoolean, EGLint> CompositorBindTexWindowEXT; ///< Wrapper for eglCompositorBindTexWindowEXT
    static Function<egl::EGLBoolean, EGLint, const egl::EGLint *, EGLint> CompositorSetContextAttributesEXT; ///< Wrapper for eglCompositorSetContextAttributesEXT
    static Function<egl::EGLBoolean, const egl::EGLint *, EGLint> CompositorSetContextListEXT; ///< Wrapper for eglCompositorSetContextListEXT
    static Function<egl::EGLBoolean, EGLint, EGLint, EGLint> CompositorSetSizeEXT; ///< Wrapper for eglCompositorSetSizeEXT
    static Function<egl::EGLBoolean, EGLint, const egl::EGLint *, EGLint> CompositorSetWindowAttributesEXT; ///< Wrapper for eglCompositorSetWindowAttributesEXT
    static Function<egl::EGLBoolean, EGLint, const egl::EGLint *, EGLint> CompositorSetWindowListEXT; ///< Wrapper for eglCompositorSetWindowListEXT
    static Function<egl::EGLBoolean, EGLint, EGLint> CompositorSwapPolicyEXT; ///< Wrapper for eglCompositorSwapPolicyEXT
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, EGLNativePixmapType> CopyBuffers; ///< Wrapper for eglCopyBuffers
    static Function<egl::EGLContext, egl::EGLDisplay, egl::EGLConfig, egl::EGLContext, const egl::EGLint *> CreateContext; ///< Wrapper for eglCreateContext
    static Function<egl::EGLImageKHR, egl::EGLDisplay, const egl::EGLint *> CreateDRMImageMESA; ///< Wrapper for eglCreateDRMImageMESA
    static Function<egl::EGLSyncNV, egl::EGLDisplay, egl::EGLenum, const egl::EGLint *> CreateFenceSyncNV; ///< Wrapper for eglCreateFenceSyncNV
    static Function<egl::EGLImage, egl::EGLDisplay, egl::EGLContext, egl::EGLenum, egl::EGLClientBuffer, const egl::EGLAttrib *> CreateImage; ///< Wrapper for eglCreateImage
    static Function<egl::EGLImageKHR, egl::EGLDisplay, egl::EGLContext, egl::EGLenum, egl::EGLClientBuffer, const egl::EGLint *> CreateImageKHR; ///< Wrapper for eglCreateImageKHR
    static Function<egl::EGLSurface, egl::EGLDisplay, egl::EGLenum, egl::EGLClientBuffer, egl::EGLConfig, const egl::EGLint *> CreatePbufferFromClientBuffer; ///< Wrapper for eglCreatePbufferFromClientBuffer
    static Function<egl::EGLSurface, egl::EGLDisplay, egl::EGLConfig, const egl::EGLint *> CreatePbufferSurface; ///< Wrapper for eglCreatePbufferSurface
    static Function<egl::EGLSurface, egl::EGLDisplay, egl::EGLConfig, EGLNativePixmapType, const egl::EGLint *> CreatePixmapSurface; ///< Wrapper for eglCreatePixmapSurface
    static Function<egl::EGLSurface, egl::EGLDisplay, egl::EGLConfig, egl::EGLClientPixmapHI *> CreatePixmapSurfaceHI; ///< Wrapper for eglCreatePixmapSurfaceHI
    static Function<egl::EGLSurface, egl::EGLDisplay, egl::EGLConfig, void *, const egl::EGLAttrib *> CreatePlatformPixmapSurface; ///< Wrapper for eglCreatePlatformPixmapSurface
    static Function<egl::EGLSurface, egl::EGLDisplay, egl::EGLConfig, void *, const egl::EGLint *> CreatePlatformPixmapSurfaceEXT; ///< Wrapper for eglCreatePlatformPixmapSurfaceEXT
    static Function<egl::EGLSurface, egl::EGLDisplay, egl::EGLConfig, void *, const egl::EGLAttrib *> CreatePlatformWindowSurface; ///< Wrapper for eglCreatePlatformWindowSurface
    static Function<egl::EGLSurface, egl::EGLDisplay, egl::EGLConfig, void *, const egl::EGLint *> CreatePlatformWindowSurfaceEXT; ///< Wrapper for eglCreatePlatformWindowSurfaceEXT
    static Function<egl::EGLStreamKHR, egl::EGLDisplay, const egl::EGLAttrib *> CreateStreamAttribKHR; ///< Wrapper for eglCreateStreamAttribKHR
    static Function<egl::EGLStreamKHR, egl::EGLDisplay, egl::EGLNativeFileDescriptorKHR> CreateStreamFromFileDescriptorKHR; ///< Wrapper for eglCreateStreamFromFileDescriptorKHR
    static Function<egl::EGLStreamKHR, egl::EGLDisplay, const egl::EGLint *> CreateStreamKHR; ///< Wrapper for eglCreateStreamKHR
    static Function<egl::EGLSurface, egl::EGLDisplay, egl::EGLConfig, egl::EGLStreamKHR, const egl::EGLint *> CreateStreamProducerSurfaceKHR; ///< Wrapper for eglCreateStreamProducerSurfaceKHR
    static Function<egl::EGLSyncKHR, egl::EGLDisplay, egl::EGLStreamKHR, egl::EGLenum, const egl::EGLint *> CreateStreamSyncNV; ///< Wrapper for eglCreateStreamSyncNV
    static Function<egl::EGLSync, egl::EGLDisplay, egl::EGLenum, const egl::EGLAttrib *> CreateSync; ///< Wrapper for eglCreateSync
    static Function<egl::EGLSyncKHR, egl::EGLDisplay, egl::EGLenum, const egl::EGLAttribKHR *> CreateSync64KHR; ///< Wrapper for eglCreateSync64KHR
    static Function<egl::EGLSyncKHR, egl::EGLDisplay, egl::EGLenum, const egl::EGLint *> CreateSyncKHR; ///< Wrapper for eglCreateSyncKHR
    static Function<egl::wl_buffer *, egl::EGLDisplay, egl::EGLImageKHR> CreateWaylandBufferFromImageWL; ///< Wrapper for eglCreateWaylandBufferFromImageWL
    static Function<egl::EGLSurface, egl::EGLDisplay, egl::EGLConfig, EGLNativeWindowType, const egl::EGLint *> CreateWindowSurface; ///< Wrapper for eglCreateWindowSurface
    static Function<EGLint, egl::EGLDEBUGPROCKHR, const egl::EGLAttrib *> DebugMessageControlKHR; ///< Wrapper for eglDebugMessageControlKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLContext> DestroyContext; ///< Wrapper for eglDestroyContext
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLImage> DestroyImage; ///< Wrapper for eglDestroyImage
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLImageKHR> DestroyImageKHR; ///< Wrapper for eglDestroyImageKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR> DestroyStreamKHR; ///< Wrapper for eglDestroyStreamKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface> DestroySurface; ///< Wrapper for eglDestroySurface
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSync> DestroySync; ///< Wrapper for eglDestroySync
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSyncKHR> DestroySyncKHR; ///< Wrapper for eglDestroySyncKHR
    static Function<egl::EGLBoolean, egl::EGLSyncNV> DestroySyncNV; ///< Wrapper for eglDestroySyncNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLImageKHR, int *, egl::EGLint *, egl::EGLint *> ExportDMABUFImageMESA; ///< Wrapper for eglExportDMABUFImageMESA
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLImageKHR, int *, int *, egl::EGLuint64KHR *> ExportDMABUFImageQueryMESA; ///< Wrapper for eglExportDMABUFImageQueryMESA
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLImageKHR, egl::EGLint *, egl::EGLint *, egl::EGLint *> ExportDRMImageMESA; ///< Wrapper for eglExportDRMImageMESA
    static Function<egl::EGLBoolean, egl::EGLSyncNV> FenceNV; ///< Wrapper for eglFenceNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLConfig, EGLint, egl::EGLint *> GetConfigAttrib; ///< Wrapper for eglGetConfigAttrib
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLConfig *, EGLint, egl::EGLint *> GetConfigs; ///< Wrapper for eglGetConfigs
    static Function<egl::EGLContext> GetCurrentContext; ///< Wrapper for eglGetCurrentContext
    static Function<egl::EGLDisplay> GetCurrentDisplay; ///< Wrapper for eglGetCurrentDisplay
    static Function<egl::EGLSurface, EGLint> GetCurrentSurface; ///< Wrapper for eglGetCurrentSurface
    static Function<egl::EGLDisplay, EGLNativeDisplayType> GetDisplay; ///< Wrapper for eglGetDisplay
    static Function<char *, egl::EGLDisplay> GetDisplayDriverConfig; ///< Wrapper for eglGetDisplayDriverConfig
    static Function<const char *, egl::EGLDisplay> GetDisplayDriverName; ///< Wrapper for eglGetDisplayDriverName
    static Function<EGLint> GetError; ///< Wrapper for eglGetError
    static Function<egl::EGLBoolean, egl::EGLDisplay, const egl::EGLAttrib *, egl::EGLOutputLayerEXT *, EGLint, egl::EGLint *> GetOutputLayersEXT; ///< Wrapper for eglGetOutputLayersEXT
    static Function<egl::EGLBoolean, egl::EGLDisplay, const egl::EGLAttrib *, egl::EGLOutputPortEXT *, EGLint, egl::EGLint *> GetOutputPortsEXT; ///< Wrapper for eglGetOutputPortsEXT
    static Function<egl::EGLDisplay, egl::EGLenum, void *, const egl::EGLAttrib *> GetPlatformDisplay; ///< Wrapper for eglGetPlatformDisplay
    static Function<egl::EGLDisplay, egl::EGLenum, void *, const egl::EGLint *> GetPlatformDisplayEXT; ///< Wrapper for eglGetPlatformDisplayEXT
    static Function<egl::__eglMustCastToProperFunctionPointerType, const char *> GetProcAddress; ///< Wrapper for eglGetProcAddress
    static Function<egl::EGLNativeFileDescriptorKHR, egl::EGLDisplay, egl::EGLStreamKHR> GetStreamFileDescriptorKHR; ///< Wrapper for eglGetStreamFileDescriptorKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSync, EGLint, egl::EGLAttrib *> GetSyncAttrib; ///< Wrapper for eglGetSyncAttrib
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSyncKHR, EGLint, egl::EGLint *> GetSyncAttribKHR; ///< Wrapper for eglGetSyncAttribKHR
    static Function<egl::EGLBoolean, egl::EGLSyncNV, EGLint, egl::EGLint *> GetSyncAttribNV; ///< Wrapper for eglGetSyncAttribNV
    static Function<egl::EGLuint64NV> GetSystemTimeFrequencyNV; ///< Wrapper for eglGetSystemTimeFrequencyNV
    static Function<egl::EGLuint64NV> GetSystemTimeNV; ///< Wrapper for eglGetSystemTimeNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLint *, egl::EGLint *> Initialize; ///< Wrapper for eglInitialize
    static Function<EGLint, egl::EGLDisplay, egl::EGLenum, egl::EGLObjectKHR, egl::EGLLabelKHR> LabelObjectKHR; ///< Wrapper for eglLabelObjectKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, const egl::EGLint *> LockSurfaceKHR; ///< Wrapper for eglLockSurfaceKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, egl::EGLSurface, egl::EGLContext> MakeCurrent; ///< Wrapper for eglMakeCurrent
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLOutputLayerEXT, EGLint, egl::EGLAttrib> OutputLayerAttribEXT; ///< Wrapper for eglOutputLayerAttribEXT
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLOutputPortEXT, EGLint, egl::EGLAttrib> OutputPortAttribEXT; ///< Wrapper for eglOutputPortAttribEXT
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, EGLint, EGLint, EGLint, EGLint> PostSubBufferNV; ///< Wrapper for eglPostSubBufferNV
    static Function<egl::EGLenum> QueryAPI; ///< Wrapper for eglQueryAPI
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLContext, EGLint, egl::EGLint *> QueryContext; ///< Wrapper for eglQueryContext
    static Function<egl::EGLBoolean, EGLint, egl::EGLAttrib *> QueryDebugKHR; ///< Wrapper for eglQueryDebugKHR
    static Function<egl::EGLBoolean, egl::EGLDeviceEXT, EGLint, egl::EGLAttrib *> QueryDeviceAttribEXT; ///< Wrapper for eglQueryDeviceAttribEXT
    static Function<egl::EGLBoolean, EGLint, egl::EGLDeviceEXT *, egl::EGLint *> QueryDevicesEXT; ///< Wrapper for eglQueryDevicesEXT
    static Function<const char *, egl::EGLDeviceEXT, EGLint> QueryDeviceStringEXT; ///< Wrapper for eglQueryDeviceStringEXT
    static Function<egl::EGLBoolean, egl::EGLDisplay, EGLint, egl::EGLAttrib *> QueryDisplayAttribEXT; ///< Wrapper for eglQueryDisplayAttribEXT
    static Function<egl::EGLBoolean, egl::EGLDisplay, EGLint, egl::EGLAttrib *> QueryDisplayAttribKHR; ///< Wrapper for eglQueryDisplayAttribKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, EGLint, egl::EGLAttrib *> QueryDisplayAttribNV; ///< Wrapper for eglQueryDisplayAttribNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, EGLint, egl::EGLint *, egl::EGLint *> QueryDmaBufFormatsEXT; ///< Wrapper for eglQueryDmaBufFormatsEXT
    static Function<egl::EGLBoolean, egl::EGLDisplay, EGLint, EGLint, egl::EGLuint64KHR *, egl::EGLBoolean *, egl::EGLint *> QueryDmaBufModifiersEXT; ///< Wrapper for eglQueryDmaBufModifiersEXT
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLNativeDisplayType *> QueryNativeDisplayNV; ///< Wrapper for eglQueryNativeDisplayNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, egl::EGLNativePixmapType *> QueryNativePixmapNV; ///< Wrapper for eglQueryNativePixmapNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, egl::EGLNativeWindowType *> QueryNativeWindowNV; ///< Wrapper for eglQueryNativeWindowNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLOutputLayerEXT, EGLint, egl::EGLAttrib *> QueryOutputLayerAttribEXT; ///< Wrapper for eglQueryOutputLayerAttribEXT
    static Function<const char *, egl::EGLDisplay, egl::EGLOutputLayerEXT, EGLint> QueryOutputLayerStringEXT; ///< Wrapper for eglQueryOutputLayerStringEXT
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLOutputPortEXT, EGLint, egl::EGLAttrib *> QueryOutputPortAttribEXT; ///< Wrapper for eglQueryOutputPortAttribEXT
    static Function<const char *, egl::EGLDisplay, egl::EGLOutputPortEXT, EGLint> QueryOutputPortStringEXT; ///< Wrapper for eglQueryOutputPortStringEXT
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR, egl::EGLenum, egl::EGLAttrib *> QueryStreamAttribKHR; ///< Wrapper for eglQueryStreamAttribKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR, egl::EGLenum, egl::EGLint *> QueryStreamKHR; ///< Wrapper for eglQueryStreamKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR, egl::EGLenum, EGLint, EGLint, EGLint, void *> QueryStreamMetadataNV; ///< Wrapper for eglQueryStreamMetadataNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR, egl::EGLenum, egl::EGLTimeKHR *> QueryStreamTimeKHR; ///< Wrapper for eglQueryStreamTimeKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR, egl::EGLenum, egl::EGLuint64KHR *> QueryStreamu64KHR; ///< Wrapper for eglQueryStreamu64KHR
    static Function<const char *, egl::EGLDisplay, EGLint> QueryString; ///< Wrapper for eglQueryString
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, EGLint, egl::EGLint *> QuerySurface; ///< Wrapper for eglQuerySurface
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, EGLint, egl::EGLAttribKHR *> QuerySurface64KHR; ///< Wrapper for eglQuerySurface64KHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, EGLint, void **> QuerySurfacePointerANGLE; ///< Wrapper for eglQuerySurfacePointerANGLE
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::wl_resource *, EGLint, egl::EGLint *> QueryWaylandBufferWL; ///< Wrapper for eglQueryWaylandBufferWL
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, EGLint> ReleaseTexImage; ///< Wrapper for eglReleaseTexImage
    static Function<egl::EGLBoolean> ReleaseThread; ///< Wrapper for eglReleaseThread
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR> ResetStreamNV; ///< Wrapper for eglResetStreamNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, egl::EGLint *, EGLint> SetDamageRegionKHR; ///< Wrapper for eglSetDamageRegionKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR, egl::EGLenum, egl::EGLAttrib> SetStreamAttribKHR; ///< Wrapper for eglSetStreamAttribKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR, EGLint, EGLint, EGLint, const void *> SetStreamMetadataNV; ///< Wrapper for eglSetStreamMetadataNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSyncKHR, egl::EGLenum> SignalSyncKHR; ///< Wrapper for eglSignalSyncKHR
    static Function<egl::EGLBoolean, egl::EGLSyncNV, egl::EGLenum> SignalSyncNV; ///< Wrapper for eglSignalSyncNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR, egl::EGLenum, EGLint> StreamAttribKHR; ///< Wrapper for eglStreamAttribKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR, const egl::EGLAttrib *> StreamConsumerAcquireAttribKHR; ///< Wrapper for eglStreamConsumerAcquireAttribKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR> StreamConsumerAcquireKHR; ///< Wrapper for eglStreamConsumerAcquireKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR, const egl::EGLAttrib *> StreamConsumerGLTextureExternalAttribsNV; ///< Wrapper for eglStreamConsumerGLTextureExternalAttribsNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR> StreamConsumerGLTextureExternalKHR; ///< Wrapper for eglStreamConsumerGLTextureExternalKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR, egl::EGLOutputLayerEXT> StreamConsumerOutputEXT; ///< Wrapper for eglStreamConsumerOutputEXT
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR, const egl::EGLAttrib *> StreamConsumerReleaseAttribKHR; ///< Wrapper for eglStreamConsumerReleaseAttribKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR> StreamConsumerReleaseKHR; ///< Wrapper for eglStreamConsumerReleaseKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLStreamKHR> StreamFlushNV; ///< Wrapper for eglStreamFlushNV
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, EGLint, EGLint> SurfaceAttrib; ///< Wrapper for eglSurfaceAttrib
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface> SwapBuffers; ///< Wrapper for eglSwapBuffers
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, EGLint, const egl::EGLint *> SwapBuffersRegion2NOK; ///< Wrapper for eglSwapBuffersRegion2NOK
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, EGLint, const egl::EGLint *> SwapBuffersRegionNOK; ///< Wrapper for eglSwapBuffersRegionNOK
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, const egl::EGLint *, EGLint> SwapBuffersWithDamageEXT; ///< Wrapper for eglSwapBuffersWithDamageEXT
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface, const egl::EGLint *, EGLint> SwapBuffersWithDamageKHR; ///< Wrapper for eglSwapBuffersWithDamageKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, EGLint> SwapInterval; ///< Wrapper for eglSwapInterval
    static Function<egl::EGLBoolean, egl::EGLDisplay> Terminate; ///< Wrapper for eglTerminate
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::wl_display *> UnbindWaylandDisplayWL; ///< Wrapper for eglUnbindWaylandDisplayWL
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSurface> UnlockSurfaceKHR; ///< Wrapper for eglUnlockSurfaceKHR
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSync, const egl::EGLAttrib *> UnsignalSyncEXT; ///< Wrapper for eglUnsignalSyncEXT
    static Function<egl::EGLBoolean> WaitClient; ///< Wrapper for eglWaitClient
    static Function<egl::EGLBoolean> WaitGL; ///< Wrapper for eglWaitGL
    static Function<egl::EGLBoolean, EGLint> WaitNative; ///< Wrapper for eglWaitNative
    static Function<egl::EGLBoolean, egl::EGLDisplay, egl::EGLSync, EGLint> WaitSync; ///< Wrapper for eglWaitSync
    static Function<EGLint, egl::EGLDisplay, egl::EGLSyncKHR, EGLint> WaitSyncKHR; ///< Wrapper for eglWaitSyncKHR


protected:
    /**
    *  @brief
    *    Provide an additional State
    *
    *  @param[in] pos
    *    Index of new State
    */
    static void provideState(int pos);

    /**
    *  @brief
    *    Neglect a previously provided state
    *
    *  @param[in] pos
    *    Index of State to neglect
    */
    static void neglectState(int pos);

    /**
    *  @brief
    *    Set current State
    *
    *  @param[in] pos
    *    Index of State
    */
    static void setStatePos(int pos);


protected:
    static const array_t s_functions;                                       ///< The list of all build-in functions
    static int & s_maxPos();                                                ///< Maximum State index in use
    static std::vector<AbstractFunction *> & s_additionalFunctions();       ///< List of additional OpenGL fucntions
    static std::vector<ContextSwitchCallback> & s_contextSwitchCallbacks(); ///< List of callbacks for context switch
    static SimpleFunctionCallback & s_unresolvedCallback();                 ///< Callback for unresolved functions
    static FunctionCallback & s_beforeCallback();                           ///< Callback for before function call
    static FunctionCallback & s_afterCallback();                            ///< Callback for after function call
    static FunctionLogCallback & s_logCallback();                           ///< Callback for logging a function call
    static int & s_pos();                                                   ///< Position of current State
    static ContextHandle & s_context();                                     ///< Handle of current context
    static eglbinding::GetProcAddress & s_getProcAddress();                  ///< Current address of function resolution method
    static std_boost::recursive_mutex & s_mutex();                          ///< Mutex
    static std::unordered_map<ContextHandle, int> & s_bindings();           ///< Map (handle->position) of initialized contexts
    static eglbinding::GetProcAddress & s_firstGetProcAddress();             ///< First address of function resolution method
};


} // namespace eglbinding