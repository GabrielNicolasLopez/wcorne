/*
 *
 * Copyright (c) 2023 The ZMK Contributors
 * SPDX-License-Identifier: MIT
 *
 */

#include "peripheral_status.h"

LV_IMG_DECLARE(corro01);

const lv_img_dsc_t *anim_imgs[] = {
    &corro01,
};

int zmk_widget_status_init(struct zmk_widget_status *widget, lv_obj_t *parent) {
    widget->obj = lv_obj_create(parent);
    lv_obj_set_size(widget->obj, 160, 68);
    lv_obj_clear_flag(widget->obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_opa(widget->obj, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(widget->obj, 0, 0);
    lv_obj_set_style_outline_width(widget->obj, 0, 0);
    lv_obj_set_style_pad_all(widget->obj, 0, 0);

    lv_obj_t *art = lv_animimg_create(widget->obj);
    lv_animimg_set_src(art, (const void **)anim_imgs, 1);
    lv_animimg_set_duration(art, CONFIG_CUSTOM_ANIMATION_SPEED);
    lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(art);

    lv_obj_align(art, LV_ALIGN_TOP_LEFT, 0, 0);
    return 0;
}

lv_obj_t *zmk_widget_status_obj(struct zmk_widget_status *widget) { return widget->obj; }
