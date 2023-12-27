#include <stdio.h>      // bolzano
#include<math.h>

int equation(int coefficient[]);
void range(double space[]);
int values(int coefficient[], double space[], double value[], int cl);
int roots(int coefficient[], double space[], double value[], int cl);

int main(){

    int cl, coefficient[4], res, root;        //συντελεστες του χ
    double space[3], value[3];      // ακρα του διαστηματος και τιμες για τα χ των ακρων   'space[2]' ειναι το μεσο του διαστηματος   value[2] einai h timh toy mesou toy diasthmatos
    
    
    cl = equation(coefficient);
    
    range(space);
    space[2] = (space[0] + space[1]) / 2 ;
    values(coefficient, space, value, cl);
    
    res = values(coefficient, space, value, cl);
    root = roots(coefficient, space, value, cl);
    
    if(res == 1){
        printf("\nThere is at least one solution of the equation in the given space."); 
        for(int i=0; i<10; i++){       
            if(root == 1) {
                space[1] = space[2];
                value[1] = value[2];
            }
            else {
                space[0] = space[2];
                value[0] = value[2];
            }
            values(coefficient, space, value, cl);
            space[2] = (space[0] + space[1]) / 2 ;
            root = roots(coefficient, space, value, cl);
                    
        }
        printf("\nThe solution is close to %f. ", space[2]);
    }else printf("to mpoylo");


return 0;
}



int equation(int coefficient[]){                                                                 // identify the class and the equation itself
    int x;
    do{
    printf("\nEnter the class of equation: ");
    scanf("%d", &x);   
    }while(x < 1 && x > 3);

    switch(x){
        case 3:
        printf("\nEnter the coefficient of the third power: ");
        scanf("%d", &coefficient[3]);
        printf("\nEnter the coefficient of the second power: ");
        scanf("%d", &coefficient[2]);
        printf("\nEnter the coefficient of the first power: ");
        scanf("%d", &coefficient[1]);
        printf("\nEnter the value of the constant term: ");
        scanf("%d", &coefficient[0]);
        break;
        case 2:
        printf("\nEnter the coefficient of the second power: ");
        scanf("%d", &coefficient[2]);
        printf("\nEnter the coefficient of the first power: ");
        scanf("%d", &coefficient[1]);
        printf("\nEnter the value of the constant term: ");
        scanf("%d", &coefficient[0]);
        coefficient[3] = 0;
        break;
        default:
        printf("\nEnter the coefficient of the first power: ");
        scanf("%d", &coefficient[1]);
        printf("\nEnter the value of the constant term: ");
        scanf("%d", &coefficient[0]);
        coefficient[3] = 0;
        coefficient[2] = 0;
        break;
    }

    switch(x){
        case 3:
        printf("The equation is: (%d)x^3 + (%d)x^2 + (%d)x + (%d) = 0 \n", coefficient[3], coefficient[2], coefficient[1], coefficient[0]);
        break;
        case 2:
        printf("The equation is: (%d)x^2 + (%d)x + (%d) = 0 \n", coefficient[2], coefficient[1], coefficient[0]);
        break;
        default:
        printf("The equation is: (%d)x + (%d) = 0 \n", coefficient[1], coefficient[0]);
        break;
    }

return x;
}



void range(double space[]){                                                           //read the space to search the root in
    double left, right;

    printf("\nEnter the space to search for a solution: ");
    scanf("%lf%lf", &left, &right);
    space[0] = left;
    space[1] = right;
}


int values(int coefficient[], double space[], double value[], int cl){                 //calculates sign of the two different values
    double first, second;
    int x;

    first = ( (pow(space[0], 3)) * coefficient[3] ) + ( (pow(space[0], 2)) * coefficient[2] ) + ( (space[0]) * coefficient[1] ) + ( coefficient[0] );
    second = ( (pow(space[1], 3)) * coefficient[3] ) + ( (pow(space[1], 2)) * coefficient[2] ) + ( (space[1]) * coefficient[1] ) + ( coefficient[0] );

    value[0] = first;
    value[1] = second;
    if(first * second < 0) x = 1;
    else x = 0;

return x;
}    

int roots(int coefficient[], double space[], double value[], int cl){                 //determines which part of the space the root is located.
    double middle, bit1, bit2;
    int x;

    space[2] = (space[0] + space[1]) / 2 ;
    
    middle = ( pow(space[2], 3) * coefficient[3] ) + ( pow(space[2], 2) * coefficient[2] ) + ( space[2] * coefficient[1] ) + ( coefficient[0] );

    value[2] = middle;
    bit1 = value[0] * middle;
    bit2 = value[1] * middle;

    if( bit2 < 0) x = 2;
    
    if( bit1 < 0)  x = 1;

return x;
}    
