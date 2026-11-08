/*Terminal Functions*/

#ifndef MY_LIB_H
#define MY_LIB_H

#define NAME_LIMIT 61
#define PHONE_LIMIT 21
#define CONTACT_FILE "contact_data.txt"
#define TEMP_FILE "temp_data.txt"
#define TEMP_FILE_T1 "temp_t1.txt"

typedef enum{
    OPT_ADD,
    OPT_VIEW,
    OPT_SEARCH,
    OPT_EDIT,
    OPT_REMOVE,
    OPT_EXIT,
    CLR_SCREEN
}menu_actions;

typedef enum{
    ACTION_INVALID,
    ACTION_EXIT,
    ACTION_OK,
    FILE_OPEN_ERROR,
    BUFFER_EMPTY,
    BUFFER_NOT_EMPTY,
    NAME_READ_FAIL,
    PHONE_READ_FAIL,
    FAIL,
    PASS,
    INVALID_PERSON
}status_codes;

#endif

void clear_screen();
status_codes createContact(void);
status_codes clear_buffer(void);
status_codes viewContact(int*);
status_codes searchContact(void);
status_codes matching(char*,char*);
status_codes editContact(void);
status_codes removeContact(void);
//