#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include "ui/ui.h"

// Display buffer size (adjust if needed)
#define LVGL_BUFFER_SIZE (TFT_WIDTH * 20)

// TFT instance
TFT_eSPI tft = TFT_eSPI();

// Touch points
uint16_t touchX, touchY;

// Display buffer
static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[LVGL_BUFFER_SIZE];

// LVGL display and input drivers
static lv_disp_drv_t disp_drv;
static lv_indev_drv_t indev_drv;

// Display flush callback
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}

// Touch read callback
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
    bool touched = tft.getTouch(&touchX, &touchY);
    
    if (touched)
    {
        data->state = LV_INDEV_STATE_PR;
        data->point.x = touchX;
        data->point.y = touchY;
    }
    else
    {
        data->state = LV_INDEV_STATE_REL;
    }
}

void setup()
{
    Serial.begin(115200);
    Serial.println("ESP32-S3 Touch LCD 5 inch with LVGL");

    // Initialize TFT
    tft.begin();
    tft.setRotation(0); // Adjust based on your display orientation
    tft.fillScreen(TFT_BLACK);

    // Initialize touch - use default calibration for now
    // You might need to calibrate this for your specific screen
    tft.setTouch(NULL);

    // Initialize LVGL
    lv_init();
    
    // Initialize display buffer
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, LVGL_BUFFER_SIZE);

    // Initialize display driver
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = TFT_WIDTH;
    disp_drv.ver_res = TFT_HEIGHT;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    // Initialize input device driver
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

    // Initialize UI
    ui_init();

    Serial.println("Setup complete");
}

void loop()
{
    lv_timer_handler(); // LVGL task handler
    delay(5);
}