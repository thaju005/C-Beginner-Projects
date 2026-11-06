/*Terminal Functions*/

#ifndef MY_LIB_H
#define MY_LIB_H

#define NAME_LIMIT 61
#define PHONE_LIMIT 21

typedef enum{
    OPT_ADD,
    OPT_VIEW,
    OPT_SEARCH,
    OPT_EDIT,
    OPT_REMOVE,
    OPT_EXIT
}menu_actions;

typedef enum{
    ACTION_INVALID,
    ACTION_EXIT,
    ACTION_OK,
    FILE_OPEN_ERROR,
    CONTACT_SUCCESS,
    BUFFER_EMPTY,
    BUFFER_NOT_EMPTY,
    NAME_READ_FAIL,
    PHONE_READ_FAIL
}status_codes;

#endif

void clear_screen();
status_codes createContact(void);
status_codes clear_buffer(void);
//