

#ifndef CUSTOM_LIB
#define CUSTOM_LIB

#define SCORE_FILE "score.txt"
#define CURRENT_DATA "current_data.txt"
#define PLAYER_NAME_SIZE 21

typedef enum {
    NEW_GAME,
    LOAD_GAME,
    HIGH_SCORE,
    GAME_EXIT
}menu_opt;

typedef enum {
    PRGM_STARTED,
    EXIT,
    INVALID_OPTION,
    FILE_OPEN_ERROR,
    SUCCESS,
    FAIL
}status_codes;

typedef struct {
    char name[PLAYER_NAME_SIZE];
}player_data;


/**
 * Function declarations
 */
//Terminal Functions
void clear_screen(void);
char lin_getch(void);
int clear_buffer(void); 

//Interface Functions
int menu_getch(void);
void main_menu(int);

//Action Functions
status_codes do_action(menu_opt);
void action_message(status_codes);
status_codes new_game(void);

//Help Functions
void show_how_to_use(void);

//File functions
FILE* reset_current_game_file();


#endif