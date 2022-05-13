#include <flutter_linux/flutter_linux.h>

struct _VideoOutletClass {
    FlPixelBufferTextureClass parent_class;
};

struct VideoOutletPrivate {
    int64_t texture_id = 0;
    uint8_t *buffer = nullptr;
    int32_t video_width = 0;
    int32_t video_height = 0;
};

G_DECLARE_DERIVABLE_TYPE(VideoOutlet, video_outlet, MOBILE_SCANNER, VIDEO_OUTLET,
                         FlPixelBufferTexture)

G_DEFINE_TYPE_WITH_CODE(VideoOutlet, video_outlet,
                        fl_pixel_buffer_texture_get_type(),
                        G_ADD_PRIVATE(VideoOutlet))

static gboolean video_outlet_copy_pixels(FlPixelBufferTexture *texture,
                                         const uint8_t **out_buffer,
                                         uint32_t *width, uint32_t *height,
                                         GError **error) {
    auto video_outlet_private =
            (VideoOutletPrivate *) video_outlet_get_instance_private(
                    MOBILE_SCANNER_VIDEO_OUTLET(texture));
    *out_buffer = video_outlet_private->buffer;
    *width = video_outlet_private->video_width;
    *height = video_outlet_private->video_height;
    return TRUE;
}

static VideoOutlet *video_outlet_new() {
    return MOBILE_SCANNER_VIDEO_OUTLET(g_object_new(video_outlet_get_type(), nullptr));
}

static void video_outlet_class_init(VideoOutletClass *klass) {
    FL_PIXEL_BUFFER_TEXTURE_CLASS(klass)->copy_pixels = video_outlet_copy_pixels;
}

static void video_outlet_init(VideoOutlet *self) {}