#include<stdio.h>
#include <unistd.h>


int main(){


    for(int i=0; i<5; i++){
        printf("%d\n", i+1);
        sleep(1);
    }
    printf("TO MPAOYLO\n");

    return 0;
}