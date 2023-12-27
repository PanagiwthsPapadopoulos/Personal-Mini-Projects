#include <stdio.h> // solve a linear equation of the form aY + b + c = 0
#include <string.h>


float solve_for_y(float a, float b, float c){
  float y;  
    if (a == 0){               
        printf("\nUnable to calculate result.");
    }        else{ y = -(b + c) / a;
        }   

return y;
}
 

int main(){
float a, b, c, y;

printf("\nEnter a linear equation in one variable of the form aY + b + c = 0 ");
printf("\nEnter the value of a, b, c respectively: ");

scanf("%f%f%f", &a, &b, &c);

y = solve_for_y( a, b, c);

if (a != 0) printf("\nSolution is Y = %f", y);
 
return 0;
}