#include <stdio.h> // solve a quadratic equation of the form aY^2 + bY + c = 0
#include <string.h>
#include <math.h>

int main(){
    float a, b, c, y, y1, y2, D;

    printf("\nEnter a quadratic equation in one variable of the form aY^2 + bY + c = 0 with a =/= 0");
    printf("\nEnter the value of a, b, c respectively: ");

    scanf("%f%f%f", &a, &b, &c);
    D = b * b - 4 * a * c;
    if( a == 0 ){
        printf("\nInvalid input.");
        }
        else if (D == 0){
            y = ( (-b ) / (2 * a) );
            printf("\nSolution is Y = %f", y);
        }
        else if (D > 0) {
            y1 = ( -b + sqrt(D)) / (2* a);
            y2 = ( -b - sqrt(D)) / (2* a);  
            printf("The equation has two possible solutions. Y = %f or Y = %f", y1, y2);
        }
        else {
            printf("\nThe equation has no possible solutions.");
        }
return 0;
}