

#ifndef CUSTOM_LIB
#define CUSTOM_LIB

typedef enum {
    NEW_GAME,
    LOAD_GAME,
    HIGH_SCORE,
    EXIT
}menu_opt;


//Function declarations
void clear_screen(void);
char lin_getch(void);
int menu_getch(void);
int do_action(menu_opt);
void show_how_to_use(void);
void main_menu(int);

#endif