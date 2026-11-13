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
    int random=1,new_game=1;
    if(current_file == NULL){
        return FILE_OPEN_ERROR;
    }
    clear_screen();

    printf("A player will be selected randomly to start game!!!\n");
    snprintf(scanf_string,sizeof(scanf_string),"%%%ds",PLAYER_NAME_SIZE-1);
    printf("Enter name for player 1 : ");
    scanf(scanf_string,p1.name);
    clear_buffer();
    printf("Enter name for player 2 : ");
    scanf(scanf_string,p2.name);
    clear_buffer(); 

    //Select a person to start, That person will start with x
    random=generate_random_num();

    start_game(p1.name,p2.name,random,new_game);
    

    return SUCCESS;
}

void start_game(char p1[],char p2[],int r,int new_game){
    int ttt_screen_return,flip_symbol=1;
    char ttt_board[3][3]={{0}},symbol[2];
    symbol[0]='x';
    symbol[1]='0';

    //Calling tic tac toe board screen
    do{
        ttt_screen_return=ttt_board_screen(p1,p2,r,ttt_board,new_game,flip_symbol,symbol);
        r = r == 1 ? 2 : 1;
        flip_symbol = flip_symbol == 1 ? 2 : 1;
    }while(ttt_screen_return != 11);
}

void update_board(int pos,char ttt_board[][3],int flip_symbol, char symbol[2]){
    int k=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(k == pos){
                ttt_board[i][j]=symbol[flip_symbol-1];
            }
            k++;
        }
    }
}