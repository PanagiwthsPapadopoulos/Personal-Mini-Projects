#include <stdio.h>      // calculates the units of time needed for a POSITIVE value to reach a limit with a steady growth or drop percentage

int main(){
    int time = 0;
    double val, n, lim;
    
    printf("\nEnter the initial value: ");
    scanf("%lf", &val );
    
    printf("Enter the rate of increase or decrease (negative sign for decrease) per unit of time (in \%): ");
    scanf("%lf", &n);

    printf("Enter the maximum or minimum limit of the value: ");
    scanf("%lf", &lim);
    
    n = n / 100;
    
    if(val <= 0 && lim <= 0 ) printf("Unable to calculate result.");    
    else if(n == 0 || lim == val) printf("The value is already at its limit.");
    else if(val < lim && n > 0){
        while(lim > val){
            val = val + (val * n);
            time = time + 1;
        } 
        printf("The limit of the value will be reached after %d units of time.", time);
        }   
    else if(val > lim && n < 0){
            while(lim < val){
                val = val + (val * n);
                time = time + 1;
            } 
        printf("The limit of the value will be reached after %d units of time.", time);
        }
return 0;
}