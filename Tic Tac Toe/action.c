#include <stdio.h>
#include "custom_lib.h"

void action_message(status_codes action){
    switch(action){
        case SUCCESS:
            printf("Operation Success...\n");
            break;
        case FAIL:
            printf("Something went wrong...\n");
            break;
        case FILE_OPEN_ERROR:
            printf("File open error...\n");
            break;
        case INVALID_OPTION: 
            printf("Invalid option...\n");
            break;
        case EXIT:
            printf("Exiting...\n");
            break;
        case PRGM_STARTED:
            break;
        default:
            printf("Status not defined...\n");
            break;
    }
}

status_codes do_action(menu_opt opt){
    switch(opt){
        case NEW_GAME:
            return new_game();
        case LOAD_GAME:
        case HIGH_SCORE:
        case GAME_EXIT: return EXIT;
    }
    return INVALID_OPTION;
}

status_codes new_game(void){
    FILE *current_file=reset_current_game_file();
    char scanf_string[6];
    player_data p1,p2;
    if(current_file == NULL){
        return FILE_OPEN_ERROR;
    }
    clear_screen();
    
    snprintf(scanf_string,sizeof(scanf_string),"%%%ds",PLAYER_NAME_SIZE-1);
    printf("Enter name for player 1 : ");
    scanf(scanf_string,p1.name);
    clear_buffer();
    printf("Enter name for player 2 : ");
    scanf(scanf_string,p2.name);
    clear_buffer(); 

    return SUCCESS;
}