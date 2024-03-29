
#pragma once


#include <string>
#include <utility>
#include <vector>
#include <set>
#include <cstdint>

#include <eglbinding-aux/eglbinding-aux_api.h>
#include <eglbinding-aux/eglbinding-aux_features.h>

#include <eglbinding/egl/types.h>
#include <eglbinding/AbstractFunction.h>


namespace eglbinding
{


class Version;


namespace aux
{


/**
*  @brief
*    Provisioning of meta information about OpenGL extensions, functions and conversion of strings and symbols of the OpenGL API
*/
class EGLBINDING_AUX_API Meta
{
public:
    /**
    *  @brief
    *    Deleted Constructor as all functions are static
    */
    Meta() = delete;

    /**
    *  @brief
    *    Returns the revision of the parsed egl.xml file
    *
    *  @return
    *    The revision of the parsed egl.xml file
    */
    static int eglRevision();

    /**
    *  @brief
    *    Converts a string into a bitfield symbol
    *
    *  @param[in] bitfield
    *     The string representation of the bitfield
    *
    *  @return
    *    The symbol identified through the bitfield string, 0 if failed
    */
    static egl::EGLbitfield getBitfield(const std::string & bitfield);
    
    /**
    *  @brief
    *    Returns the list of all bitfields known by the egl.xml
    *
    *  @return
    *    The list of all bitfields known by the egl.xml
    */
    static std::vector<egl::EGLbitfield> bitfields();

    /**
    *  @brief
    *    Converts a EGLenum to a string
    *
    *  @param[in] eglenum
    *    The enum to convert
    *
    *  @return
    *    A string representation of the GLenum symbol name
    *
    *  @remark
    *    Beware, that some enums in the OpenGL API have different symbol names but identical enum values and that this function cannot differentiate between them
    */
    // static const std::string & getString(egl::EGLenum eglenum);
    
    /**
    *  @brief
    *    Converts a string to an enum symbol
    *
    *  @param[in] eglenum
    *    The string representation of the enum
    *
    *  @return
    *    The symbol identified through the enum string, 0 if failed
    */
    static egl::EGLenum getEnum(const std::string & eglenum);
    
    /**
    *  @brief
    *    Returns the list of all enums known by the egl.xml
    *
    *  @return
    *    The list of all enums known by the egl.xml
    */
    static std::set<egl::EGLenum> enums();

    /**
    *  @brief
    *    Converts a EGLBoolean to a string
    *
    *  @param[in] eglboolean
    *    The boolean to convert
    *
    *  @return
    *    A string representation of the EGLBoolean symbol name
    *
    *  @remark
    *    Can either be `EGL_TRUE` or `EGL_FALSE`
    */
    static const std::string & getString(const egl::EGLBoolean & eglboolean);
    
    /**
    *  @brief
    *    Converts a string to a EGLBoolean symbol
    *
    *  @param[in] boolean
    *    The string representation of the EGLBoolean
    *
    *  @return
    *    The symbol identified through the boolean string, `EGL_FALSE` if failed
    */
    static egl::EGLBoolean getBoolean(const std::string & boolean);

    /**
    *  @brief
    *    Converts a EGLextension to its string representation
    *
    *  @param[in] eglextension
    *    The extension to convert
    *
    *  @return
    *    The string representation of the extension
    */
    static const std::string & getString(egl::EGLextension eglextension);
    
    /**
    *  @brief
    *    Converts a string to an EGLextension
    *
    *  @param[in] extension
    *    The string representation of the extension
    *
    *  @return
    *    The symbol identified through the extension string, 'UNKNOWN' if failed
    */
    static egl::EGLextension getExtension(const std::string & extension);

    /**
    *  @brief
    *    Returns the set of all extensions known by the egl.xml
    *
    *  @return
    *    The set of all extensions known by the egl.xml
    */
    static std::set<egl::EGLextension> extensions();
    
    /**
    *  @brief
    *    Returns the set of extensions that are required for by the given version
    *
    *  @param[in] version
    *    The version/feature to return the required extensions for.
    *    If an null version is given, all extensions that have no
    *    version/feature associated are returned instead
    *
    *  @return
    *    The set of extensions that should be supported for the given version.
    *    All non-versioned extensions can be queried by providing the null version
    */
    static const std::set<egl::EGLextension> extensions(const Version & version);

    /**
    *  @brief
    *    Returns the list of extensions that are requiring a function
    *
    *  @param[in] function
    *    The name of the function, including the 'egl' prefix
    *
    *  @return
    *    The set of extensions that are requiring a function
    */
    static const std::set<egl::EGLextension> extensions(const std::string & eglfunction);

