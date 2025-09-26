#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

//Xét các giá trị ngưỡng
#define DEFAULT_MIN_MOISTURE 30 //thiết lập ngưỡng nhiệt độ tối thiểu
#define DEFAULT_MAX_MOISTURE 60 //thiết lập ngưỡng nhiệt độ tối đa
#define DEFAULT_WATER_SECONDS 15 //thời gian bơm nước (s)
#define DEFAULT_SENSORS_INTERVAL 10//thời gian hoạt động giữa các sensor (s)
#define MANUAL_WATER_SECONDS 10 //thời gian tưới khi cùng nút thủ công

#endif //CONFIG_H

