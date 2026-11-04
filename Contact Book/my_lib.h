/*Terminal Functions*/

#ifndef MY_LIB_H
#define MY_LIB_H

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
    CONTACT_SUCCESS
}status_codes;

#endif

void clear_screen();
status_codes createContact();
//