    /**
    *  @brief
    *    Returns the list of features that are requiring a function
    *
    *  @param[in] function
    *    The name of the function, including the 'egl' prefix
    *
    *  @return
    *    The set of features that are requiring a function
    */
    static const std::set<Version> versions(const std::string & eglfunction);
    
    /**
    *  @brief
    *    Returns the set of functions that are required for the version
    *
    *  @param[in] version
    *    The version to return the required functions for
    *
    *  @return
    *    The set of functions that are required for the version
    *
    *  @remark
    *    This is exclusive (preceeding versions are ignored)
    */
    static const std::set<AbstractFunction *> functions(const Version & version);

    /**
    *  @brief
    *    Returns the set of functions that are required for the extension
    *
    *  @param[in] extension
    *    The extension to return the required functions for
    *
    *  @return
    *    The set of functions that are required for the extension
    */
    static const std::set<AbstractFunction *> functions(egl::EGLextension extension);

    /**
    *  @brief
    *    Returns the first Version (Feature) that required the extension
    *
    *  @param[in] eglextension
    *    The extension
    *
    *  @return
    *    The first Version (Feature) that required the extension
    */
    static const Version & version(egl::EGLextension eglextension);
    
    /**
    *  @brief
    *    Returns the list of all Versions (Features) known by the egl.xml
    *
    *  @return
    *    The list of all Versions (Features) known by the egl.xml
    */
    static const std::set<Version> & versions();

    /**
    *  @brief
    *    Convert bitfield to symbol name string representation
    *
    *  @param[in] bitfield
    *    The bitfield value
    *
    *  @return
    *    The string representation of the value
    */
    static const std::string & getString(egl::EGLContextFlagMask eglbitfield);

    /**
    *  @brief
    *    Convert bitfield to symbol name string representation
    *
    *  @param[in] bitfield
    *    The bitfield value
    *
    *  @return
    *    The string representation of the value
    */
    static const std::string & getString(egl::EGLContextProfileMask eglbitfield);

    /**
    *  @brief
    *    Convert bitfield to symbol name string representation
    *
    *  @param[in] bitfield
    *    The bitfield value
    *
    *  @return
    *    The string representation of the value
    */
    static const std::string & getString(egl::EGLDRMBufferUseMESAMask eglbitfield);

    /**
    *  @brief
    *    Convert bitfield to symbol name string representation
    *
    *  @param[in] bitfield
    *    The bitfield value
    *
    *  @return
    *    The string representation of the value
    */
    static const std::string & getString(egl::EGLLockUsageHintKHRMask eglbitfield);

    /**
    *  @brief
    *    Convert bitfield to symbol name string representation
    *
    *  @param[in] bitfield
    *    The bitfield value
    *
    *  @return
    *    The string representation of the value
    */
    static const std::string & getString(egl::EGLRenderableTypeMask eglbitfield);

    /**
    *  @brief
    *    Convert bitfield to symbol name string representation
    *
    *  @param[in] bitfield
    *    The bitfield value
    *
    *  @return
    *    The string representation of the value
    */
    static const std::string & getString(egl::EGLSurfaceTypeMask eglbitfield);

    /**
    *  @brief
    *    Convert bitfield to symbol name string representation
    *
    *  @param[in] bitfield
    *    The bitfield value
    *
    *  @return
    *    The string representation of the value
    */
    static const std::string & getString(egl::EGLSyncFlagsKHR eglbitfield);

    /**
    *  @brief
    *    Convert bitfield to symbol name string representation
    *
    *  @param[in] bitfield
    *    The bitfield value
    *
    *  @return
    *    The string representation of the value
    */
    static const std::string & getString(egl::UnusedMask eglbitfield);


    /**
    *  @brief
    *    Convert enum to symbol name string representation
    *
    *  @param[in] enum
    *    The enum value
    *
    *  @return
    *    The shortest string representation of the value
    *
    *  @remark
    *    Beware, that some enums in the API have different symbol names but identical enum values and that this function cannot differentiate between them
    */
    static const std::string & getString(egl::EGLenum eglenum);

    /**
    *  @brief
    *    Convert enum to symbol name string representation
    *
    *  @param[in] enum
    *    The enum value
    *
    *  @return
    *    All string representations of the value
    */
    static std::vector<std::string> getStrings(egl::EGLenum eglenum);


private:
    /**
    *  @brief
    *    Returns the bucket index of an identifier used for the actual lookup into the compile-time maps
    *
    *  @param[in] identifier
    *    The identifier for the bucket lookup
    *
    *  @param[in] prefixLength
    *    The length of the prefix (e.g., 'egl' or 'EGL_') to omit to get the actual first character of the identifier
    *
    *  @return
    *    The bucket index of an identifier
    */
    static size_t alphabeticalGroupIndex(const std::string & identifier, std::uint8_t prefixLength);
};


} } // namespace eglbinding::aux