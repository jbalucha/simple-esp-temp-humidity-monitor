#include <sensors.h>

#ifdef USE_DISPLAY
    #include <display.h>
    OLED_CLASS_OBJ display(OLED_ADDRESS, OLED_SDA, OLED_SCL);
#endif

Sensor bme680;

void setup()
{
    Serial.begin(115200);
    while (!Serial)
    {
        delay(10);
    }

    Serial.println(F("Starting..."));
    Sensor bme680 = Sensor();


    #ifdef USE_DISPLAY
        init_display(display);
    #endif
    
    Serial.println(F("BME680 started!"));

}


void loop()
{   
    #ifdef USE_DISPLAY
        sensor_values values = bme680.measure(false);
        write_2_rows_on_display(display,
                                String(values.temperature) + " °C",
                                String(values.humidity) + " %");
    #else
        sensor_values values = bme680.measure(true);
        Serial.println("Temperature: " + String(values.temperature) + " C");
        Serial.println("Pressure: " + String(values.pressure) + " hPa");
        Serial.println("Humidity: " + String(values.humidity) + " %");
        Serial.println("Gas: " + String(values.gas_resistance) + " KOhms");
        Serial.println("Approx. Altitude: " + String(values.altitude) + " m");
    #endif
    
    delay(1000);
}