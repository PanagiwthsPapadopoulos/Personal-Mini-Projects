#include <stdio.h> //constantly feed numbers until limit or maximum sum of numbers given is reached

int main(){
    float number, sum, limit;
    int i, max;
    i = 0;
    sum = 0;
    
    printf("\nDefine the limit of the sum of the numbers: ");
    scanf("%f", &limit);
    printf("Define the limit of the numbers given: ");
    scanf("%d", &max);
    
    while(sum <= limit && i < max ){
        printf("Enter a number: ");
        scanf("%f", &number);
        sum = number + sum;
        i = i + 1;
    } 

    printf("\nThe sum of the given numbers is: %f. There were given %d numbers.", sum, i);

return 0;
}