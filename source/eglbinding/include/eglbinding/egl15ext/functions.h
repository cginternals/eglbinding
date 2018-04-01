
#pragma once


#include <eglbinding/noegl.h>
#include <eglbinding/egl/functions.h>


namespace egl15ext
{


using egl::eglClientWaitSyncKHR;
using egl::eglClientWaitSyncNV;
using egl::eglCompositorBindTexWindowEXT;
using egl::eglCompositorSetContextAttributesEXT;
using egl::eglCompositorSetContextListEXT;
using egl::eglCompositorSetSizeEXT;
using egl::eglCompositorSetWindowAttributesEXT;
using egl::eglCompositorSetWindowListEXT;
using egl::eglCompositorSwapPolicyEXT;
using egl::eglCreateDRMImageMESA;
using egl::eglCreateFenceSyncNV;
using egl::eglCreateImageKHR;
using egl::eglCreateNativeClientBufferANDROID;
using egl::eglCreatePixmapSurfaceHI;
using egl::eglCreatePlatformPixmapSurfaceEXT;
using egl::eglCreatePlatformWindowSurfaceEXT;
using egl::eglCreateStreamAttribKHR;
using egl::eglCreateStreamFromFileDescriptorKHR;
using egl::eglCreateStreamKHR;
using egl::eglCreateStreamProducerSurfaceKHR;
using egl::eglCreateStreamSyncNV;
using egl::eglCreateSync64KHR;
using egl::eglCreateSyncKHR;
using egl::eglDebugMessageControlKHR;
using egl::eglDestroyImageKHR;
using egl::eglDestroyStreamKHR;
using egl::eglDestroySyncKHR;
using egl::eglDestroySyncNV;
using egl::eglDupNativeFenceFDANDROID;
using egl::eglExportDMABUFImageMESA;
using egl::eglExportDMABUFImageQueryMESA;
using egl::eglExportDRMImageMESA;
using egl::eglFenceNV;
using egl::eglGetCompositorTimingANDROID;
using egl::eglGetCompositorTimingSupportedANDROID;
using egl::eglGetFrameTimestampSupportedANDROID;
using egl::eglGetFrameTimestampsANDROID;
using egl::eglGetNativeClientBufferANDROID;
using egl::eglGetNextFrameIdANDROID;
using egl::eglGetOutputLayersEXT;
using egl::eglGetOutputPortsEXT;
using egl::eglGetPlatformDisplayEXT;
using egl::eglGetStreamFileDescriptorKHR;
using egl::eglGetSyncAttribKHR;
using egl::eglGetSyncAttribNV;
using egl::eglGetSystemTimeFrequencyNV;
using egl::eglGetSystemTimeNV;
using egl::eglLabelObjectKHR;
using egl::eglLockSurfaceKHR;
using egl::eglOutputLayerAttribEXT;
using egl::eglOutputPortAttribEXT;
using egl::eglPostSubBufferNV;
using egl::eglPresentationTimeANDROID;
using egl::eglQueryDebugKHR;
using egl::eglQueryDeviceAttribEXT;
using egl::eglQueryDeviceStringEXT;
using egl::eglQueryDevicesEXT;
using egl::eglQueryDisplayAttribEXT;
using egl::eglQueryDisplayAttribKHR;
using egl::eglQueryDisplayAttribNV;
using egl::eglQueryDmaBufFormatsEXT;
using egl::eglQueryDmaBufModifiersEXT;
using egl::eglQueryNativeDisplayNV;
using egl::eglQueryNativePixmapNV;
using egl::eglQueryNativeWindowNV;
using egl::eglQueryOutputLayerAttribEXT;
using egl::eglQueryOutputLayerStringEXT;
using egl::eglQueryOutputPortAttribEXT;
using egl::eglQueryOutputPortStringEXT;
using egl::eglQueryStreamAttribKHR;
using egl::eglQueryStreamKHR;
using egl::eglQueryStreamMetadataNV;
using egl::eglQueryStreamTimeKHR;
using egl::eglQueryStreamu64KHR;
using egl::eglQuerySurface64KHR;
using egl::eglQuerySurfacePointerANGLE;
using egl::eglResetStreamNV;
using egl::eglSetBlobCacheFuncsANDROID;
using egl::eglSetDamageRegionKHR;
using egl::eglSetStreamAttribKHR;
using egl::eglSetStreamMetadataNV;
using egl::eglSignalSyncKHR;
using egl::eglSignalSyncNV;
using egl::eglStreamAttribKHR;
using egl::eglStreamConsumerAcquireAttribKHR;
using egl::eglStreamConsumerAcquireKHR;
using egl::eglStreamConsumerGLTextureExternalAttribsNV;
using egl::eglStreamConsumerGLTextureExternalKHR;
using egl::eglStreamConsumerOutputEXT;
using egl::eglStreamConsumerReleaseAttribKHR;
using egl::eglStreamConsumerReleaseKHR;
using egl::eglSwapBuffersRegion2NOK;
using egl::eglSwapBuffersRegionNOK;
using egl::eglSwapBuffersWithDamageEXT;
using egl::eglSwapBuffersWithDamageKHR;
using egl::eglUnlockSurfaceKHR;
using egl::eglWaitSyncKHR;


} // namespace egl15ext
