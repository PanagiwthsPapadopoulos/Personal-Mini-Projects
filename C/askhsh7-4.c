#include<stdio.h>
#include<stdlib.h>


int main(){

    int array[10], i=1;
    array[0]=1;

    while(i<10){
        array[i]=0;
        array[i]=rand();
        if(array[i-1]<array[i]) i++; 
    }

    for(int k=0; k<10; k++){
        printf("Array element No.%d is: %12d.\n", k, array[k]);
    }

    return 0;
}