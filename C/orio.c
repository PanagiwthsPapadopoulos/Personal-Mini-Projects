#include <stdio.h>

int main(){
    int const NUM;
    int sum = 0, i = 0;
    
    do {printf("Please enter a positive integer number: ");
    scanf("%d", &NUM);
    if(NUM<0) printf("Invalid input.\n");
    } while (NUM<0);

    while (sum<NUM){
        i++;
        sum = sum + i;
        printf("\n%d %d", i, sum);
    }

    printf("\nThe number %d is reached after %d numbers.", NUM, i);

    return 0;
}