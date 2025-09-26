#include "watering_logic.h"
#include "actuators.h"
#include "sensor.h"
#include <stdio.h>

static system_mode_t g_mode = MODE_AUTO;

void watering_logic_run(const system_config_t *cfg, const sensors_data_t *data){
    if (g_mode == MODE_MANUAL) {
        printf("[Logic] -> MANUAL. No more watering\n");
        return;
    }

    //AUTO mode
    if(data->soil_moisture < cfg->min_moisture){
        printf("[Logic] -> Soil low(%d%%). Pump On\n",data->soil_moisture);
        turn_pump_on();
        set_led_state(LED_LOW_MOISTURE_ALERT);
    }else if (data->soil_moisture > cfg->max_moisture){
        printf("[Logic] -> Soil high(%d%%). Pump Off\n",data->soil_moisture);
        turn_pump_off();
        set_led_state(LED_NORMAL);
    } else {
        printf("[Logic] -> Soil normal (%d%%). Keep state\n",data->soil_moisture);
        set_led_state(LED_WARNING);
    }

    //Change mode
    void set_system_mode(system_mode_t m){
        g_mode = m;
        printf("[Logic] Change mode -> %s\n",)
    }

    system_mode_t get_system_mode(void){
        return g_mode;
    }
}