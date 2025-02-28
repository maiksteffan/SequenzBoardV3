#ifndef _UI_H
#define _UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

// SCREENS
extern lv_obj_t * ui_MainScreen;

// WIDGETS
extern lv_obj_t * ui_MainPanel;
extern lv_obj_t * ui_MainLabel;
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Button2;
extern lv_obj_t * ui_Slider;
extern lv_obj_t * ui_ValueLabel;

void ui_init(void);
void ui_MainScreen_screen_init(void);

// Event handlers
void ui_event_Button1(lv_event_t * e);
void ui_event_Button2(lv_event_t * e);
void ui_event_Slider(lv_event_t * e);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif