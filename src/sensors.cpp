#include <sensors.h>

Sensor::Sensor(){
    this->bme_controller = Adafruit_BME680();
    if (!this->bme_controller.begin())
    {
        Serial.println(F("Could not find a valid BME680 sensor, check wiring!"));
        while (1);
    }

    this->bme_controller.setTemperatureOversampling(BME680_OS_8X);
    this->bme_controller.setHumidityOversampling(BME680_OS_2X);
    this->bme_controller.setPressureOversampling(BME680_OS_4X);
    this->bme_controller.setIIRFilterSize(BME680_FILTER_SIZE_3);
    this->bme_controller.setGasHeater(320, 150); // 320*C for 150 ms
}

sensor_values Sensor::measure(bool extended_measurement = false)
{
    if (extended_measurement){
        return sensor_values{
        .temperature = this->bme_controller.readTemperature(),
        .humidity = this->bme_controller.readHumidity(),
        .pressure = this->bme_controller.readPressure() / 100.0,
        .gas_resistance = this->bme_controller.readGas() / 1000.0,
        .altitude = this->bme_controller.readAltitude(SEALEVELPRESSURE_HPA)
        };
    }
    else {
        return sensor_values{
        .temperature = this->bme_controller.readTemperature(),
        .humidity = this->bme_controller.readHumidity(),
        .pressure = 0,
        .gas_resistance = 0,
        .altitude = 0
        };
    }
}