#include <stdio.h>
#include "my_lib.h"

#define NO_CHOICE -1

int do_action(int ch){
    switch(ch){
        case OPT_ADD: return createContact();  
        case OPT_VIEW:
        case OPT_SEARCH:
        case OPT_EDIT:
        case OPT_REMOVE: return ACTION_OK;
        case OPT_EXIT: return ACTION_EXIT;
        default: return ACTION_INVALID;
    }
}

int main(void){
    int ch=NO_CHOICE,scan_res,temp_char;
    do {
        //MENU
        printf("\n____Contact book____\n");
        printf("1. Add contact\n");
        printf("2. View contacts\n");
        printf("3. Search contact\n");
        printf("4. Edit contact\n");
        printf("5. Remove contact\n");
        printf("6. Exit\n");
        printf("----------------\nEnter Your Choice : ");
        scan_res=scanf("%d",&ch);
        if(scan_res == 1){
            ch--;
        }
        while((temp_char=getchar()) != '\n' && temp_char != EOF){
            continue;
        }
        if(scan_res != 1){
            if(scan_res == EOF){
                ch = OPT_EXIT;
                printf("Input closed!!!\n");
            }else {
                clear_screen();
                printf("Invalid input!!!\n");
                continue;
            }
        }

        //ACTION FUNCTION CALL
        switch(do_action(ch)){
            case ACTION_INVALID:
                clear_screen();
                printf("Invalid Option...");
                break;
            case ACTION_EXIT:
                printf("Program ended...");
                break;
            case ACTION_OK:
                clear_screen();
                printf("Operation Successfull...");
                break;
            case FILE_OPEN_ERROR:
                clear_screen();
                printf("File creation error");
                break;
            case CONTACT_SUCCESS:
                clear_screen();
                printf("New Contact Added");
                break;
        }
    }while(ch != OPT_EXIT);
    printf("\n\n");
    return 0;
}