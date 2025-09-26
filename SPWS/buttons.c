#include <stdio.h>
#include <stdbool.h>
#include "buttons.h"

void buttons_init(void){
    printf("A for Auto, M for Manual");
}

void buttons_pull(bool *auto_mode,bool *manual_mode, bool *quit){
    if (!kbhit()) return;

    char c = getchar();
    if (c == 'a' || c == 'A') {
        *auto_mode = true;
    }
    if (c == 'm' || c == 'M'){
        *manual_mode = true;
    }
    if (c == 'q' || c == 'Q'){
        *quit = true;
    }
}