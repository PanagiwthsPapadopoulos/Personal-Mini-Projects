#include <stdio.h>
#include <math.h>
#include <ctype.h>

int check(int x){
    
    int sum=0;
    
    for(int i=1; i<x; i++){
        if(x%i == 0) sum = sum + i;
    }

    return sum;
}

int main(){

    int num, num1, mod;

    printf("Please enter the space of numbers: ");
    scanf("%d%d", &num, &num1);

    for(int i=num; i<=num1 ; i++){
        
        mod = check(i);

        if(mod == i){
            printf("\nThe number %d is perfect.", i);
        } else if(mod > i){
            printf("\nThe number %d is abundant.", i);
        } else printf("\nThe number %d is deficient.", i);
    
    }
    

    return 0;
}