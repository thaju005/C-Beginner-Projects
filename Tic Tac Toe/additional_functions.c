#include <stdlib.h>
#include <time.h>

int generate_random_num(){
    srand(time(NULL));
    int min=1, max=2, ranged_random;
    ranged_random = (rand() % (max - min + 1)) + min;
    return ranged_random;
}