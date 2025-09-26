#ifndef WATERING_LOGIC_H 
#define WATERING_LOGIC_H 

#include "types.h"

void watering_logic_run(const system_config_t *cfg, const sensors_data_t *data);

void set_system_mode(system_mode_t m);

system_mode_t get_system_mode(void) ;

#endif