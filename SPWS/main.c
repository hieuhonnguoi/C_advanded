#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>

#include "config.h"
#include "types.h"
#include "sensors.h"
#include "actuators.h"
#include "buttons.h"
#include "watering_logic.h"

int main(void){
    printf("=== SPWS Simulation Start ===\n");

    system_config_t cfg = {
        .min_moisture = DEFAULT_MIN_MOISTURE,
        .max_moisture = DEFAULT_MAX_MOISTURE,
        .max_water_seconds = DEFAULT_WATER_SECONDS,
        .sensor_interval_seconds = DEFAULT_SENSORS_INTERVAL,
        .mode = MODE_AUTO
    };

    sensors_data_t s;

    sensors_init();
    actuators_init();
    buttons_init();
    watering_logic_run(cfg,s);

    
    time_t last_status = time(NULL);

    bool quit = false;
    while (!quit){
        bool auto_mode=false, manual_mode=false;
        buttons_pull(&auto_mode, &manual_mode);

        if (auto_mode){
            if (cfg.mode == MODE_AUTO){
                cfg.mode = MODE_MANUAL;
                turn_pump_off();
                printf("[MAIN] Mode -> MANUAL\n");
            } else {
                cfg.mode = MODE_AUTO;
                printf("[MAIN] Mode -> AUTO\n");
            }
        }
        if (manual_mode && cfg.mode == MODE_MANUAL){
            watering_manual_trigger(MANUAL_WATER_SECONDS);
        }

        sensors_read(&s);
        watering_update(&s);

        time_t now = time(NULL);
        if (difftime(now, last_status) >= 10.0){
            const char *mode_s = (cfg.mode==MODE_AUTO)? "AUTO":"MANUAL";
            printf("[STATUS] Mode:%s | Soil: %.2f%% | Temp: %.2fC | Pump:%s\n",
                   mode_s, s.soil_moisture, s.temperature_c,
                   (get_pump_state()==PUMP_ON)? "ON":"OFF");
            last_status = now;
        }

        usleep(500000); // 500ms
    }

    printf("=== SPWS Simulation End ===\n");
    return 0;
}
