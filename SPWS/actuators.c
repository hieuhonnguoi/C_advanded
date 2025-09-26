#include "actuators.h"
#include <stdio.h>

static led_state_t g_led = LED_NORMAL;
static pump_state_t g_pump = PUMP_OFF;

void actuators_init(){
    g_led = LED_NORMAL;
    g_pump = PUMP_OFF;
}

void turn_pump_off(){
    if (g_pump == PUMP_OFF) return;
    g_pump = PUMP_OFF;
    printf("[ACT] PUMP-> OFF");
}

void turn_pump_on(){
    if(g_pump == PUMP_ON) return;
    g_pump = PUMP_ON;
    printf("[ACT] PUMP -> ON");
}

void set_led_state(led_state_t s){
    if (g_led == s) return;
    g_led = s;
    const char* name = "?";
    switch (s){
        case LED_NORMAL: name = "NORMAL (GREEEN)";break;
        case LED_WARNING: name = "WARNING (YELLOW)";break;
        case LED_LOW_MOISTURE_ALERT: name = "ALERT (BLINK RED)";break;
        case LED_ERROR : name = "ERROR (RED)";break;
    }
    printf("[ACT] LED -> %s\n",name);

    led_state_t get_led_state (void) {
        return g_led;
    }
    pump_state_t get_pump_state (void) {
        return g_pump;
    }
}