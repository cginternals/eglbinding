
#pragma once


#include <set>
#include <vector>
#include <functional>

#include <eglbinding/eglbinding_api.h>
#include <eglbinding/eglbinding_features.h>

#include <eglbinding/CallbackMask.h>
#include <eglbinding/ProcAddress.h>


namespace eglbinding
{


class AbstractFunction;
class FunctionCall;


using SimpleFunctionCallback = std::function<void(const AbstractFunction &)>;
using FunctionCallback = std::function<void(const FunctionCall &)>;
using FunctionLogCallback = std::function<void(FunctionCall *)>;

EGLBINDING_API void initialize(eglbinding::GetProcAddress functionPointerResolver, bool resolveFunctions = true);
EGLBINDING_API void registerAdditionalFunction(AbstractFunction * function);
EGLBINDING_API ProcAddress resolveFunction(const char * name);
EGLBINDING_API void resolveFunctions();

EGLBINDING_API void setCallbackMask(CallbackMask mask);
EGLBINDING_API void setCallbackMaskExcept(CallbackMask mask, const std::set<std::string> & blackList);
EGLBINDING_API void addCallbackMask(CallbackMask mask);
EGLBINDING_API void addCallbackMaskExcept(CallbackMask mask, const std::set<std::string> & blackList);
EGLBINDING_API void removeCallbackMask(CallbackMask mask);
EGLBINDING_API void removeCallbackMaskExcept(CallbackMask mask, const std::set<std::string> & blackList);
EGLBINDING_API SimpleFunctionCallback unresolvedCallback();
EGLBINDING_API void setUnresolvedCallback(SimpleFunctionCallback callback);
EGLBINDING_API FunctionCallback beforeCallback();
EGLBINDING_API void setBeforeCallback(FunctionCallback callback);
EGLBINDING_API FunctionCallback afterCallback();
EGLBINDING_API void setAfterCallback(FunctionCallback callback);
EGLBINDING_API FunctionLogCallback logCallback();
EGLBINDING_API void setLogCallback(FunctionLogCallback callback);


} // namespace eglbinding
