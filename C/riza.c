#include <stdio.h>

int main(){

float num, guess, res;
int q = 15;                                                                  // adjust precision
do {printf("Please enter a positive number whose root to calulate: ");
    scanf("%f", &num);
    if(num<0) printf("Invalid input.\n");
    } while (num<0);

printf("Please enter an initial guess: ");
scanf("%f", &guess);

for(int i=0; i<q; i++){
    res = 0.5*( (guess) + (num)/(guess) );
    guess = res;
}


printf("\nThe square root of %lf is %lf.", num, res );

return 0;
}