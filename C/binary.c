#include<stdio.h>


int main(){

    int num[64];
    int numb, i=0;

    printf("Enter an integer number: ");
    scanf("%d", &numb);


    while(numb>0){
        num[i]=numb%2;
        numb = numb/2;
        i++;
    }
    
    
    i--;
    printf("\nThe binary number is: ");
    
    
    for(; i>-1; i--){
        printf("%d", num[i]);
    }
    
    
    
    return 0;
}