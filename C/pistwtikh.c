#include <stdio.h>
#include <math.h>
#include <ctype.h>

int first(int list[]);
int second(int list[]);

int main(){

    int list[16], i=0;

    do {
        
        if(i == 0) printf("Please enter the 1st number of your credit card: ");
        if(i == 1) printf("Please enter the 2nd number of your credit card: ");
        if(i == 2) printf("Please enter the 3rd number of your credit card: ");
        if(i > 2) printf("Please enter the %dth number of your credit card: ", i+1);

        scanf("%d", &list[i]);
    
        if(list[i] < 0 || list[i] > 9){
            printf("Invalid input.\n");
            i = i - 1;
        } 
        
        i++;
        
    } while (i < 16);


    if( (first(list)+second(list))%10 == 0 ){
        printf("\nThe credit card number is valid.");
    }else printf("\nThe credit card number is not valid.");

    return 0;
}


int first(int list[]){

    int u, num = 0;

    for(int i=0; i<16; i=i+2){
             
        if( (2*list[i]) > 9){

            for(int j=0; j<=8; j++){
                if( ((2*list[i]) - j)%10 == 0 ) u = 1 + j;
            }      
        
        }else u = 2*list[i];
        
        num = num + u;
    }
    return num;
}


int second(int list[]){

    int num=0;
    for(int i=1; i<16; i=i+2){
        num = num + list[i];
    }
    printf("second%d", num);
    return num;
}