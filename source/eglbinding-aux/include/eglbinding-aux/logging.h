
#pragma once


#include <set>

#include <eglbinding/FunctionCall.h>

#include <eglbinding-aux/eglbinding-aux_api.h>


namespace eglbinding { namespace aux
{


/**
*  @brief
*    The type of an entry in the log buffer is a FunctionCall *
*/
using LogEntry = FunctionCall *;


/**
*  @brief
*    Resizes the global log buffer
*
*  @param[in] newSize
*    The new size of the buffer
*/
EGLBINDING_AUX_API void resize(unsigned int newSize);

/**
*  @brief
*    Start logging to a file globally
*
*  @remarks
*    This function generates a file name and uses this as output
*/
EGLBINDING_AUX_API void start();

/**
*  @brief
*    Start logging to a file globally
*
*  @param[in] filepath
*    The file to store the log into
*/
EGLBINDING_AUX_API void start(const std::string & filepath);

/**
*  @brief
*    Start logging to a file globally, except for blacklisted functions
*
*  @param blackList
*    The blacklist of function names
*
*  @remarks
*    This function generates a file name and uses this as output
*/
EGLBINDING_AUX_API void startExcept(const std::set<std::string> & blackList);

/**
*  @brief
*    Start logging to a file globally, except for blacklisted functions
*
*  @param[in] filepath
*    The file to store the log into
*  @param[in] blackList
*    The blacklist of function names
*/
EGLBINDING_AUX_API void startExcept(const std::string & filepath, const std::set<std::string> & blackList);

/**
*  @brief
*    Stops logging and flushing log file
*/
EGLBINDING_AUX_API void stop();

/**
*  @brief
*    Pauses logging for later stopping or resuming
*
*  @remarks
*    While logging is started but paused, no OpenGL function calls are considered for the log file
*/
EGLBINDING_AUX_API void pause();

/**
*  @brief
*    Resumes paused logging
*/
EGLBINDING_AUX_API void resume();

/**
*  @brief
*    Add a function call to the log
*
*  @remarks
*    This function is intended to get used by glbinding and not by a user of glbinding
*/
EGLBINDING_AUX_API void log(FunctionCall && call);


} } // namespace eglbinding::aux
