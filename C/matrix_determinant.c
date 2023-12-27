#include <stdio.h>

float det(float A[100][100], int n)
{
    float Minor[100][100];
    int i,j,k,c1,c2;
    float deter=0;
    //int c[100];
    int O=1;
    if(n == 2)
    {
        deter = (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]) ;
        return deter;
    }
    else{
        for(i=0; i<n; i++){
            c1=0, c2=0;
            for(j=1; j<n; j++){
                for(k=0; k<n; k++){
                    if(k!=i){
                        Minor[c1][c2] = A[j][k];
                        c2++;
                        if(c2>n-2){
                            c1++;
                            c2=0;
                        }
                    }
                }
            }
            deter = deter +O*(A[0][i]*det(Minor, n-1));
            O=-1*O;
        }
    }
    return deter;
}

int main(){

    int dim;
    
    do{
        printf("Square matrix dimensions(>1): ");
        scanf("%d", &dim);
    }while(dim<2);

    float matrix[100][100], res;
    
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("_  ");
        }
        printf("\n");
    }
    printf("\n");

    for(int i=0; i<dim; i++){
        printf("Row No.%d elements:", i+1);
        for(int j=0; j<dim; j++){
            scanf("%f", &matrix[i][j]);
        }
    }
    
    printf("\n---------------------------------------------------------------------------------------------\n");
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("%5.2f  ", matrix[i][j]);
        }
        printf("\n");
    }

    res=det(matrix, dim);
    printf("The determinant of the matrix is %f.\n", res);

    return 0;
}