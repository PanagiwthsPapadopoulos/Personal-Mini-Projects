//                                                DEVELOPERS: ΠΑΠΑΔΟΠΟΥΛΟΣ ΠΑΝΑΓΙΩΤΗΣ - ΚΑΡΓΙΩΤΗΣ ΑΛΕΞΑΝΔΡΟΣ.
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 50                     //μεγιστη διασταση συστοιχιας, δεν ελεγχεται στο προγραμμα
#define NAMES_MAX_SIZE 30               //μεγιστη διασταση ονοματος συστοιχιας, δεν ελεγχεται στο προγραμμα
#define DIRECTORY_SIZE 70               //μεγιστη διασταση της θεσης αρχειου με συστοιχια, αναφερεται στη συναρτηση local_matrix


float A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE], TEMP[MAX_SIZE][MAX_SIZE];            //ενεργοποιημενοι πινακες (τρρεις πιθανες θεσεις )
char a[NAMES_MAX_SIZE], b[NAMES_MAX_SIZE], c[NAMES_MAX_SIZE];                                                   //ονοματα των ενεργοποιημενων πινακων
int dim11=0, dim12, dim21=0, dim22, dim31=0, dim32;                                                             //διαστασαεις των ενεργοποιημενων πινακων


int k;double sin(),cos();

void easter_egg(){int num;float A=
       0,B=0,i,j,z[1760];char b[
     1760];printf("\x1b[d");for(;;
  ){memset(b,32,1760);memset(z,0,7040)
  ;for(j=0;6.28>j;j+=0.07)for(i=0;6.28
 >i;i+=0.02){float c=sin(i),d=cos(j),e=
 sin(A),f=sin(j),g=cos(A),h=d+2,D=1/(c*
 h*e+f*g+5),l=cos      (i),m=cos(B),n=s\
in(B),t=c*h*g-f*        e;int x=40+30*D*
(l*h*m-t*n),y=            12+15*D*(l*h*n
+t*m),o=x+80*y,          N=8*((f*e-c*d*g
 )*m-c*d*e-f*g-l        *d*n);if(22>y&&
 y>0&&x>0&&80>x&&D>z[o]){z[o]=D;;;b[o]=
 ".,-~:;=!*#$@"[N>0?N:0];}}/*#****!!-*/
  printf("\x1b[d");for(k=0;1761>k;k++)
   putchar(k%80?b[k]:10);A+=0.005;B+=
     0.0005;}}

void input(int dim1, int dim2){                             // η συναρτηση ελεγχει αν ο χρηστης επιθυμει να αποθηκευσει τη συστοιχια που προεκυψε
    char matrix_confirm, matrix_name[NAMES_MAX_SIZE];
    FILE *fptr;
    printf("\n");
    printf("Αποθήκευση Συστοιχίας;(y/n)");
    scanf(" %c", &matrix_confirm);  
    switch(matrix_confirm){
        case 'n': printf("Η συστοιχία δεν αποθηκεύτηκε.");
        break;
        case 'y': 
            printf("Είσοδος αναγνωριστικού: ");
            fflush(stdin);
            fgets(matrix_name,NAMES_MAX_SIZE,stdin);
            //fflush(stdin);
            matrix_name[strcspn(matrix_name, "\n")]='\0';
            fptr = fopen(strcat(matrix_name, ".txt"),"w");
                for(int i=0; i<dim1; i++){
                    for(int j=0; j<dim2; j++){
                        fprintf(fptr,"%f ",TEMP[i][j]);
                    }
                    fprintf(fptr,"\n");
                } 
                fclose(fptr);
                printf("Η συστοιχία αποθηκεύτηκε επιτυχώς.");
               fflush(stdin);
        break;

        default: fflush(stdin);
                scanf(" %c", &matrix_confirm); 
    }
}

int vector_check(int dim){                                  //η συναρτηση ελεγχει αν η συστοιχια αποτελει διανυσμα(πινακα γραμμη)
    if(dim>1) {
    return 0;                                               //επιστρεφει τιμη 0 αν δεν αποτελει διανυσμα
    }else return 1;                                         //αλλιως 1
}

float determinant(float mat[MAX_SIZE][MAX_SIZE], int column, int row){              //η συναρτηση υπολογιζει τη διακρινουσα ενος πινακα αφου ελεγξει αν ειναι τετραγωνικος
    float Minor[MAX_SIZE][MAX_SIZE];
    int i,j,k,c1,c2,n;
    float deter=0;
    int O=1;
    
    if(column!=row){
         printf("Ο πίνακας δεν είναι τετραγωνικός.");
         deter = 0.0001;
         return deter;
    }
    else{
        n = column;
        if(n == 2)
        {
            deter = (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]) ;
            return deter;
        }
        else{
            for(i=0; i<n; i++){
                c1=0, c2=0;
                for(j=1; j<n; j++){
                    for(k=0; k<n; k++){
                        if(k!=i){
                            Minor[c1][c2] = mat[j][k];
                            c2++;
                            if(c2>n-2){
                                c1++;
                                c2=0;
                            }
                        }
                    }
                }
                deter = deter +O*(mat[0][i]*determinant(Minor, n-1, n-1));
                O=-1*O;
            }
        }
    }
    return deter;
}

void matmul(float matrix1[MAX_SIZE][MAX_SIZE], float matrix2[MAX_SIZE][MAX_SIZE], int dim11, int dim12, int dim21, int dim22){              //συναρτηση για τον πολλαπλασιασμο πινακων
    
    if(!(dim12==dim21)) printf("Ο πολλαπλασιασμός αυτών των πινάκων δεν είναι δυνατός.\n");
    else{
        printf("O πίνακας είναι ο παρακάτω: \n");
        for(int i=0; i<dim11; i++){
            for(int k=0; k<dim22; k++){
                for(int j=0; j<dim12; j++){
                    TEMP[i][k] = TEMP[i][k] + (matrix1[i][j] * matrix2[j][k]);
                }
            }
        }

        for(int i=0; i<dim11; i++){
            for(int j=0; j<dim22; j++){
                printf("%f\t", TEMP[i][j]);
            }
            printf("\n");
        }
    }

    input(dim11,dim22);
}

void adjoint(float mat[MAX_SIZE][MAX_SIZE], int column, int row){               //συναρτηση για την ευρεση προσαρτημενου πινακα
    float tempo[MAX_SIZE][MAX_SIZE], det;
    int i,j,n = column;
    int O=1;
     if(column==row) 
        {
        for(int q=0; q<n; q++){
            for(int l=0; l<n; l++){
                O = pow((-1), q+l);
            //printf("O = %d", O);
                if(n == 2){
                    TEMP[q][l] = O*mat[n-l-1][n-q-1];
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
                                    tempo[k][m]=mat[i][j];
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
                    TEMP[l][q] = ( (O*determinant(tempo, n-1,n-1)) );
                }
            }
        }                
    }
    if(det!=0){
        printf("O αναστροφος πίνακας είναι ο:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%f\t", TEMP[i][j]);
        }
        printf("\n");
    }
    
    input(n,n);
    }
}

void inverse(float mat[MAX_SIZE][MAX_SIZE], int column, int row){               //συναρτηση για την ευρεση αντιστροφου πινακα
    float tempo[MAX_SIZE][MAX_SIZE], det;
    int i,j,n = column;
    int O=1;
    det = determinant(mat, column,row);    
    if(det==0) printf("Σφάλμα. Ο πίνακας εχει διακρίνουσα 0.");
    else if(column==row) 
        {
        for(int q=0; q<n; q++){
            for(int l=0; l<n; l++){
                O = pow((-1), q+l);
            //printf("O = %d", O);
                if(n == 2){
                    TEMP[q][l] = O*mat[n-l-1][n-q-1];
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
                                    tempo[k][m]=mat[i][j];
                                    //printf("%f  %f\n",tempo[k][m],mat[i][j]);
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
                    TEMP[l][q] = ( (O*determinant(tempo, n-1,n-1)) / det );
                }
            }
        }                
    
    
        printf("O αντιστροφος πίνακας είναι ο:\n");
    
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
              printf("%f\t", TEMP[i][j]);
            }
            printf("\n");
        }
    
    input(n,n);
    }
}

void matsmul(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, double scalor){          //συναρτηση για τον πολλαπλασιασμο πινακα με αριθμο
    printf("Ο πίνακας είναι ο:\n");
    for(int i=0;i<dim1;i++){
        for(int j=0;j<dim2;j++){
            printf("%f\t", scalor*matrix[i][j]);
            TEMP[i][j] = scalor*matrix[i][j];
        }
        printf("\n");
    }
    input(dim1,dim2);
}

void trans(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2){                           //συναρτηση για την ευρεση αναστροφου πινακα
    printf("Ο πίνακας είναι ο: \n");
    for(int i=0; i<dim2; i++){
        for(int j=0; j<dim1; j++){
            printf("%f\t", matrix[j][i]);
            TEMP[i][j] = matrix[j][i];
        }
        printf("\n");
    }
    input(dim2,dim1);
}

void oppos(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2){
    printf("Ο πίνακας είναι ο: \n");
    for(int i=0; i<dim1; i++){
        for(int j=0; j<dim2; j++){
            if(matrix[i][j]==0) printf("%f\t", matrix[i][j]);
            else printf("%f\t", -matrix[i][j]);
            
            if(matrix[i][j]==0) TEMP[i][j] = matrix[i][j];
            else TEMP[i][j] = -matrix[i][j];
        }
        printf("\n");
    }
    input(dim1,dim2);
}

void rowadd(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int row_){       //συναρτηση για την προσθεση μεταξυ σειρων ενος πινακα
    if(row_+1>dim1 || row_+1<=0) printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(i==row) {
                    TEMP[i][j] = matrix[i][j]+matrix[row_][j];
                    printf("%f\t",matrix[i][j]+matrix[row_][j]);
                }
                else {
                    TEMP[i][j] = matrix[i][j];
                    printf("%f\t",matrix[i][j]);
                }
            }
            printf("\n");
        }
        input(dim1,dim2);
    }
}

void rowmul(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int row_){           //συναρτηση για τον πολλαπλασιασμο μεταξυ σειρων ενος πινακα
    if(row_+1>dim1 || row_+1<=0) printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(i==row) {
                    TEMP[i][j] = (matrix[i][j]) * (matrix[row_][j]);
                    printf("%f\t", (matrix[i][j]) * (matrix[row_][j]) );
                }
                else {
                    TEMP[i][j] = matrix[i][j];
                    printf("%f\t",matrix[i][j]);
                }
            }
            printf("\n");
        }
        input(dim1,dim2);
    }
}

void coladd(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int row_){           //συναρτηση για την προσθεση μεταξυ στηλων ενος πινακα
    if(row_+1>dim2 || row_+1<=0) printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(j==row){
                    TEMP[i][j] = matrix[i][j]+matrix[i][row_];
                     printf("%f\t",matrix[i][j]+matrix[i][row_]);
                }
                else {
                    TEMP[i][j] = matrix[i][j];
                    printf("%f\t",matrix[i][j]);
                }
            }
            printf("\n");
        }
        input(dim1,dim2);
    }
}

