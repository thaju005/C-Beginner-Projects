#include <stdio.h>
#include <string.h>
#include "my_lib.h"

struct contact {
    char name[NAME_LIMIT],phone_no[PHONE_LIMIT];
};

status_codes clear_buffer(void){
    int buffer_empty=0,temp_char;
    while((temp_char=getchar()) != '\n' && temp_char != EOF){
        buffer_empty=1;
        continue;
    }
    if(buffer_empty){
        return BUFFER_NOT_EMPTY;
    }
    return BUFFER_EMPTY;
}

status_codes createContact(void){
    FILE *fp = fopen("contact_data.txt","a");
    struct contact c;
    status_codes name_limit_exceed=BUFFER_EMPTY,phone_limit_exceed=BUFFER_EMPTY;
    if(fp == NULL){
        return FILE_OPEN_ERROR;
    }
    printf("Enter contact name : ");
    if(fgets(c.name,sizeof(c.name),stdin) == NULL){
        fclose(fp);
        return NAME_READ_FAIL;
    }
    if(c.name[strcspn(c.name,"\n")] == '\0'){
        name_limit_exceed=clear_buffer();
    }
    printf("Enter phone number : ");
    if(fgets(c.phone_no,sizeof(c.phone_no),stdin) == NULL){
        fclose(fp);
        return PHONE_READ_FAIL;
    }
    if(c.phone_no[strcspn(c.phone_no,"\n")] == '\0'){
        phone_limit_exceed=clear_buffer();
    }
    if(name_limit_exceed == BUFFER_NOT_EMPTY || phone_limit_exceed == BUFFER_NOT_EMPTY) {
        fclose(fp);
        return BUFFER_NOT_EMPTY;
    }
    c.name[strcspn(c.name,"\n")]='\0'; 
    c.phone_no[strcspn(c.phone_no,"\n")]='\0';
    fprintf(fp,"%s | %s\n",c.name,c.phone_no);
    fclose(fp);
    return CONTACT_SUCCESS;
}