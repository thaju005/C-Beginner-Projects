#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define SCORE_FILE "data.txt"
#define SCORE_FMT "best score : %d"

void clear_input(void){
    int c;
    while((c=getchar()) != '\n' && c != EOF);
}

int lin_getch() {
    struct termios old_settings, new_settings;
    char ch;
    static int fn_call=0;
    // Save current terminal settings
    tcgetattr(STDIN_FILENO, &old_settings);
    // Copy the current settings
    new_settings = old_settings;
    // Disable Enter requirement and character echo
    new_settings.c_lflag &= ~(ICANON | ECHO);
    // Apply new settings immediately
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
    printf("Press any key: ");
    if(fn_call == 1){
        clear_input();
    }
    ch = getchar();
    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
    fn_call=1;
    return ch;
}

int load_best(void){
    int best=0;
    FILE *fp = fopen("data.txt","r");
    if(fp == NULL){
        return best;
    }
    fscanf(fp,SCORE_FMT,&best);
    fclose(fp);
    return best;
}

int save_best(int best){
    FILE *fp=fopen("data.txt","w");
    if(fp == NULL){
        return -1;
    }
    fprintf(fp,SCORE_FMT,best);
    fclose(fp);
    return 0;
}

int init_game(int best_score){
    int random_num,min=1,max=100;
    char ch;
    srand(time(NULL));    
    printf("##########  Number Guessing Game  ##########\n");
    if(best_score != 0){
        printf("Best score = %d, (Lowest attempt is the best score)\n",best_score);
    }
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

void find_random(int random_num, int best_score){
    int guess,try=1;
    do{
        printf("Enter number : ");
        while(scanf("%d",&guess) != 1){
            printf("Invalid input, Enter a number : ");
            while(getchar() != '\n')
                continue;
        }
        if(guess < random_num){
            printf("Too low, attempt no : %d\n",try++);
        }else if(guess > random_num){
            printf("Too high, attempt no : %d\n",try++);
        }else {
            if(try < best_score || best_score == 0){
                if(save_best(try) != 0){
                    printf("Failed to save best score");
                }
            }
            printf("You find on attend no : %d....\n",try);
        }
    }while(guess != random_num);
}