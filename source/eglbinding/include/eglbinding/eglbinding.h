
#pragma once


#include <set>
#include <string>
#include <vector>
#include <functional>

#include <eglbinding/eglbinding_api.h>
#include <eglbinding/eglbinding_features.h>

#include <eglbinding/ContextHandle.h>
#include <eglbinding/CallbackMask.h>
#include <eglbinding/ProcAddress.h>


namespace eglbinding
{


class AbstractFunction;
class FunctionCall;


using SimpleFunctionCallback = std::function<void(const AbstractFunction &)>; ///< The signature of the unresolved callback
using FunctionCallback = std::function<void(const FunctionCall &)>;           ///< The signature of the before and after callbacks
using FunctionLogCallback = std::function<void(FunctionCall *)>;              ///< The signature of the log callback
using ContextSwitchCallback = std::function<void(ContextHandle)>;             ///< The signature of the context switch callback

/**
*  @brief
*    Initializes the binding for the current active OpenGL context
*
*  @param[in] functionPointerResolver
*    A function pointer to resolve binding functions for this context.
*    If `nullptr` is passed, `eglbinding::getProcAddress` is used for convenience.
*  @param[in] resolveFunctions (optional)
*    Whether to resolve function pointers lazily (\a resolveFunctions = `false`) or immediately
*
*  @remark
*    This function is a convenience interface for applications that use only one OpenGL context.
*    If you want to use more than one context, use explicit context identifiers and the dedicated
*    Initialization interface initialize(ContextHandle, glbinding::GetProcAddress, bool, bool).
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
EGLBINDING_API void initialize(eglbinding::GetProcAddress functionPointerResolver, bool resolveFunctions = true);

/**
*  @brief
*    Initializes the binding for the current active OpenGL context
*
*  @param[in] context
*    The context handle of the context to initialize
*  @param[in] functionPointerResolver
*    A function pointer to resolve binding functions for this context
*  @param[in] useContext
*    Whether to set the context active (\a useContext = `true`) after the initialization
*  @param[in] resolveFunctions (optional)
*    Whether to resolve function pointers lazily (\a resolveFunctions = `false`) or immediately
*
*  @remark
*    A functionPointerResolver with value 'nullptr' will get initialized with the function
*    pointer from the initial thread.
*/
EGLBINDING_API void initialize(ContextHandle context, eglbinding::GetProcAddress functionPointerResolver, bool useContext = true, bool resolveFunctions = true);

/**
*  @brief
*    Update the current context state in eglbinding
*
*  @remark
*    This function queries the driver for the current OpenGL context
*/
EGLBINDING_API void useCurrentContext();

/**
*  @brief
*    Update the current context state in eglbinding
*
*  @param[in] context
*    The context handle of the context to set current
*/
EGLBINDING_API void useContext(ContextHandle context);

/**
*  @brief
*    Removes the current context from the state of eglbinding
*
*  @remark
*    This function queries the driver for the current OpenGL context
*/
EGLBINDING_API void releaseCurrentContext();

/**
*  @brief
*    Removes the current context from the state of eglbinding
*
*  @param[in] context
*    The context handle of the context to remove
*/
EGLBINDING_API void releaseContext(ContextHandle context);

/**
*  @brief
*    Registers an additional function for the additional features
*
*  @param[in] function
*    The function to register
*
*  @remark
*    The additional features are callbacks, and used in multi-context environments
*/
EGLBINDING_API void registerAdditionalFunction(AbstractFunction * function);

/**
*  @brief
*    Resolve a single function pointer by given name
*
*  @param[in] name
*    The name of the function
*/
EGLBINDING_API ProcAddress resolveFunction(const char * name);

/**
*  @brief
*    Resolves the funtion pointers of all registered OpenGL functions immediately for the current context
*/
EGLBINDING_API void resolveFunctions();

/**
*  @brief
*    Updates the callback mask of all registered OpenGL functions in the current state
*
*  @param[in] mask
*    The new CallbackMask
*/
EGLBINDING_API void setCallbackMask(CallbackMask mask);

/**
*  @brief
*    Updates the callback mask of all registered OpenGL functions in the current state, excluding the blacklisted functions
*
*  @param[in] mask
*    The new CallbackMask
*  @param[in] blackList
*    The blacklist of functions to exclude in this update
*/
EGLBINDING_API void setCallbackMaskExcept(CallbackMask mask, const std::set<std::string> & blackList);

/**
*  @brief
*    Updates the callback mask of all registered OpenGL functions in the current state to include the passed CallbackMask
*
*  @param[in] mask
*    The CallbackMask to include
*/
EGLBINDING_API void addCallbackMask(CallbackMask mask);

/**
*  @brief
*    Updates the callback mask of all registered OpenGL functions in the current state to include the passed CallbackMask, excluding the blacklisted functions
*
*  @param[in] mask
*    The CallbackMask to include
*  @param[in] blackList
*    The blacklist of functions to exclude in this update
*/
EGLBINDING_API void addCallbackMaskExcept(CallbackMask mask, const std::set<std::string> & blackList);

/**
*  @brief
*    Updates the callback mask of all registered OpenGL functions in the current state to exclude the passed CallbackMask
*
*  @param[in] mask
*    The CallbackMask to exclude
*/
EGLBINDING_API void removeCallbackMask(CallbackMask mask);

/**
*  @brief
*    Updates the callback mask of all registered OpenGL functions in the current state to exclude the passed CallbackMask, excluding the blacklisted functions
*
*  @param[in] mask
*    The CallbackMask to exclude
*  @param[in] blackList
*    The blacklist of functions to exclude in this update
*/
EGLBINDING_API void removeCallbackMaskExcept(CallbackMask mask, const std::set<std::string> & blackList);

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
EGLBINDING_API SimpleFunctionCallback unresolvedCallback();

/**
*  @brief
*    Updates the unresolved callback that is called upon invocation of an OpenGL function which have no counterpart in the OpenGL driver
*
*  @param[in] callback
*    The callback to use instead of unresolved function calls
*
*  @remark
*    This callback is registered globally across all states.
*
*  @remark
*    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the Unresolved flag to enable the callback
*/
EGLBINDING_API void setUnresolvedCallback(SimpleFunctionCallback callback);

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
EGLBINDING_API FunctionCallback beforeCallback();

/**
*  @brief
*    Updates the before callback that is called before the actual OpenGL function invocation
*
*  @param[in] callback
*    The callback to use before an OpenGL function call
*
*  @remark
*    This callback is registered globally across all states.
*
*  @remark
*    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the Before flag to enable the callback
*/
EGLBINDING_API void setBeforeCallback(FunctionCallback callback);

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
EGLBINDING_API FunctionCallback afterCallback();

/**
*  @brief
*    Updates the after callback that is called after the actual OpenGL function invocation
*
*  @param[in] callback
*    The callback to use after an OpenGL function call
*
*  @remark
*    This callback is registered globally across all states.
*
*  @remark
*    Keep in mind that in addition to a registered callback, the callback mask of the current Function has to include the After flag to enable the callback
*/
EGLBINDING_API void setAfterCallback(FunctionCallback callback);

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
EGLBINDING_API FunctionLogCallback logCallback();

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
EGLBINDING_API void setLogCallback(FunctionLogCallback callback);

/**
*  @brief
*    Registers an additional callback that gets called each time the context is switched using the useContext method
*
*  @remark
*    There may be multiple context switch callbacks registered at once
*/
EGLBINDING_API void addContextSwitchCallback(ContextSwitchCallback callback);


} // namespace eglbinding