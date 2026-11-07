#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "my_lib.h"

struct contact {
    char name[NAME_LIMIT],phone_no[PHONE_LIMIT];
};

void string_tolower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

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
    FILE *fp = fopen(CONTACT_FILE,"a");
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
    return ACTION_OK;
}


status_codes viewContact(void){
    FILE *fp=fopen(CONTACT_FILE,"r");
    char buffer[NAME_LIMIT + PHONE_LIMIT + 3];
    int SiNo=0;
    char *separator,*phone_start;
    if(fp == NULL){
        return FILE_OPEN_ERROR;
    }
    while(fgets(buffer,sizeof(buffer),fp) != NULL){
        buffer[strcspn(buffer,"\n")]='\0';
        if(buffer[0] == '\0'){
            continue;
        }

        separator = strstr(buffer," | ");
        if(separator == NULL){
            continue;
        }

        phone_start=separator+3;
        *separator='\0';
        printf("##Person : %d\n",++SiNo);
        printf("Name : %s\n",buffer);
        printf("Phone no : %s\n\n",phone_start);
    }
    if(SiNo == 0){
        printf("No contact found...\n\n");
    }
    fclose(fp);
    return ACTION_OK;
}

status_codes searchContact(void){
    FILE *fp=fopen(CONTACT_FILE,"r");
    int opt=0,scan_res=0,found=0,s_index=0;
    char search[NAME_LIMIT > PHONE_LIMIT ? NAME_LIMIT : PHONE_LIMIT],temp_char,file_buffer[NAME_LIMIT+PHONE_LIMIT+3];
    char *phone;
    if(fp == NULL){
        return FILE_OPEN_ERROR;
    }
    printf("How do you want to search contact\n1, By name\n2, By number\nChoice : ");
    scan_res=scanf("%d",&opt);
    while((temp_char=getchar() != '\n') && temp_char != EOF){
        continue;
    }
    if(scan_res != 1){
        if(scan_res == EOF){
            printf("Input closed..\n");
        }else {
            printf("Invalid input..\n");
        }
        fclose(fp);
        return ACTION_INVALID;
    }

    if(opt != 1 && opt != 2){
        printf("Invalid option..!\n");
        fclose(fp);
        return ACTION_INVALID;
    }

    printf("enter pattern : ");
    fgets(search,sizeof(search),stdin);
    search[strcspn(search,"\n")]='\0';
    string_tolower(search);
    while(fgets(file_buffer,sizeof(file_buffer),fp) != NULL){
        if(opt == 1){
            string_tolower(file_buffer);
            s_index=strcspn(file_buffer,"|");
            file_buffer[s_index]='\0';
            if(strlen(file_buffer) < strlen(search)){
                continue;
            }
            if(matching(search,file_buffer) == FAIL){
                continue;
            }
        }else if(opt == 2){
            s_index=strcspn(file_buffer,"|");
            phone=&file_buffer[s_index+1];
            if(strlen(phone) < strlen(search)){
                printf("len not match\n");
                continue;
            }
            if(matching(search,phone) == FAIL){
                printf("num not match\n");
                continue;
            }
        }
        printf("\n##Matching %d\n",++found);
        printf("Name : %s\n",file_buffer);
        printf("Phone : %s\n",&file_buffer[s_index+1]);
    }
    if(found == 0){
        printf("Didn't found any matching person...!!\n");
    }
    fclose(fp);
    return ACTION_OK;
}

status_codes matching(char *s1, char *s2){
    while(*s1 != '\0'){
        printf("%s , %s\n",s1,s2);
        if(*s1 != *s2) {
            printf("%c , %c\n",*s1,*s2);
            return FAIL;
        }
        s1++;
        s2++;
    }
    return PASS;
}