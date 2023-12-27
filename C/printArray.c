#include <stdio.h>

void array2d(void);
void array3d(void);
void array4d(void);


int main(){
    int type;
    
    do{
    printf("\nSelect the type of array to print ( 2d or 3d or 4d ): ");
    scanf("%d", &type);
    } while(type < 2 || type > 4);

    if(type == 2) array2d();
    else if(type == 3) array3d();
    else array4d();

return 0;
}




void array2d(void){
    int num[10][10];
    int k = 0;
    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10; j++){
            num[i][j] = k;
        k++;
        }
    }

    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10; j++){
            printf(" %d ", num[i][j]);
        }
    printf("\n");
    }
}

void array3d(void){
    int num[10][10][10];
    int k = 0;
    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10; j++){
            for(int l = 0; l < 10; l++){
                num[i][j][l] = k;
                k++;
            }
        }
    }

    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10; j++){
            for(int l = 0; l < 10; l++){
                printf(" %d ", num[i][j][l]);
            }
        }
    }
}


void array4d(void){
    int num[10][10][10][10];
    int k = 0;
    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10; j++){
            for(int l = 0; l < 10; l++){
               for(int m = 0; m < 10; m++){
                num[i][j][l][m] = k;
                k++;
                }
            }
        }
    }

    for(int i = 0 ; i < 10; i++){
        for(int j = 0 ; j < 10; j++){
            for(int l = 0; l < 10; l++){
                for(int m = 0; m < 10; m++){
                    printf(" %d ", num[i][j][l][m]);
                }
            }
        }
    }
}