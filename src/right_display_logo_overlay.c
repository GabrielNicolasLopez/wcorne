#include <zephyr/init.h>
#include <zephyr/kernel.h>

#include <lvgl.h>

#include <stdbool.h>

/* Avoid depending on ZMK header include paths in user-config builds. */
struct k_work_q *zmk_display_work_q(void);
bool zmk_display_is_initialized(void);

LV_IMG_DECLARE(corne_right_logo);

static lv_obj_t *logo_img;

static void create_logo_overlay(struct k_work *work) {
    ARG_UNUSED(work);

    /* Only show on the peripheral (right half) for split builds. */
    if (IS_ENABLED(CONFIG_ZMK_SPLIT) && !IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_PERIPHERAL)) {
        return;
    }

    if (logo_img != NULL) {
        return;
    }

    lv_obj_t *screen = lv_scr_act();
    if (screen == NULL) {
        return;
    }

    logo_img = lv_img_create(screen);
    lv_img_set_src(logo_img, &corne_right_logo);
    lv_obj_align(logo_img, LV_ALIGN_TOP_LEFT, 0, 0);

    /* For LV_IMG_CF_ALPHA_* images: recolor controls "ink" color. */
    lv_obj_set_style_img_recolor(logo_img, lv_color_black(), 0);
    lv_obj_set_style_img_recolor_opa(logo_img, LV_OPA_COVER, 0);

    lv_obj_move_foreground(logo_img);
}

K_WORK_DEFINE(create_logo_overlay_work, create_logo_overlay);

static void wait_for_display_init(struct k_work *work);
K_WORK_DELAYABLE_DEFINE(wait_for_display_init_work, wait_for_display_init);

static void wait_for_display_init(struct k_work *work) {
    ARG_UNUSED(work);

    if (!zmk_display_is_initialized()) {
        k_work_schedule(&wait_for_display_init_work, K_MSEC(200));
        return;
    }

    k_work_submit_to_queue(zmk_display_work_q(), &create_logo_overlay_work);
}

static int right_logo_overlay_init(void) {
    k_work_schedule(&wait_for_display_init_work, K_MSEC(200));
    return 0;
}

SYS_INIT(right_logo_overlay_init, APPLICATION, 90);
