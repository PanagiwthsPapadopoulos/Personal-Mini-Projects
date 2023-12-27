#include <stdio.h>

int square(int q);

int main(){
    int num, sum=0;

    do {printf("Please enter a positive integer number: ");
    scanf("%d", &num);
    if(num<0) printf("Invalid input.\n");
    } while (num<0);

    num = square(num);

    if(num == 0) printf("\nNumber squared is equal to 0.");
    else{
        printf("The number squared is equal to %d", num); 
    }


return 0;    
}


int square(int q){
    int sum;
   
    for(int i=1; i<q; i++){
        sum = sum + i;
    }
    
    sum = 2*sum + q;

return sum;
}

