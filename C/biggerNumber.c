#include <stdio.h> // feed numbers and then determine if one other number belongs in the array

void order(float numbers[], int size);
float yes(int size, float numbers[], float num);

int main(){

    int size = 0;
    float numbers[size], temp, num;


    do{ 
    printf("\nEnter a number: ");        //scans given numbers and places them in the array
    scanf("%f", &temp);
    numbers[size] = temp;
    size = size++ ;
    }while(temp != 9999);

    

    order(numbers, size);

    printf("Give number to test if it exists: ");
    scanf("%f", &num);

    
    temp = yes(size, numbers, num);
    printf("The number is in the position %d", &temp);




return 0;
}

void order(float numbers[], int size)
{
    
    float min, x;
    
    for (int i = 0; i < size; i++ ){                       //ranking subjects inside the array
        int min = numbers[i];
        for ( int j = i + 1; j < size; j++){
            if(min > numbers[j]){
                min = numbers[j];
                x = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = x;
            }
        }
    }

}



float yes(int size, float numbers[], float num){
    int position;
    int space[2] ={0,size};
    
    do{
                
        if (num > numbers[size/2]){
            space[0] = (size/2) ;
        }
        else if (num < numbers[size/2]){
            size = (size/2) ;
        }
    }while(num != numbers[position]);

return position;        
}