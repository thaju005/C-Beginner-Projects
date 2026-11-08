#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

void clear_screen(void){
    system("clear");
}



char lin_getch(void){
    struct termios orig, raw;
    char c;
    // Save current settings
    tcgetattr(STDIN_FILENO, &orig);

    raw = orig;
    raw.c_lflag &= ~(ICANON | ECHO);  // no line buffering, no echo
    raw.c_cc[VMIN] = 1;               // read returns after 1 byte
    raw.c_cc[VTIME] = 0;              // no timeout
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    read(STDIN_FILENO, &c, 1);

    // Restore original settings
    tcsetattr(STDIN_FILENO, TCSANOW, &orig);
    return c;
}

int menu_getch(void){
    struct termios orig, raw;
    char c;
    int result = 0;                   // 0 = any other key

    // Save current settings
    tcgetattr(STDIN_FILENO, &orig);

    raw = orig;
    raw.c_lflag &= ~(ICANON | ECHO);  // no line buffering, no echo
    raw.c_cc[VMIN] = 1;               // read returns after 1 byte
    raw.c_cc[VTIME] = 0;              // no timeout
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);

    if (read(STDIN_FILENO, &c, 1) == 1) {
        if (c == 27) {
            // Short timeout so a plain Escape press doesn't hang
            raw.c_cc[VMIN] = 0;
            raw.c_cc[VTIME] = 1;
            tcsetattr(STDIN_FILENO, TCSANOW, &raw);

            char seq[2];
            if (read(STDIN_FILENO, &seq[0], 1) == 1 &&
                read(STDIN_FILENO, &seq[1], 1) == 1 &&
                (seq[0] == '[' || seq[0] == 'O')) {
                if (seq[1] == 'A') result = 0;       // up
                else if (seq[1] == 'B') result = 1;  // down
            }
        }
        else if (c == '\n' || c == '\r') result = 2; // enter
        else if (c == 'h' || c == 'H') result = 3;   // h
    }

    // Restore original settings
    tcsetattr(STDIN_FILENO, TCSANOW, &orig);
    return result;
}