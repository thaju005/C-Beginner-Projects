#include <stdio.h>
#include <string.h>
#include "my_lib.h"

struct contact {
    char name[61],phone_no[21];
};

status_codes createContact(){
    FILE *fp = fopen("contact_data.txt","a");
    struct contact c;
    if(fp == NULL){
        return FILE_OPEN_ERROR;
    }
    printf("Enter contact name : ");
    fgets(c.name,sizeof(c.name),stdin);
    printf("Enter phone number : ");
    fgets(c.phone_no,sizeof(c.phone_no),stdin);
    c.name[strcspn(c.name,"\n")]='\0'; 
    c.phone_no[strcspn(c.phone_no,"\n")]='\0';
    fprintf(fp,"%s | %s\n",c.name,c.phone_no);
    fclose(fp);
    return CONTACT_SUCCESS;
}