#include "ui.h"
#include "ui_helpers.h"

// SCREENS
lv_obj_t * ui_MainScreen;

// WIDGETS
lv_obj_t * ui_MainPanel;
lv_obj_t * ui_MainLabel;
lv_obj_t * ui_Button1;
lv_obj_t * ui_Button2;
lv_obj_t * ui_Slider;
lv_obj_t * ui_ValueLabel;

// EVENT CALLBACKS
void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_label_set_text(ui_MainLabel, "Button 1 Pressed");
    }
}

void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_label_set_text(ui_MainLabel, "Button 2 Pressed");
    }
}

void ui_event_Slider(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        int value = lv_slider_get_value(ui_Slider);
        char buf[16];
        snprintf(buf, sizeof(buf), "Value: %d", value);
        lv_label_set_text(ui_ValueLabel, buf);
    }
}

void ui_MainScreen_screen_init(void)
{
    // Create main screen
    ui_MainScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_MainScreen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_MainScreen, lv_color_hex(0x2D3142), LV_PART_MAIN | LV_STATE_DEFAULT);

    // Create main panel
    ui_MainPanel = lv_obj_create(ui_MainScreen);
    lv_obj_set_width(ui_MainPanel, 700);
    lv_obj_set_height(ui_MainPanel, 400);
    lv_obj_set_align(ui_MainPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_MainPanel, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_MainPanel, lv_color_hex(0xEAEBED), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_MainPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_MainPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_MainPanel, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_MainPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_MainPanel, 50, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Create main label
    ui_MainLabel = lv_label_create(ui_MainPanel);
    lv_obj_set_width(ui_MainLabel, 300);
    lv_obj_set_height(ui_MainLabel, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_MainLabel, 0);
    lv_obj_set_y(ui_MainLabel, -140);
    lv_obj_set_align(ui_MainLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_MainLabel, "SequenzBoardV3");
    lv_obj_set_style_text_font(ui_MainLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_MainLabel, lv_color_hex(0x2D3142), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_MainLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    // Create buttons
    ui_Button1 = lv_btn_create(ui_MainPanel);
    lv_obj_set_width(ui_Button1, 150);
    lv_obj_set_height(ui_Button1, 50);
    lv_obj_set_x(ui_Button1, -120);
    lv_obj_set_y(ui_Button1, -50);
    lv_obj_set_align(ui_Button1, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_Button1, ui_event_Button1, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0x4F5D75), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * ui_Button1Label = lv_label_create(ui_Button1);
    lv_obj_set_width(ui_Button1Label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Button1Label, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_Button1Label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Button1Label, "Button 1");

    ui_Button2 = lv_btn_create(ui_MainPanel);
    lv_obj_set_width(ui_Button2, 150);
    lv_obj_set_height(ui_Button2, 50);
    lv_obj_set_x(ui_Button2, 120);
    lv_obj_set_y(ui_Button2, -50);
    lv_obj_set_align(ui_Button2, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_Button2, ui_event_Button2, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0x4F5D75), LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * ui_Button2Label = lv_label_create(ui_Button2);
    lv_obj_set_width(ui_Button2Label, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Button2Label, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_Button2Label, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Button2Label, "Button 2");

    // Create slider
    ui_Slider = lv_slider_create(ui_MainPanel);
    lv_obj_set_width(ui_Slider, 400);
    lv_obj_set_height(ui_Slider, 20);
    lv_obj_set_x(ui_Slider, 0);
    lv_obj_set_y(ui_Slider, 50);
    lv_obj_set_align(ui_Slider, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_Slider, ui_event_Slider, LV_EVENT_ALL, NULL);
    lv_slider_set_range(ui_Slider, 0, 100);

    // Create value label
    ui_ValueLabel = lv_label_create(ui_MainPanel);
    lv_obj_set_width(ui_ValueLabel, 150);
    lv_obj_set_height(ui_ValueLabel, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_ValueLabel, 0);
    lv_obj_set_y(ui_ValueLabel, 100);
    lv_obj_set_align(ui_ValueLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ValueLabel, "Value: 0");
    lv_obj_set_style_text_font(ui_ValueLabel, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ValueLabel, lv_color_hex(0x2D3142), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ValueLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void ui_init(void)
{
    ui_MainScreen_screen_init();
    lv_disp_load_scr(ui_MainScreen);
}