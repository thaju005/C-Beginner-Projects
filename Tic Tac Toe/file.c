#include <stdio.h>
#include "custom_lib.h"

FILE* reset_current_game_file(){
    FILE *fp=fopen(CURRENT_DATA,"w");
    return fp;
}