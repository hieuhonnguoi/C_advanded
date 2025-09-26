#include "sensors.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

static double sim_time_sec = 0.0;
static double sim_step = 1.0;

void sensors_init(void){
    srand((unsigned)time(NULL)); //khởi tạo biến thời gian ngẫu nhiên
}

static float smoothed_moisture = 50.0f;
static float smoothed_temperature = 25.0f;

void sensors_read(sensor_data_t *out){
    sim_time_sec += sim_step;

    //Giả lập các giá trị biến độ ẩm và nhiệt độ
    double base_moisture = 50.0 + 20.0*sin(sim_time_sec/60.0);
    double noise = ((rand() % 1000) / 1000.0 - 0.5) * 4.0;
    double raw_moisture = base_moisture + noise;

    double base_temp = 25.0 + 3.0*sin(sim_time_sec/120.0);
    double noise_t = ((rand()%1000)/1000 - 0.5) * 1.0;
    double raw_temp = base_temp + noise_t;

    //Giới hạn nhiệt độ, độ ẩm
    if (raw_moisture < 0) raw_moisture = 0;
    if (raw_moisture > 100 ) raw_moisture = 100;

    const float alpha = 0.3f;
    smoothed_moisture = (1 - alpha) * smoothed_moisture + alpha * (float)raw_moist;
    smoothed_temp = (1 - alpha) * smoothed_temp + alpha * (float)raw_temp;

    out->soil_moisture = smoothed_moisture;
    out->temperature_c = smoothed_temp;
}
