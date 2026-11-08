#include <stdio.h>
#include "custom_lib.h"

void show_how_to_use(void){
    clear_screen();
    printf("Use arrow up/arrow down key to navigate through the menu. Use enter key to go inside to any menu\n");
    printf("Press any key to go back");
    fflush(stdout);
    lin_getch();
}