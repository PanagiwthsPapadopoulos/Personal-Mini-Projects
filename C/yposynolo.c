#include <stdio.h>

int twonum(int list[], int x);
int threenum(int list[], int x);
int fournum(int list[], int x);


int main(){

    int list[5], sum, n = 0;

    printf("Please enter 5 integer numbers: ");
    scanf("%d%d%d%d%d", &list[0], &list[1], &list[2], &list[3], &list[4]);
    printf("Please enter an integer value: ");
    scanf("%d", &sum);

    if(list[0]+list[1]+list[2]+list[3]+list[4] == sum){
        printf("\nThe sum of all integers is equal to %d.", sum);
        n=5;
    } else{
        n = twonum(list, sum); 
        n = threenum(list, sum);
        n = fournum(list, sum);
    }
    
    if( n == 0 ){
        printf("\nNo possible combination of the given numbers is equal to %d.", sum);
    }


return 0;
}



int twonum(int list[], int x){
    int n;
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(list[i] + list[j] == x){
                printf("\nThe sum of %d and %d is equal to %d.", list[i], list[j], x);
                n=2;         
            }
        }
    }
return n;
}

int threenum(int list[], int x){
    int n;
    for(int j=0; j<5; j++){
        for(int k=j+1; k<5; k++){
            for(int l=k+1; l<5; l++){
                if(list[j]+list[k]+list[l] == x){
                    printf("\nThe sum of %d, %d and %d is equal to %d.",list[j], list[k], list[l], x );                
                    n=3;
                }
            }
        }
    }
return n;
}


int fournum(int list[], int x){
    int n;
    for(int j=0; j<5; j++){
        for(int k=j+1; k<5; k++){
            for(int l=k+1; l<5; l++){
                for(int m=l+1; m<5; m++){
                    if(list[j]+list[k]+list[l]+list[m] == x) {
                        printf("\nThe sum of %d, %d, %d and %d is equal to %d.",list[j], list[k], list[l], list[m], x );   
                        n=4;             
                    }
                }
            }
        }
    }
return n;
}