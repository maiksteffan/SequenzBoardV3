#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include "ui/ui.h"

// Display buffer size - using smaller buffer initially for testing
#define LVGL_BUFFER_SIZE (TFT_WIDTH * 10)

// TFT instance
TFT_eSPI tft = TFT_eSPI();

// Touch points
uint16_t touchX, touchY;

// Display buffer
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *buf;

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
        Serial.printf("Touch at x=%d, y=%d\n", touchX, touchY);
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
    delay(1000); // Allow time for serial monitor to connect
    Serial.println("\n\nESP32-S3 Touch LCD 5 inch with LVGL");
    
    // Initialize PSRAM if available
    if (psramInit()) {
        Serial.println("PSRAM initialized successfully");
    } else {
        Serial.println("PSRAM initialization failed - display may not work!");
    }

    // Initialize TFT
    Serial.println("Initializing TFT...");
    tft.begin();
    Serial.println("TFT initialized");
    
    // Try different rotations if the display is blank
    tft.setRotation(1); // Try 1 instead of 0 (landscape mode)
    tft.fillScreen(TFT_RED); // Use a bright color to test visibility
    delay(1000);
    tft.fillScreen(TFT_GREEN);
    delay(1000);
    tft.fillScreen(TFT_BLUE);
    delay(1000);
    Serial.println("TFT filled with test colors");

    // Initialize touch
    Serial.println("Initializing touch...");
    uint16_t calData[5] = {300, 3600, 300, 3600, 6}; // Example calibration - you'll need proper values
    tft.setTouch(calData);
    Serial.println("Touch initialized");

    // Initialize LVGL
    Serial.println("Initializing LVGL...");
    lv_init();
    Serial.println("LVGL initialized");
    
    // Allocate buffer in PSRAM if available
    Serial.println("Allocating display buffer...");
    if (psramFound()) {
        buf = (lv_color_t *)ps_malloc(LVGL_BUFFER_SIZE * sizeof(lv_color_t));
        if (buf == NULL) {
            Serial.println("PSRAM allocation failed for display buffer!");
            buf = (lv_color_t *)malloc(LVGL_BUFFER_SIZE * sizeof(lv_color_t));
        } else {
            Serial.println("Display buffer allocated in PSRAM");
        }
    } else {
        buf = (lv_color_t *)malloc(LVGL_BUFFER_SIZE * sizeof(lv_color_t));
        Serial.println("Display buffer allocated in normal RAM");
    }
    
    if (buf == NULL) {
        Serial.println("Failed to allocate display buffer!");
        while (1) { delay(1000); } // Halt
    }
    
    // Initialize display buffer
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, LVGL_BUFFER_SIZE);

    // Initialize display driver
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = TFT_WIDTH;
    disp_drv.ver_res = TFT_HEIGHT;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);
    Serial.println("Display driver registered");

    // Initialize input device driver
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);
    Serial.println("Input device driver registered");

    // Create a simple test label before initializing the complete UI
    lv_obj_t * test_label = lv_label_create(lv_scr_act());
    lv_label_set_text(test_label, "Display Test");
    lv_obj_align(test_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(test_label, &lv_font_montserrat_20, LV_PART_MAIN);
    Serial.println("Test label created");
    
    // Update the screen
    lv_timer_handler();
    Serial.println("Initial screen updated");
    
    delay(3000); // Wait to see if the test label appears

    // Initialize UI
    Serial.println("Initializing UI...");
    ui_init();
    Serial.println("UI initialized");

    Serial.println("Setup complete");
}

void loop()
{
    lv_timer_handler(); // LVGL task handler
    delay(5);
}