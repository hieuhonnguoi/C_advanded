#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

typedef enum {
    MODE_AUTO,
    MODE_MANUAL
}system_mode_t;

typedef enum {
    PUMP_ON,
    PUMP_OFF
}pump_state_t;

typedef enum {
    LED_NORMAL,
    LED_WARNING,
    LED_LOW_WATERING_ALERT,
    LED_ERROR
}led_state_t;

typedef struct {
    int soil_moisture;
    float temperature_c;
}sensors_data_t;

typedef struct {
    uint8_t min_moisture;
    uint8_t max_moisture;
    uint32_t max_water_seconds;
    uint32_t sensor_interval_seconds;
    system_mode_t mode;
}system_config_t;

#endif