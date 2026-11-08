#include <stdio.h>
#include "my_lib.h"

#define NO_CHOICE -1

int do_action(int ch){
    switch(ch){
        case OPT_ADD: 
            clear_screen();
            return createContact();  
        case OPT_VIEW: 
            clear_screen();
            return viewContact(NULL);
        case OPT_SEARCH:
            clear_screen();
            return searchContact();
        case OPT_EDIT:
            clear_screen();
            return editContact();
        case OPT_REMOVE: 
            clear_screen();
            return removeContact();
        case OPT_EXIT: return ACTION_EXIT;
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
                ch = OPT_EXIT;
                break;
            case ACTION_OK:
                printf("\nOperation Successfull...");
                break;
            case FILE_OPEN_ERROR:
                clear_screen();
                printf("Failed to open file...");
                break;
            case BUFFER_NOT_EMPTY:
                clear_screen();
                printf("Name or Phone number exceeded limit, please enter name which have length <= %d and phone number <= %d",(NAME_LIMIT - 1),(PHONE_LIMIT -1 ));
                break;
            case NAME_READ_FAIL:
                clear_screen();
                printf("Contact name is failed to read..");
                break;
            case PHONE_READ_FAIL:
                clear_screen();
                printf("Phone number faild to read...");
                break;
            case INVALID_PERSON:
                clear_screen();
                printf("Invalid person...");
                break;
            case FAIL:
                clear_screen();
                printf("Something went wrong...");
                break;
        }
    }while(ch != OPT_EXIT);
    printf("\n\n");
    return 0;
}