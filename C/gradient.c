#include <stdio.h> // calculate the gradient of the line of two given points
#include <math.h>

int main(){
    float x1, y1 ,x2, y2, g;
    
    printf("\nGive two points in rectangular coordinates M(x1, y1) N(x2, y2): ");
    scanf("%f%f%f%f", &x1, &y1 , &x2, &y2);

    g = (y1 - y2) / (x1 - x2);
    
    if (x1 == x2){
        printf("\nThe gradient cannot be calculated and the line that the two points define is: y = %f", x1);
    }
    else if( (- x1*g + y1) < 0){  
        printf("\nThe gradiend of the line that the two points define is equal to: %f and the line is: y = %fx %f", g, g, -x1*g + y1 );
    }
    else if( (- x1*g + y1) > 0){  
        printf("\nThe gradiend of the line that the two points define is equal to: %f and the line is: y = %fx + %f", g, g, -x1*g + y1 );    
    }
    else if(g == 0){
        printf("\nThe gradiend of the line that the two points define is equal to: %f and the line is: y = %f", x1);
    }
    else{
        printf("\nThe gradiend of the line that the two points define is equal to: %f and the line is: y = %fx", g, g);
    }


return 0;
}