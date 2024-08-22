#ifndef SENSORS_H
#define SENSORS_H
    #include <Arduino.h>
    #include <Wire.h>
    #include <Adafruit_Sensor.h>
    #include <Adafruit_BME680.h>
    #include "EasyLed.h"
    #include <SPI.h>

    #define SEALEVELPRESSURE_HPA (1013.25)

    struct sensor_values
    {
        float temperature;
        float humidity;
        double pressure;
        double gas_resistance;
        float altitude;
        /* data */
    };

    class Sensor
    {
        private:
            Adafruit_BME680 bme_controller;
        public:
            Sensor();
            sensor_values measure(bool extended_measurement);
    };
#endif