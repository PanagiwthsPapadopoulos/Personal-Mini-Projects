#include <stdio.h> // calculate sum of consecutive integers

int main(){

    int num, sum = 0;
    
    do{
    printf("\nEnter the maximum integer:");
    scanf("%d", &num);   
    }while(num < 0);   

    for(int i = 0; i <= num; i++){
        sum = sum + i;
    }

    printf("The sum of all the integers until the given one is: %d", sum);

return 0;
}


