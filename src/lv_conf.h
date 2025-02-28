/**
 * @file lv_conf.h
 * Configuration file for v8.3.7
 */

 #ifndef LV_CONF_H
 #define LV_CONF_H
 
 #include <stdint.h>
 
 /*====================
    COLOR SETTINGS
  *====================*/
 
 /* Color depth: 1 (1 byte per pixel), 8 (RGB332), 16 (RGB565), 32 (ARGB8888) */
 #define LV_COLOR_DEPTH 16
 
 /* Swap the 2 bytes of RGB565 color. Useful if the display has an 8-bit interface */
 #define LV_COLOR_16_SWAP 0
 
 /*====================
    MEMORY SETTINGS
  *====================*/
 
 /* Size of the memory used by `lv_mem_alloc` in bytes (>= 2kB) */
 #define LV_MEM_SIZE (48U * 1024U)
 
 /*====================
    HAL SETTINGS
  *====================*/
 
 /* Default display refresh period. LVG will redraw changed areas with this period time */
 #define LV_DISP_DEF_REFR_PERIOD 30
 
 /*====================
    FEATURE CONFIGURATION
  *====================*/
 
 /*1: Enable the Animations */
 #define LV_USE_ANIMATION 1
 
 /* 1: Enable shadow drawing on rectangles */
 #define LV_USE_SHADOW 1
 
 /* 1: Enable object opacity (opacity/transparency) */
 #define LV_USE_OPA 1
 
 /* 1: Enable image support */
 #define LV_USE_IMG 1
 
 /* 1: Enable using built-in fonts */
 #define LV_USE_FONT_BUILTIN 1
 
 /* Declare the type of the user data of fonts */
 typedef void * lv_font_user_data_t;
 
 /*====================
    FONT USAGE
  *====================*/
 
 /* Montserrat fonts with ASCII range and some symbols */
 #define LV_FONT_MONTSERRAT_8     0
 #define LV_FONT_MONTSERRAT_10    0
 #define LV_FONT_MONTSERRAT_12    1
 #define LV_FONT_MONTSERRAT_14    1
 #define LV_FONT_MONTSERRAT_16    1
 #define LV_FONT_MONTSERRAT_18    0
 #define LV_FONT_MONTSERRAT_20    1
 #define LV_FONT_MONTSERRAT_22    0
 #define LV_FONT_MONTSERRAT_24    0
 #define LV_FONT_MONTSERRAT_26    0
 #define LV_FONT_MONTSERRAT_28    0
 #define LV_FONT_MONTSERRAT_30    0
 #define LV_FONT_MONTSERRAT_32    0
 #define LV_FONT_MONTSERRAT_34    0
 #define LV_FONT_MONTSERRAT_36    0
 #define LV_FONT_MONTSERRAT_38    0
 #define LV_FONT_MONTSERRAT_40    0
 #define LV_FONT_MONTSERRAT_42    0
 #define LV_FONT_MONTSERRAT_44    0
 #define LV_FONT_MONTSERRAT_46    0
 #define LV_FONT_MONTSERRAT_48    0
 
 /* Demonstrate special features */
 #define LV_FONT_MONTSERRAT_12_SUBPX      0
 #define LV_FONT_MONTSERRAT_28_COMPRESSED 0  /*bpp = 3*/
 #define LV_FONT_DEJAVU_16_PERSIAN_HEBREW 0  /*Hebrew, Arabic, Persian letters and all their forms*/
 #define LV_FONT_SIMSUN_16_CJK            0  /*1000 most common CJK radicals*/
 
 /*===================
  *  LV_OBJ SETTINGS
  *==================*/
 
 #define LV_USE_OBJ_PROPERTY 0
 
 /*==================
  *  WIDGET USAGE
  *================*/
 
 /*Documentation of the widgets: https://docs.lvgl.io/latest/en/html/widgets/index.html*/
 
 #define LV_USE_ARC        1
 #define LV_USE_BAR        1
 #define LV_USE_BTN        1
 #define LV_USE_BTNMATRIX  1
 #define LV_USE_CANVAS     1
 #define LV_USE_CHECKBOX   1
 #define LV_USE_DROPDOWN   1
 #define LV_USE_IMG        1
 #define LV_USE_LABEL      1
 #define LV_USE_LINE       1
 #define LV_USE_ROLLER     1
 #define LV_USE_SLIDER     1
 #define LV_USE_SWITCH     1
 #define LV_USE_TABLE      1
 #define LV_USE_TEXTAREA   1
 
 /*==================
  * THEMES
  *==================*/
 
 /*A simple, impressive and very complete theme*/
 #define LV_USE_THEME_DEFAULT 1
 
 /*==================
 * LAYOUTS
 *==================*/
 
 /*A layout similar to Flexbox in CSS.*/
 #define LV_USE_FLEX 1
 
 /*A layout similar to Grid in CSS.*/
 #define LV_USE_GRID 1
 
 #endif /*LV_CONF_H*/