void colmul(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int row_){           //συναρτηση για τον πολλαπλασιασμο μεταξυ στηλων ενος πινακα
    if(row_+1>dim2 || row_+1<=0) printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(j==row){
                    TEMP[i][j] = (matrix[i][j]) * (matrix[i][row_]);
                     printf("%f\t", (matrix[i][j]) * (matrix[i][row_]) );
                }
                else{
                    TEMP[i][j] = (matrix[i][j]);
                     printf("%f\t",matrix[i][j]);
                }
            }
            printf("\n");
        }
        input(dim1,dim2);
    }
}

void numrowadd(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int diff){        //συναρτηση για την προσθεση αριθμου σε σειρα του πινακα
    if(row+1>dim1) printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(i==row){
                    TEMP[i][j] = matrix[i][j]+diff;
                     printf("%f\t",matrix[i][j]+diff);
                }
                else{
                    TEMP[i][j] = matrix[i][j];
                     printf("%f\t",matrix[i][j]);
                }
            }
            printf("\n");
        }
        input(dim1,dim2);
    }
}

void numrowmul(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int scalor){          //συναρτηση για τον πολλαπλασιασμο αριθμου με σειρα του πινακα
    if(row+1>dim1) printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(i==row){
                    TEMP[i][j] = (matrix[i][j]) * scalor ;
                     printf("%f\t", (matrix[i][j]) * scalor );
                }
                else{
                    TEMP[i][j] = (matrix[i][j]);
                     printf("%f\t",matrix[i][j]);
                }
            }
            printf("\n");
        }
        input(dim1,dim2);
    }
}

void numcoladd(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int diff){            //συναρτηση για την προσθεση αριθμου σε στηλη του πινακα
    if(row+1>dim2) printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(j==row){
                     printf("%f\t",matrix[i][j]+diff);
                    TEMP[i][j] = matrix[i][j]+diff;
                }
                else{
                     printf("%f\t",matrix[i][j]);
                    TEMP[i][j] = matrix[i][j];
                }
            }
            printf("\n");
        }
        input(dim1, dim2);
    }
}

void numcolmul(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int scalor){          //συναρτηση για τον πολλαπλασιασμο αριθμου με στηλη του πινακα
    if(row+1>dim2) printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(j==row){
                     printf("%f\t", (matrix[i][j]) * scalor );
                    TEMP[i][j] = matrix[i][j] * scalor;
                }
                else{
                     printf("%f\t",matrix[i][j]);
                     TEMP[i][j] = matrix[i][j];
                }
            }
            printf("\n");
        }
        input(dim1, dim2);
    }
}

float vecdot(float matrix1[MAX_SIZE][MAX_SIZE], float matrix2[MAX_SIZE][MAX_SIZE],int dim1, int dim2){          //συναρτηση για την ευρεση του εσωτερικου γινομενου διανυσματων
    float dot_product=0;
    if(!(dim1==dim2)){
        printf("Τα δύο διανύσματα έχουν διαφορετικές διαστάσεις.\n");
    }else{
        for(int j=0; j<dim1; j++){
            dot_product = dot_product + (matrix1[0][j] * matrix2[0][j]);
        }
        
    }
    return dot_product;
    
}

void veccros(float matrix1[MAX_SIZE][MAX_SIZE], float matrix2[MAX_SIZE][MAX_SIZE]){                     //συναρτηση για την ευρεση του εξωτερικου γινομενου διανυσματων
    TEMP[0][0] = (matrix1[0][1] * matrix2[0][2]) - (matrix1[0][2] * matrix2[0][1]);
    TEMP[0][1] = -((matrix1[0][0] * matrix2[0][2]) - (matrix1[0][2] * matrix2[0][0]));
    TEMP[0][2] = (matrix1[0][0] * matrix2[0][1]) - (matrix1[0][1] * matrix2[0][0]);

    

    
}

void vecscal(float matrix1[MAX_SIZE][MAX_SIZE], int dim, float scalor){                                 //συναρτηση για τον πολλαπλασιασμο διανυσματος με αριθμο
    printf("Το διάνυσμα είναι το:\n");
    for(int i=0; i<dim; i++){
        TEMP[0][i] = scalor*matrix1[0][i];
        printf("%f\t", TEMP[0][i]);
        
    }
    input(1,dim);
}

float vecmag(float matrix[MAX_SIZE][MAX_SIZE], int dim){                                                //συναρτηση για την ευρεση μετρου διανυσματος
    float magnitude=0;

    for(int i=0; i<dim; i++){
        magnitude = magnitude + pow(matrix[0][i], 2);
    } 
    
    magnitude = sqrt(magnitude);

    return magnitude;
}

void file_overview(){                                                                                   //συναρτηση για την εμφανιση των φορτωμενων συστοιχιων στον ιδιο φακελο(μονο αρχεια .txt)
    DIR *d;
  struct dirent *dir;
  d = opendir(".");
  printf("Οι διαθέσιμες συστοιχίες είναι οι παρακάτω:\n\n");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      if( strstr(dir->d_name, ".txt") != NULL )    printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
}

void local_matrix(){                                                                                    //συναρτηση για την μεταφορα συστοιχιας απο διαφορετικο φακελο στον ενεργο φακελο
    char ch, source_file[NAMES_MAX_SIZE], directory[DIRECTORY_SIZE], delete;
    FILE *source, *target;
    

    printf("\nΌνομα του αρχείου:\n");                                                               //εγχωρηση ονοματος του αρχειου
    fgets(source_file,NAMES_MAX_SIZE,stdin);
    source_file[strcspn(source_file, "\n")]='\0';

    printf("Θέση του αρχείου:\n");                                                                  //εγχωρηση θεσης του  αρχειου στον υπολογιστηη του χρηστη
    scanf("%s",directory);

    strcat(directory, source_file);
    printf("%s",directory);

    source = fopen(directory, "r");
    printf("1");

    if( source == NULL ) printf("Η διαδικασία απέτυχε. Το αρχείο είναι κενό.");                     //ελεγχος αν το αρχειο είναι κενο 
printf("2");
    target = fopen(source_file, "w");
 printf("3");
    while( ( ch = fgetc(source) ) != EOF )
       fputc(ch, target);
 
        printf("\nΗ συστοιχία φορτώθηκε επιτυχώς.\n"
                "Να αφαιρεθεί η αρχική συστοιχία;(y/n)");                                           //ελεγχος για την αφαιρεση της αρχικης συστοιχιας(δηλαδη μεταφορα ή απλως αντιγραφη)

    scanf(" %c", &delete);  
    switch(delete){
        case 'y': 
                remove(directory);
                printf("\nΗ διαδικασία ολοκληρώθηκε.\n\n\n");
        break;
        
        case 'n': 
                printf("\nΤο αρχικό αρχείο έχει διατηρηθεί.\n\n\n");               
        break;

        default: scanf(" %c", &delete); 
    }

 
    fclose(source);
    fclose(target);

}

void case1(){                                                                                   //επιλογη 1 απο το αρχικο μενου
    int dim1, dim2;
    char matrix_name[NAMES_MAX_SIZE], matrix_confirm;
    float matrix[MAX_SIZE][MAX_SIZE];
    int status = 1,int_choice;
    char choice = '0';
    FILE *fptr;

        while(status==1){
        switch(choice){
            case '0':printf("\n\n\n");
                printf("Δημιουργία Συστοιχίας\n");
                        printf("1.Ορισμός αναγνωριστικού\n"                                 //μενου της 1ης επιλογης
                            "2.Ορισμός διαστάσεων και μηκών\n"
                            "3.Συμπλήρωση τιμών\n"
                            "4.Επιστροφή\n");
                scanf("%c", &choice);
                if(!(isdigit(choice))){
                    printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ.");
                    choice = '0';
                }else{ 
                    int_choice = atoi(&choice);                
                    if(int_choice>7 || int_choice<0){
                        printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ.");
                        choice = '0';
                    }
                }
                    fflush(stdin);
                    printf("\n\n\n");
            break;
            
            
            case '1':printf("Ορισμός αναγνωριστικού: \n");
                    fgets(matrix_name,NAMES_MAX_SIZE,stdin);                        //ελεγχος πρωτης επιλογης
                    fflush(stdin);                                                          //εισαγωγη ονοματος του νεου αρχειου
                    matrix_name[strcspn(matrix_name, "\n")]='\0';
                    choice = '0';
                    printf("\nΕπιτυχής αποθήκευση αναγνωριστικού\n\n\n");
            break;


            case '2':printf("Ορισμός διαστάσεων και μηκών: \n");
                    do{
                        printf("Εισαγωγή Διαστάσεων:(c>1) r*c: ");                          //ελεγχος δευτερης επιλογης
                        scanf("%d", &dim1);                                                 //εισαγωγη διαστασεων της νεας συστοιχιας
                        scanf("%d", &dim2);                                                 //για εισαφωφη διανυσματος: εισοδος διαστασεων πινακα γραμμη δηλαδη (1 x n)
                        }while(dim1<1 || dim2<2);
                printf("\nΕπιτυχής εισαγωγή διαστάσεων.\n\n\n");
                fflush(stdin);
                choice='0';
            break;


            case '3':printf("Συμπλήρωση τιμών: \n");  
                    for(int i=0; i<dim1; i++){
                        for(int j=0; j<dim2; j++){                                      //ελεγχος τριτης επιλογης
                            printf("Δώσε το στοιχείο %d.%d της συστοιχίας: ", i+1, j+1);        //εισαγωγη στοιχειων
                            scanf("%f", &matrix[i][j]);
                        }
                    } 
                printf("\n");
                printf("Αποθήκευση Συστοιχίας;(y/n)");
                scanf(" %c", &matrix_confirm);                                      //ελεγχος αποθηκευσης της νεας συστοιχιας
                switch(matrix_confirm){
                    case 'n': printf("Η διαδικασία ακυρώθηκε.");
                              status = 0;
                    break;
                    case 'y': 
                            fptr = fopen(strcat(matrix_name, ".txt"),"w");
                            for(int i=0; i<dim1; i++){
                                for(int j=0; j<dim2; j++){                          //προσθεση .txt extension και αντιγραφη των στοιχειων του πινακα μεσα στο νεο αρχειο
                                    fprintf(fptr,"%f ",matrix[i][j]);
                                }
                                fprintf(fptr,"\n");
                            } 
                            fclose(fptr);
                            printf("Η συστοιχία αποθηκεύτηκε επιτυχώς.");
                            choice = '0';
                            fflush(stdin);
                    break;

                    default: scanf(" %c", &matrix_confirm); 
                }
            break;
        
        
            case '4': printf("Επιστροφή.");                                         //επιστροφη στο αρχικο μενου
                    printf("\n\n");
                    status = 0;
            break;

            
            default: printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ");
                    choice = '0';
        
        
        }

        }


}

void case2(){
  char delete_name[NAMES_MAX_SIZE],delete_confirm;
  char choice = '0';
  int status = 1, error_check = 0, int_choice;
  fflush(stdin);
  FILE *ptr;

  while(status==1){
      switch(choice){
        case '0': printf("\n\n\nΠροβολή Διαθέσιμων Συστοιχιών\n");                        //επιλογη 2 απο το αρχικο μενου
                printf("1.Προβολή ενεργών συστοιχιών\n");
                printf("2.Προβολή φορτωμένων συστοιχιών\n");
                printf("3.Τοπική φόρτωση συστοιχίας\n");                            //μενου δευτερης επιλογης
                printf("4.Απενεργοποίηση συστοιχίας\n");
                printf("5.Διαγραφή φορτωμένης συστοιχίας\n");
                printf("6.Επιστροφή\n");

                scanf("%c", &choice);
                if(!(isdigit(choice))){
                    printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ.");
                    choice = '0';
                }else{ 
                    int_choice = atoi(&choice);                
                    if(int_choice>7 || int_choice<0){
                        printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ.");
                        choice = '0';
                    }
                }
                fflush(stdin);
        break;
        
        case '1':printf("\n\n\nΠροβολή ενεργών συστοιχιών\n");              //επιλογη 1: ελεγχος ενεργων συστοιχιων
                
                if(dim11==0) printf("Θέση 1: Συστοιχία κενή.\n");
                else{
                    printf("Θέση 1: Συστοιχία %s\n", a);
                    for(int i=0; i<dim11; i++){                             //αν δεν εχει ενεργοποιηθει συστοιχια σε μια θεση, εμφανιζεται καταλληλο μυνημα
                        for(int j=0; j<dim12; j++){                         //ειδαλλως εμφανιζεται το ονομα της και οι τιμες
                            printf("%.2f\t",A[i][j]);
                        }
                        printf("\n");
                    }   
                }  
                printf("\n\n");
                if(dim21==0) printf("Θέση 2: Συστοιχία κενή.\n");
                else{
                    printf("Θέση 2: Συστοιχία %s\n", b);
                    for(int i=0; i<dim21; i++){
                        for(int j=0; j<dim22; j++){
                            printf("%.2f\t",B[i][j]);
                        }
                        printf("\n");
                    }   
                }
                printf("\n\n");
                if(dim31==0) printf("Θέση 3: Συστοιχία κενή.\n");
                else{
                    printf("Θέση 3: Συστοιχία %s\n", c);
                    for(int i=0; i<dim31; i++){
                        for(int j=0; j<dim32; j++){
                            printf("%.2f\t",C[i][j]);
                        }
                        printf("\n");
                    }   
                }
                printf("\n\n\n");
                choice = '0';
        break;

        case '2':printf("\n\nΠροβολή φορτωμένων συστοιχιών\n");                 //εμφανιση των διαθεσιμων συστοιχιων στον φακελο
                file_overview();                                                //παραπομπη σε συναρτηση που εμφανιζει τα ονοματα των txt αρχειων
                choice = '0';
                printf("\n\n\n");
        break;

        case '3':printf("Τοπική φόρτωση συστοιχίας(.txt only)\n");              //φορτωση συστοιχιας απο τον υπολογιστη του χρηστη
                fflush(stdin);
                local_matrix();                                                 //παραπομπη σε συναρτηση
                choice = '0';
                printf("\n\n\n");
        break;

        case '4':printf("\n\nΑπενεργοποίηση συστοιχίας\n");                     //απενεργοποιηση συστοιχιας
                printf("Όνομα συστοιχίας που θα απενεργοποιηθεί: ");               //εισαγωγη ονοματος, η συστοιχια δεν εμφανιζεται ως ενεργη και δεν μπορει να χρησιμοποιηθει σε πραξεις
                fflush(stdin);
                fgets(delete_name,NAMES_MAX_SIZE,stdin);
                delete_name[strcspn(delete_name, "\n")]='\0';
                
                if(strcmp(delete_name, a) == 0){
                    dim11 = 0;
                    a[0] = '\0';
                    printf("Απενεργοποιήθηκε η συστοιχία 1. \n");
                }else error_check++;
                
                if(strcmp(delete_name, b) == 0){
                    dim21 = 0;
                    b[0] = '\0';
                    printf("Aπενεργοποιήθηκε η συστοιχία 2. \n");
                }else error_check++;
                
                if(strcmp(delete_name, c) == 0){
                    dim31 = 0;
                    c[0] = '\0';
                    printf("Απενεργοποιήθηκε η συστοιχία 3. \n");
                }else error_check++;
                
                if(error_check==3) printf("ΣΦΑΛΜΑ. Η ΔΙΑΔΙΚΑΣΙΑ ΑΚΥΡΩΘΗΚΕ.");

                choice = '0';
                printf("\n\n\n");
                fflush(stdin);
        break;

        case '5': 
                printf("\n\nΔιαγραφή φορτωμένης συστοιχίας\n");                //διαγραφη φορτωμενης συστοιχιας
                printf("Όνομα συστοιχίας που θα διαγραφεί: ");                  //διαγραφεται το αρχειο απο τον φακελο και η συστοιχια δεν ειναι πλεον διαθεσιμη για φορτωση στο προγραμμα
                fflush(stdin);
                fgets(delete_name,NAMES_MAX_SIZE,stdin);
                delete_name[strcspn(delete_name, "\n")]='\0';
                strcat(delete_name, ".txt");
                
                ptr = fopen(delete_name,"r");
                
                if(ptr == NULL){
                    printf("Η συστοιχία δεν υπάρχει.");
                }else{
                
                printf("Διαγραφή Συστοιχίας; Η διαδικασία δεν μπορεί να αναιρεθεί.(y/n)");
                scanf(" %c", &delete_confirm);
                switch(delete_confirm){
                    
                    //float number;
                    case 'n': 
                    break;
                    case 'y': 
                            
                             printf("\nΗ συστοιχία διαγράφηκε επιτυχώς.");
                            
                            remove(delete_name);
                            
                    break;

                    default: scanf(" %c", &delete_confirm); 
                }
                }
                choice = '0';
                printf("\n\n\n");
                fflush(stdin);
        break;

        case '6':printf("Επιστροφή\n");                                         //επιστροφη στο αρχικο μενου
                status = 0;
        break;
  
        default: printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ");                      
                choice = '0';
        
    }
}

printf("\n\n\n");
}

void case3(int dim1, int dim2, int index){                          //επιλογη 3 απο το αρχικο μενου
  file_overview();                                                      //παραπομπη σε συναρτηση-εμφανιση αρχειων στον φακελο
  fflush(stdin);
    char name[NAMES_MAX_SIZE];
    FILE *fptr; 


    printf("\n\n");
    printf("\nΌνομα της συστοιχίας: ");

    fgets(name,NAMES_MAX_SIZE,stdin);                       //εισοδος ονοματος του αρχειου που θα επιλεχθει

    name[strcspn(name, "\n")]='\0';
    
    if(index==1) strcpy(a,name);                    //επιλογη θεσης ενεργοποιησης
    if(index==2) strcpy(b,name);
    if(index==3) strcpy(c,name);
    
    fptr = fopen(strcat(name, ".txt"),"r");
    
    if( fptr == NULL ) {
      perror("Error: ");
      if(index==1) dim11 = 0;
      if(index==2) dim21 = 0;
      if(index==3) dim31 = 0;

    }else{

        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){                              //εισαγωγη των τιμων του αρχειου στο προγραμμα "ενεργοποιηση συστοιχιας"
                if(index==1)fscanf(fptr,"%f", &A[i][j]);                //πλεον η συστοιχια ειναι διαθεσιμη για πραξεις
                if(index==2)fscanf(fptr,"%f", &B[i][j]);
                if(index==3)fscanf(fptr,"%f", &C[i][j]);
            }
        } 

        printf("Η συστοιχία φορτώθηκε επιτυχώς.");

    }
    
}

void case4(){                                                                                           //επιλογη 4 απο το αρχικο μενου: πραξεις διανυσματων(πινακας γραμμη)
  char operation[12],matrix1[NAMES_MAX_SIZE],matrix2[NAMES_MAX_SIZE],matrix3[NAMES_MAX_SIZE];
  float num,dot_product,scalor,magnitude;
  int i=0,j=0,k=0,error_check=0,error_check1=0,vector_check_a,vector_check_b,vector_check_c;
  
  int status = 1;
  char choice = '0', inputs[2*NAMES_MAX_SIZE + 12];
  fflush(stdin);

  while(status==1){
        switch(choice){
    
            case '0': printf("\n\nΠράξεις Διανυσμάτων\n");                              //μενου της τεταρτης επιλογης
                    printf("1.Λίστα εντολών\n");
                    printf("2.Επιστροφή\n");
                    printf("Δώσε εντολή...\n");
                    fflush(stdin);
                    fgets( inputs, 2*NAMES_MAX_SIZE + 12, stdin);

                    inputs[strcspn(inputs, "\n")]='\0';
                    fflush(stdin);

                    status = 0;
                    if(strcmp(inputs, "0") == 0){
                         choice = '0';
                        status = 1;
                    }
                    
                    else if(strcmp(inputs, "1") == 0){
                         choice = '1';
                        status = 1;
                    }
                    
                    else if(strcmp(inputs, "2") == 0) choice = '2';                    
                                                                                        //διαχωρισμος απο την εισοδο του χρηστη σε:
                    else{                                                               //πραξη: το ειδος της πραξης που θα πραγματοποιηθει
                        while(inputs[i]!=','){                                          //ονοματα συστοιχιων: ποιες συστοιχιες θα χρησιμοποιηθουν στις πραξεις
                            operation[i]=inputs[i];                                     //αριθμοι: πιθανοι αριθμοι που θα χρησιμοποιηθουν σε πραξεις
                            i++;
                            if(i==12){
                                printf("Μη έγκυρη εισαγωγή. Η διαδικασία ακυρώθηκε.\n");
                                choice = '0';
                                return;
                            } 
                        }
                        operation[i]='\0';
                        i++;
                        

                        while(inputs[i]!=',' && inputs[i]!='\0'){
                            matrix1[j]=inputs[i];
                            i++;
                            j++;
                        }
                        matrix1[j]='\0';
                        i++;
                        while(inputs[i]!=',' && inputs[i]!='\0'){
                            matrix2[k]=inputs[i];
                            i++;
                            k++;
                        }
                        matrix2[k]='\0';
                        
                            
                        if(strcmp(matrix1, a) != 0) error_check++;                  //ελεγχος αν το εισαγωμενο αναγνωριστικο αντιστοιχει σε ενεργοποιημενη συστοιχια
                        if(strcmp(matrix1, b) != 0) error_check++;
                        if(strcmp(matrix1, c) != 0) error_check++;

                        if(strcmp(matrix2, a) != 0) error_check1++;
                        if(strcmp(matrix2, b) != 0) error_check1++;
                        if(strcmp(matrix2, c) != 0) error_check1++;

                        if(strcmp(operation,"vecscal") == 0) error_check1--;
                        if(strcmp(operation,"vecmag") == 0) error_check1--;

                        vector_check_a = vector_check(dim11); 
                        //printf("vectorchecka=%d",vector_check_a);                  //ελεγχος αν η συστοιχια αποτελει διανυσμα, ειναι δηλαδη πινακας-γραμμη
                        vector_check_b = vector_check(dim21);
                        vector_check_c = vector_check(dim31);

                        //printf("operation: %s\nvector1: %s\nvector2: %s\n error_check=%d\nerror_check1=%d\n",operation,matrix1,matrix2,error_check,error_check1);
                        //printf("%d %d %d\n",vector_check_a,vector_check_b,vector_check_c);
                        
                        
                        if(strcmp(operation,"vecadd") == 0){                              //προσθεση διανυσματων
                            
                            if(strcmp(matrix1,a)==0){
                                if(vector_check_a>0){                                                   //ελεγχος ποια ενεργη συστοιχια εχει επικαλεσθει ο χρηστης
                                    if(strcmp(matrix2,b)==0){                                           //σε καθε πραξη η διαδικασια αυτη επαναλαμβανεται
                                        if(vector_check_b>0){
                                            if(dim12==dim22){
                                                printf("Το τελικό διάνυσμα είναι το:\n");
                                                for(int j=0; j<dim12;j++){
                                                    printf("%f\t",A[0][j] + B[0][j]);
                                                    TEMP[0][j] = A[0][j] + B[0][j];
                                                }
                                                input(1,dim12);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            if(dim12==dim32){
                                                printf("Το τελικό διάνυσμα είναι το:\n");
                                                for(int j=0; j<dim12;j++){
                                                    printf("%f\t",A[0][j] + C[0][j]);
                                                    TEMP[0][j] = A[0][j] + C[0][j];
                                                }
                                                input(1,dim12);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                            if(strcmp(matrix1,b)==0){
                                if(vector_check_b>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            if(dim12==dim22){
                                                printf("Το τελικό διάνυσμα είναι το:\n");
                                                for(int j=0; j<dim12;j++){
                                                    printf("%f\t",B[0][j] + A[0][j]);
                                                    TEMP[0][j] = B[0][j] + A[0][j];
                                                }
                                                input(1,dim22);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            if(dim22==dim32){
                                                printf("Το τελικό διάνυσμα είναι το:\n");
                                                for(int j=0; j<dim12;j++){
                                                    printf("%f\t",B[0][j] + C[0][j]);
                                                    TEMP[0][j] = B[0][j] + C[0][j];
                                                }
                                                input(1,dim22);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }

                            if(strcmp(matrix1,c)==0){
                                if(vector_check_c>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            if(dim12==dim32){
                                                printf("Το τελικό διάνυσμα είναι το:\n");
                                                for(int j=0; j<dim12;j++){
                                                    printf("%f\t",C[0][j] + A[0][j]);
                                                    TEMP[0][j] = C[0][j] + A[0][j];
                                                }
                                                input(1,dim32);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            if(dim22==dim32){
                                                printf("Το τελικό διάνυσμα είναι το:\n");
                                                for(int j=0; j<dim12;j++){
                                                    printf("%f\t",C[0][j] + B[0][j]);
                                                    TEMP[0][j] = C[0][j] + B[0][j];
                                                }
                                                input(1,dim32);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                        
                        }else if(strcmp(operation,"vecsub") == 0){                              //αφαιρεση διανυσματων
                            
                            if(strcmp(matrix1,a)==0){
                                if(vector_check_a>0){
                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            if(dim12==dim22){
                                                printf("Το τελικό διάνυσμα είναι το:\n");
                                                for(int j=0; j<dim12;j++){
                                                    printf("%f\t",A[0][j] - B[0][j]);
                                                    TEMP[0][j] = A[0][j] - B[0][j];
                                                }
                                                input(1,dim12);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            if(dim12==dim32){
                                                printf("Το τελικό διάνυσμα είναι το:\n");
                                                for(int j=0; j<dim12;j++){
                                                    printf("%f\t",A[0][j] - C[0][j]);
                                                    TEMP[0][j] = A[0][j] - C[0][j];
                                                }
                                                input(1,dim12);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                            if(strcmp(matrix1,b)==0){
                                if(vector_check_b>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            if(dim12==dim22){
                                                printf("Το τελικό διάνυσμα είναι το:\n");
                                                for(int j=0; j<dim12;j++){
                                                    printf("%f\t",B[0][j] - A[0][j]);
                                                    TEMP[0][j] = B[0][j] - A[0][j];
                                                }
                                                input(1,dim22);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            if(dim22==dim32){
                                                printf("Το τελικό διάνυσμα είναι το:\n");
                                                for(int j=0; j<dim12;j++){
                                                    printf("%f\t",B[0][j] - C[0][j]);
                                                    TEMP[0][j] = B[0][j] - C[0][j];
                                                }
                                                input(1,dim22);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }

                            if(strcmp(matrix1,c)==0){
                                if(vector_check_c>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            if(dim12==dim32){
                                                printf("Το τελικό διάνυσμα είναι το:\n");
                                                for(int j=0; j<dim12;j++){
                                                    printf("%f\t",C[0][j] - A[0][j]);
                                                    TEMP[0][j] = C[0][j] - A[0][j];
                                                }
                                                input(1,dim32);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            if(dim22==dim32){
                                                printf("Το τελικό διάνυσμα είναι το:\n");
                                                for(int j=0; j<dim12;j++){
                                                    printf("%f\t",C[0][j] - B[0][j]);
                                                    TEMP[0][j] = C[0][j] - B[0][j];
                                                }
                                                input(1,dim32);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                        
                        }else if(strcmp(operation,"vecdot") == 0){                              //εσωτερικο γινομενο(παραπεμπει σε συναρτηση)
                            
                            if(strcmp(matrix1,a)==0){
                                if(vector_check_a>0){
                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            dot_product = vecdot(A,B,dim12,dim22);
                                            printf("Το εσωτερικό γινόμενο των δύο διανυσμάτων είναι %f.\n",dot_product);
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            //if(dim12==dim32){
                                                dot_product = vecdot(A,C,dim12,dim32);
                                                printf("Το εσωτερικό γινόμενο των δύο διανυσμάτων είναι %f.\n",dot_product);
                                            //}printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }

                            if(strcmp(matrix1,b)==0){
                                if(vector_check_b>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            //if(dim12==dim22){
                                                dot_product = vecdot(B,A,dim22,dim12);
                                                printf("Το εσωτερικό γινόμενο των δύο διανυσμάτων είναι %f.\n",dot_product);
                                            //}else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            //if(dim22==dim32){
                                                dot_product = vecdot(A,C,dim12,dim32);
                                                printf("Το εσωτερικό γινόμενο των δύο διανυσμάτων είναι %f.\n",dot_product);
                                            //}else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                            if(strcmp(matrix1,c)==0){
                                if(vector_check_c>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            //if(dim12==dim32){
                                                dot_product = vecdot(C,A,dim32,dim12);
                                                printf("Το εσωτερικό γινόμενο των δύο διανυσμάτων είναι %f.\n",dot_product);
                                            //}else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            //if(dim22==dim32){
                                                dot_product = vecdot(C,B,dim32,dim22);
                                                printf("Το εσωτερικό γινόμενο των δύο διανυσμάτων είναι %f.\n",dot_product);
                                            //}else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                                                
                        }else if(strcmp(operation,"veccros") == 0){                             //εξωτερικο γινομενο (παραπεμπει σε συναρτηση)
                            
                            
                            if(strcmp(matrix1,a)==0){
                                if(vector_check_a>0){
                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            if(dim12==dim22){
                                                veccros(A,B);
                                                printf("Το εξωτερικό γινόμενο είναι το:\n");
                                                for(int j=0; j<3; j++){
                                                    printf("%f\t",TEMP[0][j]);
                                                }
                                                input(1,3);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            if(dim12==dim32){
                                                veccros(A,C);
                                                printf("Το εξωτερικό γινόμενο είναι το:\n");
                                                for(int j=0; j<3; j++){
                                                    printf("%f\t",TEMP[0][j]);
                                                }
                                                input(1,3);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                            
                        
                            if(strcmp(matrix1,b)==0){
                                if(vector_check_b>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            if(dim12==dim22){
                                                veccros(B,A);
                                                printf("Το εξωτερικό γινόμενο είναι το:\n");
                                                for(int j=0; j<3; j++){
                                                    printf("%f\t",TEMP[0][j]);
                                                }
                                                input(1,3);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            if(dim22==dim32){
                                                veccros(B,C);
                                                printf("Το εξωτερικό γινόμενο είναι το:\n");
                                                for(int j=0; j<3; j++){
                                                    printf("%f\t",TEMP[0][j]);
                                                }
                                                input(1,3);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                            
                            if(strcmp(matrix1,c)==0){
                                if(vector_check_c>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            if(dim12==dim32){
                                                veccros(C,A);
                                                printf("Το εξωτερικό γινόμενο είναι το:\n");
                                                for(int j=0; j<3; j++){
                                                    printf("%f\t",TEMP[0][j]);
                                                }
                                                input(1,3);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            if(dim22==dim32){
                                                veccros(C,B);
                                                printf("Το εξωτερικό γινόμενο είναι το:\n");
                                                for(int j=0; j<3; j++){
                                                    printf("%f\t",TEMP[0][j]);
                                                }
                                                input(1,3);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                        
                        }else if(strcmp(operation,"vectri") == 0){                              //μικτο γινομενο(κανει χρηση των συναρτησεων του εξωτερικου και εσωτερικου γινομενου)
                            if(dim11==0 || dim21==0 || dim31==0){
                                printf("Έχουν ενεργοποιηθεί λιγότερα από τρία διανύσματα.\n");
                            }else{
                                if(!(vector_check_a>0 && vector_check_b>0 && vector_check_c>0)) printf("Μη έγκυρα διανύσματα.\n");
                                else if(dim12>4 || dim22>4 || dim32>4) printf("Τα διανύσματα δεν ανήκουν στο χώρο R^3.\n");
                                else if(!(dim12==dim22 && dim22==dim32)) printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                else{
                                    veccros(B,C);
                                    dot_product = vecdot(A,TEMP,3,3);
                                    printf("Το μικτό γινόμενο των διανυσμάτων είναι %f.\n",dot_product);
                                }
                            }
                        }else if(strcmp(operation,"vecscal") == 0){                             //πολλαπλασιασμος διανυσματος με αριθμο(παραπεμπει σε συναρτηση)
                            scalor = atof(matrix2);
                            
                            if(strcmp(matrix1, a) == 0){
                                if(vector_check_a>0){
                                     vecscal(A,dim12,scalor);
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                            
                            if(strcmp(matrix1, b) == 0){
                                if(vector_check_b>0){
                                     vecscal(B,dim22,scalor);
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                            if(strcmp(matrix1, c) == 0){
                                if(vector_check_c>0){
                                     vecscal(C,dim32,scalor);
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                        
                        }else if(strcmp(operation,"vecmag") == 0){                              //μετρο διανυσματος(παραπεμπει σε συναρτηση)
                            if(strcmp(matrix1, a) == 0){
                                if(vector_check_a>0){
                                     magnitude = vecmag(A,dim12);
                                     printf("Το μέτρο του διανύσματος είναι %f",magnitude);
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                            
                            if(strcmp(matrix1, b) == 0){
                                if(vector_check_b>0){
                                     magnitude = vecmag(B,dim22);
                                     printf("Το μέτρο του διανύσματος είναι %f",magnitude);
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                            if(strcmp(matrix1, c) == 0){
                                if(vector_check_c>0){
                                     magnitude = vecmag(C,dim32);
                                     printf("Το μέτρο του διανύσματος είναι %f",magnitude);
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                        
                        }else if(strcmp(operation,"vecang") == 0){                              //γωνια μεταξυ δυο διανυσματων(γινεται χρηση της συναρτησης του εσωτερικου γινομενου)
                            float magnitude1=0,magnitude2=0;
                            
                            if(strcmp(matrix1,a)==0){
                                if(vector_check_a>0){
                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            if(dim12==dim22){
                                                magnitude1 = vecmag(A,dim12);
                                                magnitude2 = vecmag(B,dim22);
                                                dot_product = vecdot(A,B,dim12,dim22);
                                                printf("Η γωνία των δύο διανυσμάτων είναι cosθ = %f\n", dot_product/(magnitude1*magnitude2) );
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            if(dim12==dim32){
                                                magnitude1 = vecmag(A,dim12);
                                                magnitude2 = vecmag(C,dim22);
                                                dot_product = vecdot(A,C,dim12,dim32);
                                                printf("Η γωνία των δύο διανυσμάτων είναι sinθ = %f\n", dot_product/(magnitude1*magnitude2) );
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }


                            if(strcmp(matrix1,b)==0){
                                if(vector_check_b>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            if(dim12==dim22){
                                                magnitude1 = vecmag(A,dim12);
                                                magnitude2 = vecmag(B,dim22);
                                                dot_product = vecdot(A,B,dim12,dim22);
                                                printf("Η γωνία των δύο διανυσμάτων είναι sinθ = %f\n", dot_product/(magnitude1*magnitude2) );
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            if(dim22==dim32){
                                                magnitude1 = vecmag(B,dim22);
                                                magnitude2 = vecmag(C,dim32);
                                                dot_product = vecdot(B,C,dim22,dim32);
                                                printf("Η γωνία των δύο διανυσμάτων είναι sinθ = %f\n", dot_product/(magnitude1*magnitude2) );
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }


                            if(strcmp(matrix1,c)==0){
                                if(vector_check_c>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            if(dim12==dim32){
                                                magnitude1 = vecmag(A,dim12);
                                                magnitude2 = vecmag(C,dim32);
                                                dot_product = vecdot(A,C,dim12,dim32);
                                                printf("Η γωνία των δύο διανυσμάτων είναι sinθ = %f\n", dot_product/(magnitude1*magnitude2) );
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            if(dim22==dim32){
                                                magnitude1 = vecmag(B,dim22);
                                                magnitude2 = vecmag(C,dim32);
                                                dot_product = vecdot(B,C,dim22,dim32);
                                                printf("Η γωνία των δύο διανυσμάτων είναι sinθ = %f\n", dot_product/(magnitude1*magnitude2) );
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                            
                        
                        }else if(strcmp(operation,"vecarea") == 0){                             //Εμβαδό παρ/μου που προκύπτει απο δύο διανύσματα(γινεται χρηση αλλων συναρτησεων)
                            
                            if(strcmp(matrix1,a)==0){
                                if(vector_check_a>0){
                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            if(dim12==dim22){
                                                veccros(A,B);
                                                magnitude = vecmag(TEMP,dim12);
                                                printf("Το Εμβαδό παρ/μου που προκύπτει απο τα δύο διανύσματα είναι %f τ.μ.\n", magnitude);                                               
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            if(dim12==dim32){
                                                veccros(A,C);
                                                magnitude = vecmag(TEMP,dim12);
                                                printf("Το Εμβαδό παρ/μου που προκύπτει απο τα δύο διανύσματα είναι %f τ.μ.\n", magnitude);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                            
                        
                            if(strcmp(matrix1,b)==0){
                                if(vector_check_b>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            if(dim12==dim22){
                                                veccros(B,A);
                                                magnitude = vecmag(TEMP,dim22);
                                                printf("Το Εμβαδό παρ/μου που προκύπτει απο τα δύο διανύσματα είναι %f τ.μ.\n", magnitude);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            if(dim22==dim32){
                                                veccros(B,C);
                                                magnitude = vecmag(TEMP,dim22);
                                                printf("Το Εμβαδό παρ/μου που προκύπτει απο τα δύο διανύσματα είναι %f τ.μ.\n", magnitude);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                            
                            if(strcmp(matrix1,c)==0){
                                if(vector_check_c>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            if(dim12==dim32){
                                                veccros(C,A);
                                                magnitude = vecmag(TEMP,dim32);
                                                printf("Το Εμβαδό παρ/μου που προκύπτει απο τα δύο διανύσματα είναι %f τ.μ.\n", magnitude);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            if(dim22==dim32){
                                                veccros(C,B);
                                                magnitude = vecmag(TEMP,dim32);
                                                printf("Το Εμβαδό παρ/μου που προκύπτει απο τα δύο διανύσματα είναι %f τ.μ.\n", magnitude);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                        
                        }else if(strcmp(operation,"vecdis") == 0){                              //αποσταση μεταξυ δυο διανυσματων(γινεται χρηση αλλων συναρτησεων)

                            if(strcmp(matrix1,a)==0){
                                if(vector_check_a>0){
                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            if(dim12==dim22){
                                                
                                                for(int j=0; j<dim12;j++){
                                                    
                                                    TEMP[0][j] = A[0][j] - B[0][j];
                                                    magnitude = vecmag(TEMP,dim12);
                                                }
                                                printf("Η απόσταση μεταξύ των διανυσμάτων είναι %f μονάδες.\n",magnitude);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            if(dim12==dim32){
                                                
                                                for(int j=0; j<dim12;j++){
                                                   
                                                    TEMP[0][j] = A[0][j] - C[0][j];
                                                    magnitude = vecmag(TEMP,dim12);
                                                }
                                                printf("Η απόσταση μεταξύ των διανυσμάτων είναι %f μονάδες.\n",magnitude);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                            if(strcmp(matrix1,b)==0){
                                if(vector_check_b>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            if(dim12==dim22){
                                                
                                                for(int j=0; j<dim12;j++){
                                                    
                                                    TEMP[0][j] = B[0][j] - A[0][j];
                                                    magnitude = vecmag(TEMP,dim22);
                                                }
                                                printf("Η απόσταση μεταξύ των διανυσμάτων είναι %f μονάδες.\n",magnitude);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,c)==0){
                                        if(vector_check_c>0){
                                            if(dim22==dim32){
                                                
                                                for(int j=0; j<dim12;j++){
                                                    
                                                    TEMP[0][j] = B[0][j] - C[0][j];
                                                    magnitude = vecmag(TEMP,dim22);
                                                }
                                                printf("Η απόσταση μεταξύ των διανυσμάτων είναι %f μονάδες.\n",magnitude);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }

                            if(strcmp(matrix1,c)==0){
                                if(vector_check_c>0){
                                    if(strcmp(matrix2,a)==0){
                                        if(vector_check_a>0){
                                            if(dim12==dim32){
                                                
                                                for(int j=0; j<dim12;j++){
                                                    
                                                    TEMP[0][j] = C[0][j] - A[0][j];
                                                    magnitude = vecmag(TEMP,dim32);
                                                }
                                                printf("Η απόσταση μεταξύ των διανυσμάτων είναι %f μονάδες.\n",magnitude);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }

                                    if(strcmp(matrix2,b)==0){
                                        if(vector_check_b>0){
                                            if(dim22==dim32){
                                                
                                                for(int j=0; j<dim12;j++){
                                                    
                                                    TEMP[0][j] = C[0][j] - B[0][j];
                                                    magnitude = vecmag(TEMP,dim32);
                                                }
                                                printf("Η απόσταση μεταξύ των διανυσμάτων είναι %f μονάδες.\n",magnitude);
                                            }else printf("Τα διανύσματα δεν έχουν ίδιες διαστάσεις.\n");
                                        }else printf("Μη έγκυρα διανύσματα.\n");
                                    }
                                }else printf("Μη έγκυρα διανύσματα.\n");
                            }
                        
                        
                        }else{
                            printf("Μη έγκυρη πράξη. Η διαδικασία ακυρώθηκε.\n");
                            choice = '0';
                            return;
                        }
                    
                        if(error_check==3){                                                                 //ελεγχος για καθε μια απο τις πιθανες πραξεις διανυσματων
                            printf("Αυτό το διάνυσμα δεν έχει ενεργοποιηθεί. Η διαδικασία ακυρώθηκε.\n");
                            choice = '0';
                            return;
                        }else if(error_check1==3){
                            printf("Αυτό το διάνυσμα δεν έχει ενεργοποιηθεί. Η διαδικασία ακυρώθηκε.\n");
                            choice = '0';
                            return;
                        }
                    
                    }
                    fflush(stdin);
                    
            break;

            case '1': printf("Λίστα εντολών\n");
                    printf("----------------------------------------------------------------------\n");             //λιστα εντολων για πραξεις διανυσματων
                    printf("Πρόσθεση διανυσμάτων:                            vecadd,(),()\n");                      //ο διαχωρισμος της εντολης και των αναγνωριστικων τω πινακων γινεται με κομμα ','
                    printf("Αφαίρεση διανυσμάτων:                            vecsub,(),()\n");
                    printf("Εσωτερικό γινόμενο:                              vecdot,(),()\n");
                    printf("Εξωτερικό γινόμενο:                              veccros,(),()\n");
                    printf("Μικτό γινόμενο:                                  vectri\n");
                    printf("Πολλαπλασιασμός διανύσματος με αριθμό:           vecscal,(),(scalar)\n");
                    printf("Γωνία μεταξύ δύο διανυσμάτων:                    vecang,(),()\n");
                    printf("Εμβαδό παρ/μου που προκύπτει απο δύο διανύσματα: vecarea,(),()\n");
                    printf("Μέτρο διανύσματος:                               vecmag,()\n");
                    printf("Απόσταστη μεταξύ δύο διανυσμάτων:                vecdis,(),()\n");
                    printf("----------------------------------------------------------------------\n");
                    printf("Πατήστε οποιοδήποτε κουμπί για να συνεχίσετε.");
                    fgets(inputs,2,stdin);
                    fflush(stdin);
                    choice ='0';
            break;

            case '2': printf("Επιστροφή\n\n");                                                              //επιστροφη στο αρχικο μενου
                    status = '0';
            break;

            default: choice = '0';

            
        }

    }
}

void case5(){                                                               //επιλογη 5 απο το αρχικο μενου: πραξεις πινακων
  char operation[12],matrix1[NAMES_MAX_SIZE],matrix2[NAMES_MAX_SIZE];
  float num, det, scalor;
  int i=0, j=0, k=0, error_check=0, error_check1=0;
  
  int status = 1;
  char choice = '0', inputs[2*NAMES_MAX_SIZE + 12];
  fflush(stdin);

    while(status==1){
        switch(choice){
    
            case '0': printf("\n\nΠράξεις Πινάκων\n");
                    printf("1.Λίστα εντολών\n");                        //μενου της πεμπτης επιλογης
                    printf("2.Επιστροφή\n");
                    printf("Δώσε εντολή...\n");
                    fflush(stdin);
                    fgets( inputs, 2*NAMES_MAX_SIZE + 12, stdin);

                    inputs[strcspn(inputs, "\n")]='\0';
                    fflush(stdin);

                    status = 0; 
                    
                                                                    //ομοιως με τα διανυσματα, η εισοδος του χρηστη διαβαζεται σε μια μεταβλητη
                    if(strcmp(inputs, "0") == 0){                               //και επειτα διαχωριζεται
                         choice = '0';                                          //αν ειναι αριθμος, επιλεγεται η καταλληλη εντολη
                        status = 1;                                             //αν προκειται για πραξη πινακων, γινεται η καταλληλη διακριση της πραξης και των ονοματων της πρωτης και δευτερης συστοιχιας
                    }
                    
                    else if(strcmp(inputs, "1") == 0){
                         choice = '1';
                        status = 1;
                    }
                    
                    else if(strcmp(inputs, "2") == 0) choice = '2'; 

                                     
                    
                    else{
                        while(inputs[i]!=','){
                            operation[i]=inputs[i];
                            i++;
                            if(i==12){
                                printf("Μη έγκυρη εισαγωγή. Η διαδικασία ακυρώθηκε.\n");
                                choice = '0';
                                return;
                            }
                        }
                        operation[i]='\0';
                        i++;

                        while(inputs[i]!=',' && inputs[i]!='\0'){
                            matrix1[j]=inputs[i];
                            i++;
                            j++;
                        }
                        matrix1[j]='\0';
                        i++;
                        while(inputs[i]!=',' && inputs[i]!='\0'){
                            matrix2[k]=inputs[i];
                            i++;
                            k++;
                        }
                        matrix2[k]='\0';
                        
    
                        if(strcmp(matrix1, a) != 0) error_check++;
                        if(strcmp(matrix1, b) != 0) error_check++;                  //ελεγχος αν ο πρωτος πινακας ειναι ενεργοποιημενος
                        if(strcmp(matrix1, c) != 0) error_check++;

                        if(strcmp(matrix2, a) != 0) error_check1++;
                        if(strcmp(matrix2, b) != 0) error_check1++;                 //ελεγχος αν ο δευτερος πινακας ειναι ενεργοποιημενος
                        if(strcmp(matrix2, c) != 0) error_check1++;
    
                        if(strcmp(operation,"numcolmul") == 0) error_check1--;
                        if(strcmp(operation,"numcoladd") == 0) error_check1--;
                        if(strcmp(operation,"numrowmul") == 0) error_check1--;
                        if(strcmp(operation,"numrowadd") == 0) error_check1--;
                        if(strcmp(operation,"colmul") == 0) error_check1--;
                        if(strcmp(operation,"coladd") == 0) error_check1--;
                        if(strcmp(operation,"rowmul") == 0) error_check1--;
                        if(strcmp(operation,"rowadd") == 0) error_check1--;
                        if(strcmp(operation,"matsmul") == 0) error_check1--;
                        if(strcmp(operation,"det") == 0) error_check1--;
                        if(strcmp(operation,"inv") == 0) error_check1--;
                        if(strcmp(operation,"adj") == 0) error_check1--;
                        if(strcmp(operation,"trace") == 0) error_check1--;
                        if(strcmp(operation,"trans") == 0) error_check1--;

                        if(strcmp(operation,"det") == 0){                                         //πραξεις πινακων, καθε πραξη φαινεται στον πινακα εντολων παρακατω
                            if(strcmp(matrix1, a) == 0 && dim11==dim12){
                                printf("Η διακρίνουσα του πίνακα %s είναι: %f", a,determinant(A, dim11, dim12));            //γινεται συνεχως αναφορα σε συναρτησεις παραπανω σε καθε πραξη 
                            }else if(dim11!=dim12) printf("Ο πίνακας δεν είναι τετραγωνικός.");
                        
                        if(strcmp(matrix1, b) == 0 && dim21==dim22){
                                printf("Η διακρίνουσα του πίνακα %s είναι: %f", b,determinant(B, dim21, dim22));            
                            }else if(dim21!=dim22) printf("Ο πίνακας δεν είναι τετραγωνικός.");
                        
                        if(strcmp(matrix1, c) == 0 && dim31==dim32){
                                printf("Η διακρίνουσα του πίνακα %s είναι: %f", c,determinant(C, dim31, dim32));            
                            }else if(dim31!=dim32) printf("Ο πίνακας δεν είναι τετραγωνικός.");
                            
                        
                        }else if(strcmp(operation,"inv") == 0){
                            if(strcmp(matrix1, a) == 0){
                                inverse(A, dim11, dim12);
                                
                            }       
                            
                            if(strcmp(matrix1, b) == 0){
                                inverse(B, dim21, dim22);
                                
                            } 
                            if(strcmp(matrix1, c) == 0){
                                inverse(C, dim31, dim32);
                                
                            } 

                        }else if(strcmp(operation,"adj") == 0){
                            
                            if(strcmp(matrix1, a) == 0){
                                if(dim11==dim12) adjoint(A, dim11, dim12);
                                else printf("Ο πίνακας δεν είναι τετραγωνικός.");
                            }

                            if(strcmp(matrix1, b) == 0){
                                if(dim21==dim22) adjoint(B, dim21, dim22);
                                else printf("Ο πίνακας δεν είναι τετραγωνικός.");
                            }

                            if(strcmp(matrix1, c) == 0){
                                if(dim31==dim32) adjoint(C, dim31, dim32);
                                else printf("Ο πίνακας δεν είναι τετραγωνικός.");
                            }
                        }else if(strcmp(operation,"trace") == 0){
                            
                            float trace=0;
                            if(strcmp(matrix1, a) == 0){
                                
                                if(dim11==dim12){ 
                                    for(int i=0; i<dim11; i++){
                                        trace = trace + A[i][i];
                                    }
                                    printf("Το ίχνος του πίνακα %s είναι %.2f", matrix1,trace);
                                }
                                else printf("Ο πίνακας δεν είναι τετραγωνικός.");
                                
                            }
                            if(strcmp(matrix1, b) == 0){
                                
                                if(dim21==dim22){ 
                                    for(int i=0; i<dim21; i++){
                                        trace = trace + B[i][i];
                                    }
                                    printf("Το ίχνος του πίνακα %s είναι %.2f", matrix1,trace);
                                }
                                else printf("Ο πίνακας δεν είναι τετραγωνικός.");
                                
                            }
                            if(strcmp(matrix1, c) == 0){
                                
                                if(dim31==dim32){ 
                                    for(int i=0; i<dim31; i++){
                                        trace = trace + C[i][i];
                                    }
                                    printf("Το ίχνος του πίνακα %s είναι %.2f", matrix1,trace);
                                }
                                else printf("Ο πίνακας δεν είναι τετραγωνικός.");
                                
                            }

                            
                        
                        }else if(strcmp(operation,"matadd") == 0){
                            if(strcmp(matrix1, a) == 0){
                                if(strcmp(matrix2, b) == 0){
                                    if(!(dim11==dim21 && dim12==dim22)) printf("Η πρόσθεση των πινάκων είναι αδύνατη.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim11;i++){
                                            for(int j=0; j<dim12;j++){
                                                printf("%f\t",A[i][j] + B[i][j]);
                                                TEMP[i][j] = A[i][j] + B[i][j];
                                            }
                                            printf("\n");
                                        }
                                        input(dim11,dim12);
                                    }
                                }else{
                                    if(!(dim11==dim31 && dim12==dim32)) printf("Η πρόσθεση των πινάκων είναι αδύνατη.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim11;i++){
                                            for(int j=0; j<dim12;j++){
                                                printf("%f\t",A[i][j] + C[i][j]);
                                                TEMP[i][j] = A[i][j] + C[i][j];
                                            }
                                            printf("\n");
                                        }
                                        input(dim11,dim12);
                                    }
                                }
                            }

                            if(strcmp(matrix1, b) == 0){
                                if(strcmp(matrix2, a) == 0){
                                    if(!(dim21==dim11 && dim22==dim12)) printf("Η πρόσθεση των πινάκων είναι αδύνατη.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim11;i++){
                                            for(int j=0; j<dim12;j++){
                                                printf("%f\t",A[i][j] + B[i][j]);
                                                TEMP[i][j] = A[i][j] + B[i][j];
                                            }
                                            printf("\n");
                                        }
                                        input(dim11,dim12);
                                    }
                                }else{
                                    if(!(dim21==dim31 && dim22==dim32)) printf("Η πρόσθεση των πινάκων είναι αδύνατη.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim21;i++){
                                            for(int j=0; j<dim22;j++){
                                                printf("%f\t",B[i][j] + C[i][j]);
                                                TEMP[i][j] = C[i][j] + B[i][j];
                                            }
                                            printf("\n");
                                        }
                                        input(dim21,dim22);
                                    }
                                }
                            }

                            if(strcmp(matrix1, c) == 0){
                                if(strcmp(matrix2, a) == 0){
                                    if(!(dim31==dim11 && dim32==dim12)) printf("Η πρόσθεση των πινάκων είναι αδύνατη.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim31;i++){
                                            for(int j=0; j<dim32;j++){
                                                printf("%f\t",A[i][j] + C[i][j]);
                                                TEMP[i][j] = A[i][j] + C[i][j];
                                            }
                                            printf("\n");
                                        }
                                        input(dim31,dim32);
                                    }
                                }else{
                                    if(!(dim21==dim31 && dim22==dim32)) printf("Η πρόσθεση των πινάκων είναι αδύνατη.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim31;i++){
                                            for(int j=0; j<dim32;j++){
                                                printf("%f\t",B[i][j] + C[i][j]);
                                                TEMP[i][j] = C[i][j] + B[i][j];
                                            }
                                            printf("\n");
                                        }
                                        input(dim21,dim22);
                                    }
                                }
                            }                        
                        }else if(strcmp(operation,"matsub") == 0){
                            if(strcmp(matrix1, a) == 0){
                                if(strcmp(matrix2, b) == 0){
                                    if(!(dim11==dim21 && dim12==dim22)) printf("Η πρόσθεση των πινάκων είναι αδύνατη.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim11;i++){
                                            for(int j=0; j<dim12;j++){
                                                printf("%f\t",A[i][j] - B[i][j]);
                                                TEMP[i][j] = A[i][j] - B[i][j];
                                            }
                                            printf("\n");
                                        }
                                        input(dim11,dim12);
                                    }
                                }else{
                                    if(!(dim11==dim31 && dim12==dim32)) printf("Η πρόσθεση των πινάκων είναι αδύνατη.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim11;i++){
                                            for(int j=0; j<dim12;j++){
                                                printf("%f\t",A[i][j] - C[i][j]);
                                                TEMP[i][j] = A[i][j] - C[i][j];
                                            }
                                            printf("\n");
                                        }
                                        input(dim11,dim12);
                                    }
                                }
                            }

                            if(strcmp(matrix1, b) == 0){
                                if(strcmp(matrix2, a) == 0){
                                    if(!(dim21==dim11 && dim22==dim12)) printf("Η πρόσθεση των πινάκων είναι αδύνατη.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim11;i++){
                                            for(int j=0; j<dim12;j++){
                                                printf("%f\t",A[i][j] - B[i][j]);
                                                TEMP[i][j] = A[i][j] - B[i][j];
                                            }
                                            printf("\n");
                                        }
                                        input(dim11,dim12);
                                    }
                                }else{
                                    if(!(dim21==dim31 && dim22==dim32)) printf("Η πρόσθεση των πινάκων είναι αδύνατη.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim21;i++){
                                            for(int j=0; j<dim22;j++){
                                                printf("%f\t",B[i][j] - C[i][j]);
                                                TEMP[i][j] = C[i][j] - B[i][j];
                                            }
                                            printf("\n");
                                        }
                                        input(dim21,dim22);
                                    }
                                }
                            }

                            if(strcmp(matrix1, c) == 0){
                                if(strcmp(matrix2, a) == 0){
                                    if(!(dim31==dim11 && dim32==dim12)) printf("Η πρόσθεση των πινάκων είναι αδύνατη.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim31;i++){
                                            for(int j=0; j<dim32;j++){
                                                printf("%f\t",A[i][j] - C[i][j]);
                                                TEMP[i][j] = A[i][j] - C[i][j];
                                            }
                                            printf("\n");
                                        }
                                        input(dim31,dim32);
                                    }
                                }else{
                                    if(!(dim21==dim31 && dim22==dim32)) printf("Η πρόσθεση των πινάκων είναι αδύνατη.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim31;i++){
                                            for(int j=0; j<dim32;j++){
                                                printf("%f\t",B[i][j] - C[i][j]);
                                                TEMP[i][j] = C[i][j] - B[i][j];
                                            }
                                            printf("\n");
                                        }
                                        input(dim21,dim22);
                                    }
                                }
                            }
                        }else if(strcmp(operation,"matsmul") == 0){
                            
                            scalor = atof(matrix2);
                            if(strcmp(matrix1, a) == 0) matsmul(A,dim11,dim12,scalor);
                            if(strcmp(matrix1, b) == 0) matsmul(B,dim21,dim22,scalor);
                            if(strcmp(matrix1, c) == 0) matsmul(C,dim31,dim32,scalor);
                                                        
                        }else if(strcmp(operation,"matmul") == 0){
                            if(strcmp(matrix1, a) == 0){
                                if(strcmp(matrix2, b) == 0){
                                    matmul(A,B,dim11,dim12,dim21,dim22);
                                }
                                else if(strcmp(matrix2, c) == 0){
                                    matmul(A,C,dim11,dim12,dim31,dim32);
                                }
                                else printf("Σφάλμα. Η διαδικασία απέτυχε.\n");
                            }

                            if(strcmp(matrix1, b) == 0){
                                if(strcmp(matrix2, a) == 0){
                                    matmul(B,A,dim21,dim22,dim11,dim12);
                                }
                                else if(strcmp(matrix2, c) == 0){
                                    matmul(B,C,dim21,dim22,dim31,dim32);
                                }
                                else printf("Σφάλμα. Η διαδικασία απέτυχε.\n");
                            }

                            if(strcmp(matrix1, c) == 0){
                                if(strcmp(matrix2, a) == 0){
                                    matmul(C,A,dim31,dim32,dim11,dim12);
                                }
                                else if(strcmp(matrix2, b) == 0){
                                    matmul(C,B,dim31,dim32,dim21,dim22);
                                }
                                else printf("Σφάλμα. Η διαδικασία απέτυχε.\n");
                            }
                        
                        
                        
                        }else if(strcmp(operation,"trans") == 0){
                            if(strcmp(matrix1, a) == 0) trans(A,dim11,dim12);
                            if(strcmp(matrix1, b) == 0) trans(B,dim21,dim22);
                            if(strcmp(matrix1, c) == 0) trans(C,dim31,dim32);
                        }else if(strcmp(operation,"oppos") == 0){
                            if(strcmp(matrix1, a) == 0) oppos(A,dim11,dim12);
                            if(strcmp(matrix1, b) == 0) oppos(B,dim21,dim22);
                            if(strcmp(matrix1, c) == 0) oppos(C,dim31,dim32);
                        }else if(strcmp(operation,"rowadd") == 0){
                            int row_ ,row = atoi(matrix2);
                            
                            
                           
                                if(strcmp(matrix1, a) == 0){ 
                                    if(!(row<1 || row>dim11)){
                                    printf("Ποια σειρά να προστεθεί στη σειρά %d: ",row);
                                    scanf("%d",&row_);
                                    row--;
                                    row_--;
                                    rowadd(A,dim11,dim12,row,row_);
                                    }else printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
                                }
                            
                            
                            
                                if(strcmp(matrix1, b) == 0){
                                    if(!(row<1 || row>dim21)){
                                    printf("Ποια σειρά να προστεθεί στη σειρά %d: ",row);
                                    scanf("%d",&row_);
                                    row--;
                                    row_--;
                                    rowadd(B,dim21,dim22,row,row_);
                                    }else printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
                                }
                            
                            
                            
                                if(strcmp(matrix1, c) == 0){
                                    if(!(row<1 || row>dim31)){
                                    printf("Ποια σειρά να προστεθεί στη σειρά %d: ",row);
                                    scanf("%d",&row_);
                                    row--;
                                    row_--;
                                    rowadd(C,dim31,dim32,row,row_);
                                    }else printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
                            
                                }
                        }else if(strcmp(operation,"rowmul") == 0){
                            int row_ ,row = atoi(matrix2);

                            
                            
                            
                                if(strcmp(matrix1, a) == 0){
                                    if(!(row<1 || row>dim11)){
                                     printf("Ποια σειρά να πολλαπλασιαστεί με τη σειρά %d: ",row);
                                    scanf("%d",&row_);
                                    row--;
                                    row_--;
                                    rowmul(A,dim11,dim12,row,row_);
                                    }else printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
                                }
                            
                            
                                if(strcmp(matrix1, b) == 0){
                                    if(!(row<1 || row>dim21)){
                                     printf("Ποια σειρά να πολλαπλασιαστεί με τη σειρά %d: ",row);
                                    scanf("%d",&row_);
                                    row--;
                                    row_--;
                                    rowmul(B,dim21,dim22,row,row_);
                                    }else printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
                                }
                            
                            
                                if(strcmp(matrix1, c) == 0){
                                    if(!(row<1 || row>dim31)){
                                     printf("Ποια σειρά να πολλαπλασιαστεί με τη σειρά %d: ",row);
                                    scanf("%d",&row_);
                                    row--;
                                    row_--;
                                    rowmul(C,dim31,dim32,row,row_);
                                    }else printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
                                }
                            
                        }else if(strcmp(operation,"coladd") == 0){
                            int row_ ,row = atoi(matrix2);

                            
                            
                           
                                if(strcmp(matrix1, a) == 0){
                                    if(!(row<1 || row>dim12)){
                                    printf("Ποια στήλη να προστεθεί στη στήλη %d: ",row);
                                    scanf("%d",&row_);
                                    row--;
                                    row_--;
                                    coladd(A,dim11,dim12,row,row_);
                                    }else printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
                                }
                            
                            
                                if(strcmp(matrix1, b) == 0){
                                    if(!(row<1 || row>dim22)){
                                    printf("Ποια στήλη να προστεθεί στη στήλη %d: ",row);
                                    scanf("%d",&row_);
                                    row--;
                                    row_--;
                                    coladd(B,dim21,dim22,row,row_);
                                    }else printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
                                }
                            
                           
                                if(strcmp(matrix1, c) == 0){
                                     if(!(row<1 || row>dim32)){
                                    printf("Ποια στήλη να προστεθεί στη στήλη %d: ",row);
                                    scanf("%d",&row_);
                                    row--;
                                    row_--;
                                    coladd(C,dim31,dim32,row,row_);
                                    }else printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
                                }
                            
                        }else if(strcmp(operation,"colmul") == 0){
                            int row_ ,row = atoi(matrix2);

                            
                            
                            
                                if(strcmp(matrix1, a) == 0){
                                    if(!(row<1 || row>dim12)){
                                    printf("Ποια στήλη να πολλαπλασιαστεί με τη στήλη %d: ",row);
                                    scanf("%d",&row_);
                                    row--;
                                    row_--;
                                    colmul(A,dim11,dim12,row,row_);
                                    }else printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
                                }
                            
                            
                                if(strcmp(matrix1, b) == 0){ 
                                    if(!(row<1 || row>dim22)){
                                    printf("Ποια στήλη να πολλαπλασιαστεί με τη στήλη %d: ",row);
                                    scanf("%d",&row_);
                                    row--;
                                    row_--;
                                    colmul(B,dim21,dim22,row,row_);
                                    }else printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
                                    }
                            
                            
                                if(strcmp(matrix1, c) == 0) { 
                                    if(!(row<1 || row>dim32)){
                                    printf("Ποια στήλη να πολλαπλασιαστεί με τη στήλη %d: ",row);
                                    scanf("%d",&row_);
                                    row--;
                                    row_--;
                                    colmul(C,dim31,dim32,row,row_);
                                    }else printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
                                    }
                            
                        }else if(strcmp(operation,"numrowadd") == 0){
                            int diff ,row = atoi(matrix2);
                            
                            
                            
                            
                                if(strcmp(matrix1, a) == 0){
                                    if(!(row<1 || row>dim11)){
                                    printf("Κατά πόσο μεταβάλεται η σειρά %d: ",row);
                                    scanf("%d",&diff);
                                    row--;
                                    numrowadd(A,dim11,dim12,row,diff);
                                    }else printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
                                }
                            
                            
                                if(strcmp(matrix1, b) == 0){
                                    if(!(row<1 || row>dim21)){
                                    printf("Κατά πόσο μεταβάλεται η σειρά %d: ",row);
                                    scanf("%d",&diff);
                                    row--;
                                    numrowadd(B,dim21,dim22,row,diff);
                                    }else printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
                                }
                            
                            
                                if(strcmp(matrix1, c) == 0){
                                    if(!(row<1 || row>dim31)){
                                    printf("Κατά πόσο μεταβάλεται η σειρά %d: ",row);
                                    scanf("%d",&diff);
                                    row--;
                                    numrowadd(A,dim31,dim32,row,diff);
                                    }else printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
                                }
                            
                        }else if(strcmp(operation,"numrowmul") == 0){
                            int scalor ,row = atoi(matrix2);

                            
                            
                            
                                if(strcmp(matrix1, a) == 0){
                                    if(!(row<1 || row>dim11)){
                                    printf("Κατά πόσο μεταβάλλεται η σειρά %d: ",row);
                                    scanf("%d",&scalor);
                                    row--;
                                    numrowadd(A,dim11,dim12,row,scalor);
                                    }else printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
                                }
                            
                            
                                if(strcmp(matrix1, b) == 0){
                                    if(!(row<1 || row>dim21)){
                                    printf("Κατά πόσο μεταβάλλεται η σειρά %d: ",row);
                                    scanf("%d",&scalor);
                                    row--;
                                    numrowadd(B,dim21,dim22,row,scalor);
                                    }else printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
                                }
                            
                            
                                if(strcmp(matrix1, c) == 0){
                                    if(!(row<1 || row>dim31)){
                                    printf("Κατά πόσο μεταβάλλεται η σειρά %d: ",row);
                                    scanf("%d",&scalor);
                                    row--;
                                    numrowadd(C,dim31,dim32,row,scalor);
                                    }else printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
                                }
                            
                        }else if(strcmp(operation,"numcoladd") == 0){
                            int diff,row = atoi(matrix2);

                            
                            //printf("sthlh %d/%d\n",row,dim12);
                            
                            
                                if(strcmp(matrix1, a) == 0){
                                    if(!(row<1 || row>dim12)){
                                    printf("Κατά πόσο μεταβάλεται η στήλη %d: ",row);
                                    scanf("%d",&diff);
                                    row--;
                                    numcoladd(A,dim11,dim12,row,diff);
                                    }else printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
                                }
                            
                            
                                if(strcmp(matrix1, b) == 0){
                                    if(!(row<1 || row>dim22)){
                                    printf("Κατά πόσο μεταβάλεται η στήλη %d: ",row);
                                    scanf("%d",&diff);
                                    row--;
                                    numcoladd(B,dim21,dim22,row,diff);
                                    }else printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
                                }
                            
                            
                                if(strcmp(matrix1, c) == 0){
                                    if(!(row<1 || row>dim32)){
                                    printf("Κατά πόσο μεταβάλεται η στήλη %d: ",row);
                                    scanf("%d",&diff);
                                    row--;
                                    numcoladd(C,dim31,dim32,row,diff);
                                    }else printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
                                }
                            
                        }else if(strcmp(operation,"numcolmul") == 0){
                            int scalor,row = atoi(matrix2);

                            
                            
                            
                                if(strcmp(matrix1, a) == 0){
                                    if(!(row<1 || row>dim12)){
                                    printf("Κατά πόσο μεταβάλεται η στήλη %d: ",row);
                                    scanf("%d",&scalor);
                                    row--;
                                    numcoladd(A,dim11,dim12,row,scalor);
                                    }else printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
                                }
                            
                            
                                if(strcmp(matrix1, b) == 0){
                                    if(!(row<1 || row>dim22)){
                                    printf("Κατά πόσο μεταβάλεται η στήλη %d: ",row);
                                    scanf("%d",&scalor);
                                    row--;
                                    numcoladd(B,dim21,dim22,row,scalor);
                                    }else printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
                                }
                            
                           
                                if(strcmp(matrix1, c) == 0){
                                     if(!(row<1 || row>dim32)){
                                    printf("Κατά πόσο μεταβάλεται η στήλη %d: ",row);
                                    scanf("%d",&scalor);
                                    row--;
                                    numcoladd(C,dim31,dim32,row,scalor);
                                    }else printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
                                }
                            
                        }else{
                            printf("Μη έγκυρη πράξη. Η διαδικασία ακυρώθηκε.\n");
                            choice = '0';
                            return;
                        }


                        if(error_check==3){
                            printf("Αυτός ο πίνακας δεν έχει ενεργοποιηθεί. Η διαδικασία ακυρώθηκε.\n");
                            return;
                        }else if(error_check1==3){
                            printf("Αυτός ο πίνακας δεν έχει ενεργοποιηθεί. Η διαδικασία ακυρώθηκε.\n");
                            return;
                        }
                        
                    }
                    fflush(stdin);
                    
            break;

            case '1': printf("Λίστα εντολών\n");
                    printf("--------------------------------------------------------------\n");                     //λιστα εντολων για τις πραξεις πινακων
                    printf("Ορίζουσα:                         det,()\n");                                           //ο διαχωρισμος της εντολης και των αναγνωριστικων τω πινακων γινεται με κομμα ','
                    printf("Αντίστροφος πίνακας:              inv,()\n");
                    printf("Συζυγής πίνακας:                  adj,()\n");
                    printf("Ίχνος πίνακα:                     trace,()\n");
                    printf("Πρόσθεση πινάκων:                 matadd,(),()\n");
                    printf("Αφαίρεση Πινάκων:                 matsub,(),()\n");
                    printf("Πολλαπλασιασμός πίνακα με αριθμό: matsmul,(),(scalar)\n");
                    printf("Πολλαπλασιασμός πινάκων:          matmul,(),()\n");
                    printf("Ανάστροφος πίνακας:               trans,()\n");
                    printf("Αντίθετος πίνακας:                oppos,()\n");
                    printf("Πρόσθεση μεταξύ σειρών:           rowadd,(),(row number affected)\n");
                    printf("Πολλαπλασιασμός μεταξύ σειρών:    rowmul,(),(row number affected)\n");
                    printf("Πρόσθεση μεταξύ στηλών:           coladd,(),(column number affected)\n");
                    printf("Πολλαπλασιασμός μεταξύ στηλών:    colmul,(),(row number affected)\n");
                    printf("Πρόσθεση αριθμού σε σειρά:        numrowadd,(),(row number affected)\n");
                    printf("Πολλαπλασιασμός αριθμού με σειρά: numrowmul,(),(row number affected)\n");
                    printf("Πρόσθεση αριθμού σε στήλη:        numcoladd,(),(column number affected)\n");
                    printf("Πολλαπλασιασμός αριθμού με στήλη: numcolmul,(),(column number affected)\n");
                    printf("--------------------------------------------------------------\n");
                    printf("Πατήστε οποιοδήποτε κουμπί για να συνεχίσετε.");
                    fgets(inputs,2,stdin);
                    fflush(stdin);
                    choice ='0';
            break;

            case '2': printf("Επιστροφή\n\n");                                                      //επιστροφη στο αρχικο μενου
                    status = '0';
            break;

            default: choice = '0';

            
        }

    }
}



int main(){                                                                 //κυρια συναρτηση
    for(int i=0; i<MAX_SIZE; i++){
        for(int j=0; j<MAX_SIZE; j++){
            A[i][j]=0;
            B[i][j]=0;
            C[i][j]=0;
            TEMP[i][j]=0;
        }
    }
    int array_index, int_choice;
    int status=1;
    printf("\n");
    char choice='0';
    
    while(status==1){
    
    switch(choice){                                                 
        case '0': printf("\n\n\n");
                            
                printf("1.Δημιουργία Συστοιχίας\n"                  //αρχικο μενου του προγραμματος
               "2.Προβολή Διαθέσιμων Συστοιχιών\n"                  //καθε επιλογη παραπεμπει σε ξεχωριστη συναρτηση παραπανω
               "3.Ενεργοποίηση Συστοιχίας\n"
               "4.Πράξεις Διανυσμάτων\n"
               "5.Πράξεις Πινάκων\n"
               "6.Τερματισμός Προγράμματος\n\n\n");
                
                scanf("%c", &choice);
                fflush(stdin);
                if(choice=='~'){
                    easter_egg();
                }
                else if(!(isdigit(choice))){
                    printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ.");
                    choice = '0';
                }else{ 
                    int_choice = atoi(&choice);                
                    if(int_choice>6 || int_choice<0){
                        printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ.");
                        choice = '0';
                    }
                }

                fflush(stdin);
        break;
        
        
        
        case '1': case1();                                      //παραπομπη στην πρωτη κυρια συναρτηση
                choice = '0';                                   //εκτελει τις εντολες για τη δημιουργια νεας συστοιχιας
        break;


        
        case '2': case2();                                      //παραπομπη στην δευτερηη κυρια συναρτηση
                choice = '0';                                   //προβαλλονται συστοιχιες(διαθεσιμες,ενεργες,διαγραφη,φορτωση κλπ)
        break;

        
        
        case '3': printf("Ενεργοποίηση Συστοιχίας\n");                      //τριτη επιλογη απο το κυριο μενου
                    printf("Θέση συστοιχίας(/3): ");                        
                    scanf("%c", &choice);
                    fflush(stdin);
            if(!(isdigit(choice))){
                printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ.");
                choice = '0';
            }else{ 
                int_choice = atoi(&choice); 
                array_index = int_choice;               
                if(int_choice>4 || int_choice<0){
                    printf("ΜΕΓΙΣΤΗ ΘΕΣΗ ΣΥΣΤΟΙΧΙΑΣ ΕΙΝΑΙ ΤΟ 3.");
                    choice = '0';
                }else{
                                           
                                                          //εισαγωγη της θεσης του πινακα που θα ενεργοποιηθει σε μια απο τις 3 πιθανες
                if(array_index==1){
                    do{
                        printf("Διαστάσεις της εισαγόμενης συστοιχίας: ");
                        scanf("%d%d", &dim11, &dim12);                              //ελεγχος για καθε μια απο τις επιλογες θεσης εισαγωγης                         
                    }while(dim11<1 && dim12<1);  
                    case3(dim11, dim12, 1);                                     //καλλειται η τριτη κυρια συναρτηση σε καθε περιπτωση με τις καταλληλες παραμετρους
                }                                                               //ετσι ωστε η συστοιχια να ενεργοποιηθει στη σωστη θεση
                if(array_index==2){
                    do{
                        printf("Διαστάσεις της εισαγόμενης συστοιχίας: ");
                        scanf("%d%d", &dim21, &dim22);
                    }while(dim21<1 && dim22<1); 
                    case3(dim21, dim22, 2);                   
                }
                if(array_index==3){
                    do{
                        printf("Διαστάσεις της εισαγόμενης συστοιχίας: ");
                        scanf("%d%d", &dim31, &dim32);
                    }while(dim31<1 && dim32<1);
                    case3(dim31, dim32, 3);
                }
                
                choice = '0';
                }

            }
            fflush(stdin);
        break;



        case '4': case4();                                                          //τεταρτη επιλογη απο το κυριο μενου
                choice = '0';                                                       //παραπομπη στην τεταρτη κυρια συναρτηση: πραξεις διανυσματων
        break;


        
        case '5': case5();                                                          //πεμπτη επιλογη απο το κυριο μενου
                choice = '0';                                                       //παραπομπη στην πεμπτη κυρια συναρτηση: πραξεις πινακων
        break;


        
        case '6':                                                                   //εκτη επιλογη απο το κυριο μενου
        status = 0;                                                                 //το προγραμμα τερματιζεται
        break;


        
        default: choice = 0;
    
    }

    }

 printf("\nΤερματισμός Προγράμματος.");
    return 0;
}
