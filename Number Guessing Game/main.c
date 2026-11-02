#include <stdio.h>
#include "user_defined_lib.h"


int main(){
    int random_num;    
    random_num=init_game();
    printf("Random number generated, Find it!!!\n");
    find_random(random_num);
}