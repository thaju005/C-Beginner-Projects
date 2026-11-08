#include "custom_lib.h"

int do_action(menu_opt opt){
    switch(opt){
        case NEW_GAME:
        case LOAD_GAME:
        case HIGH_SCORE:
        case EXIT: return -1;
    }
    return -1;
}