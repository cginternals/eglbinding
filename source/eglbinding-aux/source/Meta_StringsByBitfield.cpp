
#include "Meta_Maps.h"

#include <eglbinding/egl/bitfield.h>


using namespace egl;


namespace eglbinding { namespace aux
{


const std::unordered_map<UnusedMask, std::string> Meta_StringsByUnusedMask =
{
    { UnusedMask::GL_UNUSED_BIT, "GL_UNUSED_BIT" }
};


} } // namespace eglbinding::aux