#ifndef _UI_HELPERS_H
#define _UI_HELPERS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

// Helper functions
void _ui_bar_set_property(lv_obj_t * target, int id, int val);
void _ui_basic_set_property(lv_obj_t * target, int id, int val);
void _ui_dropdown_set_property(lv_obj_t * target, int id, int val);
void _ui_image_set_property(lv_obj_t * target, int id, int val);
void _ui_label_set_property(lv_obj_t * target, int id, int val);
void _ui_roller_set_property(lv_obj_t * target, int id, int val);
void _ui_slider_set_property(lv_obj_t * target, int id, int val);
void _ui_screen_change(lv_obj_t * target, lv_scr_load_anim_t fademode, int spd, int delay);
void _ui_arc_increment(lv_obj_t * target, int val);
void _ui_bar_increment(lv_obj_t * target, int val, int anm);
void _ui_slider_increment(lv_obj_t * target, int val, int anm);
void _ui_flag_modify(lv_obj_t * target, int32_t flag, int value);
void _ui_opacity_set(lv_obj_t * target, int val);
void _ui_anim_callback_set_x(lv_anim_t * a, int32_t v);
void _ui_anim_callback_set_y(lv_anim_t * a, int32_t v);
void _ui_anim_callback_set_width(lv_anim_t * a, int32_t v);
void _ui_anim_callback_set_height(lv_anim_t * a, int32_t v);
void _ui_anim_callback_set_opacity(lv_anim_t * a, int32_t v);
void _ui_anim_callback_set_image_zoom(lv_anim_t * a, int32_t v);
void _ui_anim_callback_set_image_angle(lv_anim_t * a, int32_t v);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif