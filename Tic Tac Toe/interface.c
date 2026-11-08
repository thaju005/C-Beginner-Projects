#include <stdio.h>

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