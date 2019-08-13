
#pragma once


#include <eglbinding/noegl.h>


namespace egl
{


enum class EGLextension : int // EGLextension is not a type introduced by EGL API so far
{
    UNKNOWN = -1,
    EGL_ANDROID_blob_cache,
    EGL_ANDROID_create_native_client_buffer,
    EGL_ANDROID_framebuffer_target,
    EGL_ANDROID_front_buffer_auto_refresh,
    EGL_ANDROID_get_frame_timestamps,
    EGL_ANDROID_get_native_client_buffer,
    EGL_ANDROID_GLES_layers,
    EGL_ANDROID_image_native_buffer,
    EGL_ANDROID_native_fence_sync,
    EGL_ANDROID_presentation_time,
    EGL_ANDROID_recordable,
    EGL_ANGLE_d3d_share_handle_client_buffer,
    EGL_ANGLE_device_d3d,
    EGL_ANGLE_query_surface_pointer,
    EGL_ANGLE_surface_d3d_texture_2d_share_handle,
    EGL_ANGLE_window_fixed_size,
    EGL_ARM_implicit_external_sync,
    EGL_ARM_pixmap_multisample_discard,
    EGL_EXT_bind_to_front,
    EGL_EXT_buffer_age,
    EGL_EXT_client_extensions,
    EGL_EXT_client_sync,
    EGL_EXT_compositor,
    EGL_EXT_create_context_robustness,
    EGL_EXT_device_base,
    EGL_EXT_device_drm,
    EGL_EXT_device_enumeration,
    EGL_EXT_device_openwf,
    EGL_EXT_device_query,
    EGL_EXT_gl_colorspace_bt2020_linear,
    EGL_EXT_gl_colorspace_bt2020_pq,
    EGL_EXT_gl_colorspace_display_p3,
    EGL_EXT_gl_colorspace_display_p3_linear,
    EGL_EXT_gl_colorspace_display_p3_passthrough,
    EGL_EXT_gl_colorspace_scrgb,
    EGL_EXT_gl_colorspace_scrgb_linear,
    EGL_EXT_image_dma_buf_import,
    EGL_EXT_image_dma_buf_import_modifiers,
    EGL_EXT_image_gl_colorspace,
    EGL_EXT_image_implicit_sync_control,
    EGL_EXT_multiview_window,
    EGL_EXT_output_base,
    EGL_EXT_output_drm,
    EGL_EXT_output_openwf,
    EGL_EXT_pixel_format_float,
    EGL_EXT_platform_base,
    EGL_EXT_platform_device,
    EGL_EXT_platform_wayland,
    EGL_EXT_platform_x11,
    EGL_EXT_protected_content,
    EGL_EXT_protected_surface,
    EGL_EXT_stream_consumer_egloutput,
    EGL_EXT_surface_CTA861_3_metadata,
    EGL_EXT_surface_SMPTE2086_metadata,
    EGL_EXT_swap_buffers_with_damage,
    EGL_EXT_sync_reuse,
    EGL_EXT_yuv_surface,
    EGL_HI_clientpixmap,
    EGL_HI_colorformats,
    EGL_IMG_context_priority,
    EGL_IMG_image_plane_attribs,
    EGL_KHR_cl_event,
    EGL_KHR_cl_event2,
    EGL_KHR_client_get_all_proc_addresses,
    EGL_KHR_config_attribs,
    EGL_KHR_context_flush_control,
    EGL_KHR_create_context,
    EGL_KHR_create_context_no_error,
    EGL_KHR_debug,
    EGL_KHR_display_reference,
    EGL_KHR_fence_sync,
    EGL_KHR_get_all_proc_addresses,
    EGL_KHR_gl_colorspace,
    EGL_KHR_gl_renderbuffer_image,
    EGL_KHR_gl_texture_2D_image,
    EGL_KHR_gl_texture_3D_image,
    EGL_KHR_gl_texture_cubemap_image,
    EGL_KHR_image,
    EGL_KHR_image_base,
    EGL_KHR_image_pixmap,
    EGL_KHR_lock_surface,
    EGL_KHR_lock_surface2,
    EGL_KHR_lock_surface3,
    EGL_KHR_mutable_render_buffer,
    EGL_KHR_no_config_context,
    EGL_KHR_partial_update,
    EGL_KHR_platform_android,
    EGL_KHR_platform_gbm,
    EGL_KHR_platform_wayland,
    EGL_KHR_platform_x11,
    EGL_KHR_reusable_sync,
    EGL_KHR_stream,
    EGL_KHR_stream_attrib,
    EGL_KHR_stream_consumer_gltexture,
    EGL_KHR_stream_cross_process_fd,
    EGL_KHR_stream_fifo,
    EGL_KHR_stream_producer_aldatalocator,
    EGL_KHR_stream_producer_eglsurface,
    EGL_KHR_surfaceless_context,
    EGL_KHR_swap_buffers_with_damage,
    EGL_KHR_vg_parent_image,
    EGL_KHR_wait_sync,
    EGL_MESA_drm_image,
    EGL_MESA_image_dma_buf_export,
    EGL_MESA_platform_gbm,
    EGL_MESA_platform_surfaceless,
    EGL_MESA_query_driver,
    EGL_NOK_swap_region,
    EGL_NOK_swap_region2,
    EGL_NOK_texture_from_pixmap,
    EGL_NV_3dvision_surface,
    EGL_NV_context_priority_realtime,
    EGL_NV_coverage_sample,
    EGL_NV_coverage_sample_resolve,
    EGL_NV_cuda_event,
    EGL_NV_depth_nonlinear,
    EGL_NV_device_cuda,
    EGL_NV_native_query,
    EGL_NV_post_convert_rounding,
    EGL_NV_post_sub_buffer,
    EGL_NV_quadruple_buffer,
    EGL_NV_robustness_video_memory_purge,
    EGL_NV_stream_consumer_gltexture_yuv,
    EGL_NV_stream_cross_display,
    EGL_NV_stream_cross_object,
    EGL_NV_stream_cross_partition,
    EGL_NV_stream_cross_process,
    EGL_NV_stream_cross_system,
    EGL_NV_stream_dma,
    EGL_NV_stream_fifo_next,
    EGL_NV_stream_fifo_synchronous,
    EGL_NV_stream_flush,
    EGL_NV_stream_frame_limits,
    EGL_NV_stream_metadata,
    EGL_NV_stream_origin,
    EGL_NV_stream_remote,
    EGL_NV_stream_reset,
    EGL_NV_stream_socket,
    EGL_NV_stream_socket_inet,
    EGL_NV_stream_socket_unix,
    EGL_NV_stream_sync,
    EGL_NV_sync,
    EGL_NV_system_time,
    EGL_NV_triple_buffer,
    EGL_TIZEN_image_native_buffer,
    EGL_TIZEN_image_native_surface
    
};


} // namespace egl