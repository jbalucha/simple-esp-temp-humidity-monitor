#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#ifdef USE_DISPLAY 
    #include <Wire.h> 
    #include "SSD1306Wire.h" 
    #define OLED_CLASS_OBJ  SSD1306Wire
    #define OLED_ADDRESS    0x3C
    #define OLED_SDA    21
    #define OLED_SCL    22

    #define CONFIG_MOSI 27
    #define CONFIG_MISO 19
    #define CONFIG_CLK  5
    #define CONFIG_NSS  18
    #define CONFIG_RST  23
    #define CONFIG_DIO0 26

    void write_2_rows_on_display(OLED_CLASS_OBJ &display, String row1, String row2){
        display.clear();
        display.drawString(2, 0, row1);
        display.drawString(2, 28, row2);
        display.display();
    }

    void init_display(OLED_CLASS_OBJ &display){
        display.init();
        display.flipScreenVertically();
        display.setFont(ArialMT_Plain_24);
        display.setTextAlignment(TEXT_ALIGN_LEFT);
        display.drawString(0, 22, "STARTING");
        display.display();
        display.setTextAlignment(TEXT_ALIGN_LEFT);
    }
#endif