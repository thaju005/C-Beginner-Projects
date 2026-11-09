#include <stdio.h>
#include "custom_lib.h"

int main(){
    int arr_pos=1,user_input=1;
    status_codes action=PRGM_STARTED;
    do{
        clear_screen();
        main_menu(arr_pos);
        user_input=menu_getch();
        switch(user_input){
            case 0:
                //Arrow up
                arr_pos--;
                if(arr_pos < 1){
                    arr_pos=4;
                }
                break;
            case 1:
                //Arrow down
                arr_pos++;
                if(arr_pos > 4){
                    arr_pos=1;
                }
                break;
            case 2:
                //enter
                // arr_pos contain value 1 to 4, to mtach with menu option, i need to decrease a value
                action=do_action(arr_pos-1);
                break;
            case 3: 
                //h - help
                show_how_to_use();
                break;
        }
        action_message(action);
    }while(action != EXIT);
    clear_screen();
    main_menu(4);
    printf("\nProgram ended...\n\n");
    return 0;
}