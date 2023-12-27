#include <stdio.h>  //rearrange numbers in an array in descending order --> from highest to lowest

int main(){

    int temp, size;
    int numbers[size];

    printf("Enter the number of subjects:");        //determines how many numbers
    scanf("%d", &size);

    for(int i = 0; i < size; i++){          // puts given numbers in the array
        int x;
        printf("Enter number: ");
        scanf("%d", &x);
        numbers[i] = x;
    }

    for (int i = 0; i < size; i++ ){
        int max = numbers[i];
        for ( int j = i + 1; j < size; j++){
           if(max < numbers[j]){
              max = numbers[j];
              temp = numbers[i];
              numbers[i] = numbers[j];
              numbers[j] = temp;
          }
      }
    }

    for (int i = 0; i < size; i++){
      printf("%d  ", numbers[i]);
    }  


    return 0;
}