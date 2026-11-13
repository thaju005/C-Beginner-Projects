#include <stdio.h>

int main(){
    int size=3;
    for(int i=1;i<=size;i++){
        printf("\n|-----------------|\n|");
        for(int j=1;j<=size;j++){
            printf("  %d  |",i);
        }
    }
    printf("\n|-----------------|\n");
}