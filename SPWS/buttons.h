#ifndef BUTTONS_H
#define BUTTONS_H 

#include <stdio.h>
#include <stdbool.h>

void buttons_init(void);
void buttons_pull(bool *auto_mode, bool *manual_mode,bool *quit);

#endif