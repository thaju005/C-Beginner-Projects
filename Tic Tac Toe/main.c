#include <stdio.h>
#include "custom_lib.h"

int main(){
    int arr_pos=1,user_input=1,action=0;
    do{
        clear_screen();
        main_menu(arr_pos);
        user_input=menu_getch();
        switch(user_input){
            case 0:
                arr_pos--;
                if(arr_pos < 1){
                    arr_pos=4;
                }
                break;
            case 1:
                arr_pos++;
                if(arr_pos > 4){
                    arr_pos=1;
                }
                break;
            case 2:
                action=do_action(arr_pos);
                break;
            case 3: 
                show_how_to_use();
                break;
        }
    }while(action != -1);
    clear_screen();
    main_menu(4);
    printf("\nProgram ended...\n");
    return 0;
}