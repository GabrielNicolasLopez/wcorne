#include <zephyr/kernel.h>

#include <lvgl.h>

#if IS_ENABLED(CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM)

LV_IMG_DECLARE(corne_right_logo);

lv_obj_t *zmk_display_status_screen(void) {
    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_clear_flag(screen, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_bg_color(screen, lv_color_white(), 0);
    lv_obj_set_style_bg_opa(screen, LV_OPA_COVER, 0);

    lv_obj_t *img = lv_img_create(screen);
    lv_img_set_src(img, &corne_right_logo);
    lv_obj_align(img, LV_ALIGN_TOP_LEFT, 0, 0);

    lv_obj_set_style_img_recolor(img, lv_color_black(), 0);
    lv_obj_set_style_img_recolor_opa(img, LV_OPA_COVER, 0);

    return screen;
}

#endif /* CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM */
