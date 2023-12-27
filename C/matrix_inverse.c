#include <stdio.h>
#include <math.h>



float det(float A[100][100], int n);

float adja[100][100];


void adj(float A[100][100], int n)
{
    float temp[100][100], determinant;
    int i,j;
    int O=1;
    determinant = det(A, n);
    for(int q=0; q<n; q++){
        for(int l=0; l<n; l++){
            O = pow((-1), q+l);
            //printf("O = %d", O);
            if(n == 2){
                adja[q][l] = O*A[n-l-1][n-q-1];
            }
            //MAKING THE MATRIX FOR ITS DETERMINANT TO BE CALCULATED
            //THE DETERMINANT IS EQUAL TO THE ADJ OF THE SPECIFIC ELEMENT OF THE INITIAL MATRIX
            else{
                i=0, j=0;
                for(int k=0; k < n-1; k++){                                   //TRACING POSITION OF THE TEMP MATRIX
                    for(int m=0; m < n-1; m++){
                        for(i; i<n; i++){
                            if(i==q) i++;                           
                            for(j; j<n; j++){                     //TRACING ELEMENTS OF INITIAL MATRIX FOR THE TEMP MATRIX
                                if(j==l) j++;
                                if(j>=n){
                                     j=0;
                                    if(i+1==q) i=i+2;
                                    else i++;
                                }
                                temp[k][m]=A[i][j];
                                printf("%f  %f\n",temp[k][m],A[i][j]);
                                j++;
                                break;
                            }
                            if(j==n){
                                i++;
                                j=0;
                            }
                            break;
                        }
                    }
                }
                adja[l][q] = ( (O*det(temp, n-1)) / determinant);
            }
        }
    }                

}



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
    
    printf("\n---------------------------------------------------------------------------------------------\n\n");
    for(int i=0; i<dim; i++){
        for(int j=0; j<dim; j++){
            printf("%5.2f  ", matrix[i][j]);
        }
        printf("\n");
    }

    res=det(matrix, dim);
    printf("\n\nThe determinant of the matrix is %f.\n", res);

    //if(res==0) printf("The matrix does not have an inverse.");
    //else{
        adj(matrix, dim);
        printf("\nThe inverse matrix:\n\n");
        for(int i=0; i<dim; i++){
            for(int j=0; j<dim; j++){
                printf("%5.2f  ", adja[i][j]);
            }
            printf("\n");
        }
    //}

    return 0;
}