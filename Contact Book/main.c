#include <stdio.h>
#include "my_lib.h"

#define NO_CHOICE -1

int do_action(int ch){
    switch(ch){
        case OPT_ADD: return createContact();  
        case OPT_VIEW: return viewContact();
        case OPT_SEARCH:
        case OPT_EDIT:
        case OPT_REMOVE: return ACTION_OK;
        case OPT_EXIT: return ACTION_EXIT;
        case CLR_SCREEN: clear_screen(); return ACTION_OK;
        default: return ACTION_INVALID;
    }
}

int main(void){
    int ch=NO_CHOICE,scan_res,temp_char;
    do{
        //MENU
        printf("\n____Contact book____\n");
        printf("1. Add contact\n");
        printf("2. View contacts\n");
        printf("3. Search contact\n");
        printf("4. Edit contact\n");
        printf("5. Remove contact\n");
        printf("6. Exit\n");
        printf("7. Clear Screen\n");
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
                printf("Invalid Option...");
                break;
            case ACTION_EXIT:
                printf("Program ended...");
                break;
            case ACTION_OK:
                printf("Operation Successfull...");
                break;
            case FILE_OPEN_ERROR:
                printf("Failed to open file...");
                break;
            case BUFFER_NOT_EMPTY:
                printf("Name or Phone number exceeded limit, please enter name which have length <= %d and phone number <= %d",(NAME_LIMIT - 1),(PHONE_LIMIT -1 ));
                break;
            case NAME_READ_FAIL:
                printf("Contact name is failed to read..");
                break;
            case PHONE_READ_FAIL:
                printf("Phone number faild to read...");
                break;
        }
    }while(ch != OPT_EXIT);
    printf("\n\n");
    return 0;
}