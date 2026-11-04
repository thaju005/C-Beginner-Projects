#include <stdio.h>
#include "user_defined_lib.h"

#define SCORE_FILE "data.txt"
#define SCORE_FMT "best score : %d"

int main(){
    int random_num,best_score;    
    char ch;
    do {
        best_score = load_best();
        random_num=init_game(best_score);
        printf("Random number generated, Find it!!!\n");
        find_random(random_num,best_score);
        printf("\n\nDo you want to play again? (y/n) : ");
        scanf(" %c",&ch);
    }while(ch == 'y' || ch == 'Y');
    printf("Program ended...\n");
}