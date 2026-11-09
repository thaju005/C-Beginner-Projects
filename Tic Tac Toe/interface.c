#include <stdio.h>
#include "custom_lib.h"

//Main menu items
char *menu[] = {
    "New Game",
    "Load Game",
    "High Score",
    "Exit"
};

void show_menu(int arr_pos){
    int menu_size = sizeof(menu)/sizeof(menu[0]),i=0;
    while(i < menu_size){
        if(arr_pos == i+1){
            printf("-> %s\n",menu[i]);
        }else{
            printf("   %s\n",menu[i]);
        }
        i++;
    }
}

//Menu building function
void main_menu(int arr_pos){
    printf("####--  Main Menu --####\n\n");
    show_menu(arr_pos);
    printf("\nPress H for help\n");
    printf("# Developed by shajahan #\n");
}

//Board Screen
int ttt_board_screen(char player1[],char player2[],int starting, char ttt_board[3][3],int new_game){
    int input=11; 
    clear_screen();
    show_player_name(player1,player2,starting,new_game);
    show_board(ttt_board);
    show_instruction();
    printf("enter input : ");
    scanf("%d",&input);
    clear_buffer();
    if(input > 0 && input < 10){
        update_board(input,ttt_board);
    }
    return input;
}

void show_instruction(){
    printf("enter 'x' to go back\n");
}

void show_player_name(char player1[],char player2[],int starting,int new_game){
    static int x=0;
    if(new_game == 1){
        x=0;
    }
    printf("Player1 : %s\n",player1);
    printf("Player2 : %s\n",player2);
    if(x > 0){
        return;
    }
    //Show this message only on the starting...
    if(starting == 1){
        printf("%s will start with 'x'\n",player1);
        x++;
    }else{
        printf("%s will start with 'x'\n",player2);
        x++;
    }
}

void show_board(char ttt_board[3][3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(ttt_board[i][j] == 0){
                printf(" 0 ");
            }
        }
        printf("\n");
    }
}