
#include <eglbinding-aux/Meta.h>

#include <eglbinding/egl/bitfield.h>

#include "Meta_Maps.h"


using namespace egl;


namespace
{


const auto none = std::string{};


} // namespace


namespace eglbinding { namespace aux
{


const std::string & Meta::getString(const UnusedMask eglbitfield)
{
    const auto i = Meta_StringsByUnusedMask.find(eglbitfield);
    if (i != Meta_StringsByUnusedMask.end())
    {
        return i->second;
    }
    return none;
}


} } // namespace eglbinding::aux