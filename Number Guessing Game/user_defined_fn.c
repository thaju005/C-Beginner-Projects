#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int lin_getch() {
    struct termios old_settings, new_settings;
    char ch;
    // Save current terminal settings
    tcgetattr(STDIN_FILENO, &old_settings);
    // Copy the current settings
    new_settings = old_settings;
    // Disable Enter requirement and character echo
    new_settings.c_lflag &= ~(ICANON | ECHO);
    // Apply new settings immediately
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    printf("Press any key: ");
    // Read one character immediately
    ch = getchar();
    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
    return ch;
}

int init_game(){
    int random_num,min=1,max=100;
    char ch;
    srand(time(NULL));    
    printf("##########  Number Guessing Game  ##########\n");
    printf("c to change range. Default range is 1 to 100, if you don't want to change press any key\n");
    ch = lin_getch();
    printf("%c\n",ch);

    if(ch == 'c' || ch == 'C'){
        printf("Enter new min : ");
        scanf("%d",&min);
        printf("Enter new max : ");
        scanf("%d",&max);
        if(min > max){
            printf("Invalid range\n");
            exit(1);
        }
    }

    random_num=(rand() % (max - min + 1)) + min;
    return random_num;
}

void find_random(int random_num){
    int guess;
    do{
        printf("Enter number : ");
        while(scanf("%d",&guess) != 1){
            printf("Invalid input, Enter a number : ");
            while(getchar() != '\n')
                continue;
        }
        if(guess < random_num){
            printf("Too low, Try again\n");
        }else if(guess > random_num){
            printf("Too high, Try again\n");
        }else {
            printf("You find it....\n");
        }
    }while(guess != random_num);
}