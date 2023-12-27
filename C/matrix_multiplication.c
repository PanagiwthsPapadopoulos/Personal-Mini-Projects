#include <stdio.h>
#include <stdlib.h>

void function(float matrix1[100][100], float matrix2[100][100], int dim11, int dim12, int dim21, int dim22){
    float a[100][100];
    for(int i=0; i<dim11; i++){
        for(int k=0; k<dim22; k++){
            for(int j=0; j<dim12; j++){
                a[i][k] = a[i][k]+ matrix1[i][j] * matrix2[j][k];
            }
        }
    }

    for(int i=0; i<dim11; i++){
        for(int j=0; j<dim22; j++){
            printf("%5.2f  ", a[i][j]);
        }
        printf("\n");
    }

}


int main(){

    int dim11, dim12;
    
    do{
        printf("First Matrix dimensions(>1): ");
        scanf("%d", &dim11);
        scanf("%d", &dim12);
    }while(dim11<2 || dim12<2);

    float matrix1[100][100];
    
    for(int i=0; i<dim11; i++){
        for(int j=0; j<dim12; j++){
            printf("_  ");
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<dim11; i++){
        printf("Row No.%d elements:", i+1);
        for(int j=0; j<dim12; j++){
            scanf("%f", &matrix1[i][j]);
        }
    }


    int dim21, dim22;
    
    do{
        printf("Second Matrix dimensions(>1): ");
        scanf("%d", &dim21);
        scanf("%d", &dim22);
    }while(dim21<2 || dim22<2);

    if(dim12!=dim21){
        printf("This operation is not valid.\nTERMINATING PROGRAM.");
        exit(-1);
    }

    float matrix2[100][100];

    for(int i=0; i<dim21; i++){
        for(int j=0; j<dim22; j++){
            printf("_  ");
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0; i<dim21; i++){
        printf("Row No.%d elements:", i+1);
        for(int j=0; j<dim22; j++){
            scanf("%f", &matrix2[i][j]);
        }
    }
    printf("\n---------------------------------------------------------------------------------------------\n");
   
    function(matrix1, matrix2, dim11, dim12, dim21, dim22);

    return 0;
}