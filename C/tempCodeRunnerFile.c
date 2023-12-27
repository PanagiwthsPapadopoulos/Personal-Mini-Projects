#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 50

float A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE], TEMP[MAX_SIZE][MAX_SIZE];
char a[25], b[25], c[25];
int dim11=0, dim12, dim21=0, dim22, dim31=0, dim32;

float determinant(float mat[MAX_SIZE][MAX_SIZE], int column, int row){
    float Minor[MAX_SIZE][MAX_SIZE];
    int i,j,k,c1,c2,n;
    float deter=0;
    int O=1;
    
    if(column!=row) printf("Ο πίνακας δεν είναι τετραγωνικός.");
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

void matmul(float matrix1[MAX_SIZE][MAX_SIZE], float matrix2[MAX_SIZE][MAX_SIZE], int dim11, int dim12, int dim21, int dim22){
    if(!(dim12==dim21)) printf("Ο πολλαπλασιασμός αυτών των πινάκων δεν είναι δυνατός.\n");
    else{
        printf("O πίνακας είναι ο παρακάτω: \n");
        for(int i=0; i<dim11; i++){
            for(int k=0; k<dim22; k++){
                for(int j=0; j<dim12; j++){
                    TEMP[i][k] = TEMP[i][k] + matrix1[i][j] * matrix2[j][k];
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
}

void adjoint(float mat[MAX_SIZE][MAX_SIZE], int column, int row){
    float temp[MAX_SIZE][MAX_SIZE], det;
    int i,j,n;
    int O=1;
    det = determinant(mat, n,n);    
    if(det==0) printf("Σφάλμα. Ο πίνακας εχει διακρίνουσα 0.");
    else if(column==row) 
        {
        n = column;
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
                    for(int k=0; k < n-1; k++){                                   //TRACING POSITION OF THE TEMP MATRIX
                        for(int m=0; m < n-1; m++){
                            for(i=0; i<n; i++){
                                if(i==q) i++;                           
                                for(j=0; j<n; j++){                     //TRACING ELEMENTS OF INITIAL MATRIX FOR THE TEMP MATRIX
                                    if(j==l) j++;
                                    if(j>=n){
                                         j=0;
                                        if(i+1==q) i=i+2;
                                        else i++;
                                    }
                                    temp[k][m]=mat[i][j];
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
                    TEMP[q][l] = ( (O*determinant(temp, n-1,n-1)) );
                }
            }
        }                
    }
}

void matsmul(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, double scalor){
    printf("Ο πίνακας είναι ο:\n");
    for(int i=0;i<dim1;i++){
        for(int j=0;j<dim2;j++){
            printf("%f\t", scalor*matrix[i][j]);
        }
        printf("\n");
    }
}

void trans(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2){
    printf("Ο πίνακας είναι ο: \n");
    for(int i=0; i<dim1; i++){
        for(int j=0; j<dim2; j++){
            printf("%f\t", matrix[j][i]);
        }
        printf("\n");
    }
}

void rowadd(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int row_){
    if(row>dim1) printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(i==row) printf("%f\t",matrix[i][j]+matrix[row_][j]);
                else printf("%f\t",matrix[i][j]);
            }
            printf("\n");
        }
    }
}

void rowmul(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int row_){
    if(row>dim1) printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(i==row) printf("%f\t", (matrix[i][j]) * (matrix[row_][j]) );
                else printf("%f\t",matrix[i][j]);
            }
            printf("\n");
        }
    }
}

void coladd(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int row_){
    if(row>dim2) printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(j==row) printf("%f\t",matrix[i][j]+matrix[i][row_]);
                else printf("%f\t",matrix[i][j]);
            }
            printf("\n");
        }
    }
}

void colmul(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int row_){
    if(row>dim2) printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(i==row) printf("%f\t", (matrix[i][j]) * (matrix[i][row_]) );
                else printf("%f\t",matrix[i][j]);
            }
            printf("\n");
        }
    }
}

void numrowadd(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int diff){
    if(row>dim1) printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(i==row) printf("%f\t",matrix[i][j]+diff);
                else printf("%f\t",matrix[i][j]);
            }
            printf("\n");
        }
    }
}

void numrowmul(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int scalor){
    if(row>dim1) printf("Δεν υπάρχει η επιλεγμένη σειρά στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(i==row) printf("%f\t", (matrix[i][j]) * scalor );
                else printf("%f\t",matrix[i][j]);
            }
            printf("\n");
        }
    }
}

void numcoladd(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int diff){
    if(row>dim2) printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(j==row) printf("%f\t",matrix[i][j]+diff);
                else printf("%f\t",matrix[i][j]);
            }
            printf("\n");
        }
    }
}

void numcolmul(float matrix[MAX_SIZE][MAX_SIZE], int dim1, int dim2, int row, int scalor){
    if(row>dim2) printf("Δεν υπάρχει η επιλεγμένη στήλη στον πίνακα.\n");
    else{
        printf("Ο πίνακας είναι ο: \n");
        for(int i=0; i<dim1; i++){
            for(int j=0; j<dim2; j++){
                if(j==row) printf("%f\t", (matrix[i][j]) * scalor );
                else printf("%f\t",matrix[i][j]);
            }
            printf("\n");
        }
    }
}

void file_overview(){
    DIR *d;
  struct dirent *dir;
  d = opendir(".");
  printf("Οι διαθέσιμες συστοιχίες είναι οι παρακάτω:\n");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      if( strstr(dir->d_name, ".txt") != NULL )    printf("%s\n", dir->d_name);
    }
    closedir(d);
  }
}

void local_matrix(){
    char ch, source_file[30], directory[50], delete;
    FILE *source, *target;
    
    
    printf("\nΌνομα του αρχείου:\n");
    fgets(source_file,30,stdin);

    printf("Θέση του αρχείου:\n");
    scanf("%s",directory);

    strcat(directory, source_file);

    source = fopen(directory, "r");

    if( source == NULL ) printf("Η διαδικασία απέτυχε. Το αρχείο είναι κενό.");

    target = fopen(source_file, "w");
 
    while( ( ch = fgetc(source) ) != EOF )
       fputc(ch, target);
 
    printf("\nΗ συστοιχία φορτώθηκε επιτυχώς.\n"
            "Να αφαιρεθεί η αρχική συστοιχία;(y/n)");

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

void case1(){
    int dim1, dim2;
    char matrix_name[30], matrix_confirm;
    float matrix[30][30];
    int status = 1;
    char choice = '0';
    FILE *fptr;

        while(status==1){
        switch(choice){
            case '0':printf("\n\n\n");
                printf("Δημιουργία Συστοιχίας\n");
                        printf("1.Ορισμός αναγνωριστικού\n"       
                            "2.Ορισμός διαστάσεων και μηκών\n"
                            "3.Συμπλήρωση τιμών\n"
                            "4.Επιστροφή\n");
                    scanf("%c", &choice);
                    if(isalpha(choice)){
                            printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ.");
                            choice = '0';
                    }
                    fflush(stdin);
                    printf("\n\n\n");
            break;
            
            
            case '1':printf("Ορισμός αναγνωριστικού: \n");
                    fgets(matrix_name,30,stdin);
                    fflush(stdin);
                    matrix_name[strcspn(matrix_name, "\n")]='\0';
                    choice = '0';
                    printf("\nΕπιτυχής αποθήκευση αναγνωριστικού\n\n\n");
            break;


            case '2':printf("Ορισμός διαστάσεων και μηκών: \n");
                    do{
                        printf("Εισαγωγή Διαστάσεων:(c>1) r*c: ");
                        scanf("%d", &dim1);
                        scanf("%d", &dim2);
                        }while(dim1<1 || dim2<2);
                printf("\nΕπιτυχής εισαγωγή διαστάσεων.\n\n\n");
                fflush(stdin);
                choice='0';
            break;


            case '3':printf("Συμπλήρωση τιμών: \n");  
                    for(int i=0; i<dim1; i++){
                        for(int j=0; j<dim2; j++){
                            printf("Δώσε το στοιχείο %d.%d της συστοιχίας: ", i+1, j+1);
                            scanf("%f", &matrix[i][j]);
                        }
                    } 
                printf("\n");
                printf("Αποθήκευση Συστοιχίας;(y/n)");
                scanf(" %c", &matrix_confirm);  
                switch(matrix_confirm){
                    case 'n': printf("Η διαδικασία ακυρώθηκε.");
                              status = 0;
                    break;
                    case 'y': 
                            fptr = fopen(strcat(matrix_name, ".txt"),"w");
                            for(int i=0; i<dim1; i++){
                                for(int j=0; j<dim2; j++){
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
        
        
            case '4': printf("Επιστροφή.");
                    printf("\n\n");
                    status = 0;
            break;

            
            default: printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ");
                    choice = '0';
        
        
        }

        }


}

void case2(){
  char delete_name[30];
  char choice = '0';
  int status = 1, error_check = 0;
  fflush(stdin);

  while(status==1){
      switch(choice){
        case '0': printf("Προβολή Διαθέσιμων Συστοιχιών\n");
                printf("1.Προβολή ενεργών συστοιχιών\n");
                printf("2.Προβολή φορτωμένων συστοιχιών\n");
                printf("3.Τοπική φόρτωση συστοιχίας\n");
                printf("4.Απενεργοποίηση συστοιχίας\n");
                printf("5.Διαγραφή φορτωμένης συστοιχίας\n");
                printf("6.Επιστροφή\n");

                scanf("%c", &choice);
                if(isalpha(choice)){
                    printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ.");
                    choice = '0';
                }
                fflush(stdin);
        break;
        
        case '1':printf("\n\n\nΠροβολή ενεργών συστοιχιών\n");
                
                if(dim11==0) printf("Θέση 1: Συστοιχία κενή.\n");
                else{
                    printf("Θέση 1: Συστοιχία %s\n", a);
                    for(int i=0; i<dim11; i++){
                        for(int j=0; j<dim12; j++){
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
                printf("\n\n\n\n");
                choice = '0';
        break;

        case '2':printf("\n\nΠροβολή φορτωμένων συστοιχιών\n");
                file_overview();
                choice = '0';
                printf("\n\n\n");
        break;

        case '3':printf("Τοπική φόρτωση συστοιχίας(.txt only)\n");
                local_matrix();
                choice = '0';
                printf("\n\n\n");
        break;

        case '4':printf("\n\nΑπενεργοποίηση συστοιχίας\n");
                printf("Όνομα συστοιχίας που θα απενεργοποιηθεί: ");
                fgets(delete_name,30,stdin);
                delete_name[strcspn(delete_name, "\n")]='\0';
                
                if(strcmp(delete_name, a) == 0){
                    dim11 = 0;
                    printf("Απενεργοποιήθηκε η συστοιχία 1. \n");
                }else error_check++;
                
                if(strcmp(delete_name, b) == 0){
                    dim21 = 0;
                    printf("ΔΑπενεργοποιήθηκε η συστοιχία 2. \n");
                }else error_check++;
                
                if(strcmp(delete_name, c) == 0){
                    dim31 = 0;
                    printf("Απενεργοποιήθηκε η συστοιχία 3. \n");
                }else error_check++;
                
                if(error_check==3) printf("ΣΦΑΛΜΑ. Η ΔΙΑΔΙΚΑΣΙΑ ΑΚΥΡΩΘΗΚΕ.");

                choice = '0';
                printf("\n\n\n");
        break;

        case '5':printf("\n\nΔιαγραφή φορτωμένης συστοιχίας\n");
                printf("Όνομα συστοιχίας που θα διαγραφεί: ");
                fgets(delete_name,30,stdin);
                delete_name[strcspn(delete_name, "\n")]='\0';
                strcat(delete_name, ".txt");
                remove(delete_name);
                printf("\nΗ συστοιχία διαγράφηκε επιτυχώς.");
                choice = '0';
                printf("\n\n\n");
        break;

        case '6':printf("Επιστροφή\n");
                status = 0;
        break;
  
        default: printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ");
                choice = '0';
        
    }
}

printf("\n\n\n");
}

void case3(int dim1, int dim2, int index){
  file_overview();
  fflush(stdin);
    char name[25];
    FILE *fptr; 


    printf("\n\n");
    printf("\nΌνομα της συστοιχίας: ");

    fgets(name,25,stdin);

    name[strcspn(name, "\n")]='\0';

    if(index==1) strcpy(a,name);
    if(index==2) strcpy(b,name);
    if(index==3) strcpy(c,name);

    fptr = fopen(strcat(name, ".txt"),"r");

    for(int i=0; i<dim1; i++){
        for(int j=0; j<dim2; j++){
            if(index==1)fscanf(fptr,"%f", &A[i][j]);
            if(index==2)fscanf(fptr,"%f", &B[i][j]);
            if(index==3)fscanf(fptr,"%f", &C[i][j]);
        }
    } 

}

void case4(){

}

void case5(){
  char operation[10],matrix1[20],matrix2[20];
  float num, det=1, scalor=999;
  int i=0, j=0, k=0, error_check=0;
  
  int status = 1;
  char choice = '0', input[50];
  fflush(stdin);

    while(status==1){
        switch(choice){
    
            case '0': printf("\n\nΠράξεις Πινάκων\n");
                    printf("1.Λίστα εντολών\n");
                    printf("2.Επιστροφή\n");
                    printf("Δώσε εντολή...\n");
                    fflush(stdin);
                    fgets( input, 50, stdin);

                    input[strcspn(input, "\n")]='\0';

                    status = 0;
                    if(strcmp(input, "0") == 0){
                         choice = '0';
                        status = 1;
                    }
                    
                    else if(strcmp(input, "1") == 0){
                         choice = '1';
                        status = 1;
                    }
                    
                    else if(strcmp(input, "2") == 0) choice = '2';                    
                    
                    else{
                        while(input[i]!=','){
                            operation[i]=input[i];
                            i++;
                        }
                        operation[i]='\0';
                        i++;
                        printf(" %s ",operation);
                        while(input[i]!=',' && input[i]!='\0'){
                            matrix1[j]=input[i];
                            i++;
                            j++;
                        }
                        matrix1[j]='\0';
                        i++;
                        while(input[i]!=',' && input[i]!='\0'){
                            matrix2[k]=input[i];
                            i++;
                            k++;
                        }
                        matrix2[k]='\0';
                        

                        printf("%c %s ",input[3], matrix1);
                        printf("%c%c",input[4],input[5]);
    
                        if(strcmp(matrix1, a) != 0) error_check++;
                        if(strcmp(matrix1, b) != 0) error_check++;
                        if(strcmp(matrix1, c) != 0) error_check++;
    
                        if(error_check==3){
                            printf("Αυτός ο πίνακας δεν έχει ενεργοποιηθεί. Η διαδικασία ακυρώθηκε.\n");
                        }else if(strcmp(operation,"det") == 0){
                            if(strcmp(matrix1, a) == 0) printf("Η διακρίνουσα του πίνακα %s είναι: %f", a,determinant(A, dim11, dim12));
                            if(strcmp(matrix1, b) == 0) printf("Η διακρίνουσα του πίνακα %s είναι: %f", b,determinant(B, dim21, dim22));
                            if(strcmp(matrix1, c) == 0) printf("Η διακρίνουσα του πίνακα %s είναι: %f", c,determinant(C, dim31, dim32));
                        
                        }else if(strcmp(operation,"inv") == 0){
                                    printf("This is it");
                            
                            if(strcmp(matrix1, a) == 0){
                                adjoint(A, dim11, dim12);
                                printf("O αντιστροφος πίνακας είναι ο:\n");
                                    for(int i=0; i<dim11; i++){
                                        for(int j=0; j<dim12; j++){
                                            printf("%f\t", TEMP[i][j]);
                                        }
                                        printf("\n");
                                    }
                            }       
                            /*
                            if(strcmp(matrix1, b) == 0){
                                adjoint(B, dim21, dim22);
                                det = determinant(B, dim21, dim22);
                                if(det==0) printf("Ο πίνακας εχει διακρίνουσα 0 και δεν αντιστρέφεται");
                                else{ printf("O αντιστροφος πίνακας είναι ο:\n");
                                    for(int i=0; i<dim21; i++){
                                        for(int j=0; j<dim22; j++){
                                            printf("%f\t", TEMP[i][j]);
                                        }
                                        printf("\n");
                                    }
                                }   
                            }
                            if(strcmp(matrix1, c) == 0){
                                adjoint(C, dim31, dim32);
                                det = determinant(C, dim31, dim32);
                                if(det==0) printf("Ο πίνακας εχει διακρίνουσα 0 και δεν αντιστρέφεται");
                                else{ printf("ο αντιστροφος πίνακας είναι ο:\n");
                                    for(int i=0; i<dim31; i++){
                                        for(int j=0; j<dim32; j++){
                                            printf("%f\t", TEMP[i][j]);
                                        }
                                        printf("\n");
                                    }
                                }   
                            }*/

                        }else if(strcmp(operation,"adj") == 0){
                            if(strcmp(matrix1, a) == 0){
                                adjoint(A, dim11, dim12);
                                printf("O αναστροφος πίνακας είναι ο:\n");
                                    for(int i=0; i<dim11; i++){
                                        for(int j=0; j<dim12; j++){
                                            printf("%f\t", TEMP[i][j]);
                                        }
                                        printf("\n");
                                    }
                            }
                        }else if(strcmp(operation,"trace") == 0){
                            int smallest=999;
                            float trace=0;
                            if(strcmp(matrix1, a) == 0){
                                if(dim11<smallest) smallest = dim11;
                                else smallest = dim12;
                                for(int i=0; i<smallest; i++){
                                    trace = trace + A[i][i];
                                }
                            }
                            if(strcmp(matrix1, b) == 0){
                                if(dim21<smallest) smallest = dim21;
                                else smallest = dim22;
                                for(int i=0; i<smallest; i++){
                                    trace = trace + B[i][i];
                                }
                            }
                            if(strcmp(matrix1, c) == 0){
                                if(dim31<smallest) smallest = dim31;
                                else smallest = dim32;
                                for(int i=0; i<smallest; i++){
                                    trace = trace + C[i][i];
                                }
                            }

                            printf("Το ίχνος του πίνακα %s είναι %.2f", matrix1,trace);
                        
                        }else if(strcmp(operation,"matadd") == 0){
                            if(strcmp(matrix1, a) == 0){
                                if(strcmp(matrix2, b) == 0){
                                    if(!(dim11==dim21 && dim12==dim22)) printf("Η πρόσθεση των πινάκων είναι αδύνατη1.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim11;i++){
                                            for(int j=0; j<dim12;j++){
                                                printf("%f\t",A[i][j] + B[i][j]);

                                            }
                                            printf("\n");
                                        }
                                    }
                                }else{
                                    if(!(dim11==dim31 && dim12==dim32)) printf("Η πρόσθεση των πινάκων είναι αδύνατη2.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim11;i++){
                                            for(int j=0; j<dim12;j++){
                                                printf("%f\t",A[i][j] + C[i][j]);

                                            }
                                            printf("\n");
                                        }
                                    }
                                }
                            }

                            if(strcmp(matrix1, b) == 0){
                                if(strcmp(matrix2, a) == 0){
                                    if(!(dim21==dim11 && dim22==dim12)) printf("Η πρόσθεση των πινάκων είναι αδύνατη3.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim11;i++){
                                            for(int j=0; j<dim12;j++){
                                                printf("%f\t",A[i][j] + B[i][j]);

                                            }
                                            printf("\n");
                                        }
                                    }
                                }else{
                                    if(!(dim21==dim31 && dim22==dim32)) printf("Η πρόσθεση των πινάκων είναι αδύνατη4.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim21;i++){
                                            for(int j=0; j<dim22;j++){
                                                printf("%f\t",B[i][j] + C[i][j]);

                                            }
                                            printf("\n");
                                        }
                                    }
                                }
                            }

                            if(strcmp(matrix1, c) == 0){
                                if(strcmp(matrix2, a) == 0){
                                    if(!(dim31==dim11 && dim32==dim12)) printf("Η πρόσθεση των πινάκων είναι αδύνατη5.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim31;i++){
                                            for(int j=0; j<dim32;j++){
                                                printf("%f\t",A[i][j] + C[i][j]);

                                            }
                                            printf("\n");
                                        }
                                    }
                                }else{
                                    if(!(dim21==dim31 && dim22==dim32)) printf("Η πρόσθεση των πινάκων είναι αδύνατη6.\n");
                                    else{
                                        printf("Ο τελικός πίνακας είναι ο:\n");
                                        for (int i=0;i<dim31;i++){
                                            for(int j=0; j<dim32;j++){
                                                printf("%f\t",B[i][j] + C[i][j]);

                                            }
                                            printf("\n");
                                        }
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
                        }else if(strcmp(operation,"rowadd") == 0){
                            int row_ ,row = atoi(matrix2);

                            printf("Ποια σειρά να προστεθεί στη σειρά %d: ",row);
                            scanf("%d",&row_);
                            row--;
                            row_--;
                            
                            if(strcmp(matrix1, a) == 0) rowadd(A,dim11,dim12,row,row_);
                            if(strcmp(matrix1, b) == 0) rowadd(B,dim21,dim22,row,row_);
                            if(strcmp(matrix1, c) == 0) rowadd(C,dim31,dim32,row,row_);
                        }else if(strcmp(operation,"rowmul") == 0){
                            int row_ ,row = atoi(matrix2);

                            printf("Ποια σειρά να πολλαπλασιαστεί με τη σειρά %d: ",row);
                            scanf("%d",&row_);
                            row--;
                            row_--;
                            
                            if(strcmp(matrix1, a) == 0) rowmul(A,dim11,dim12,row,row_);
                            if(strcmp(matrix1, b) == 0) rowmul(B,dim21,dim22,row,row_);
                            if(strcmp(matrix1, c) == 0) rowmul(C,dim31,dim32,row,row_);
                        }else if(strcmp(operation,"coladd") == 0){
                            int row_ ,row = atoi(matrix2);

                            printf("Ποια στήλη να προστεθεί στη στήλη %d: ",row);
                            scanf("%d",&row_);
                            row--;
                            row_--;
                            
                            if(strcmp(matrix1, a) == 0) coladd(A,dim11,dim12,row,row_);
                            if(strcmp(matrix1, b) == 0) coladd(B,dim21,dim22,row,row_);
                            if(strcmp(matrix1, c) == 0) coladd(C,dim31,dim32,row,row_);
                        }else if(strcmp(operation,"colmul") == 0){
                            int row_ ,row = atoi(matrix2);

                            printf("Ποια στήλη να πολλαπλασιαστεί με τη στήλη %d: ",row);
                            scanf("%d",&row_);
                            row--;
                            row_--;
                            
                            if(strcmp(matrix1, a) == 0) colmul(A,dim11,dim12,row,row_);
                            if(strcmp(matrix1, b) == 0) colmul(B,dim21,dim22,row,row_);
                            if(strcmp(matrix1, c) == 0) colmul(C,dim31,dim32,row,row_);
                        }else if(strcmp(operation,"numrowadd") == 0){
                            int diff ,row = atoi(matrix2);
                            
                            printf("Κατά πόσο μεταβάλεται η σειρά %d: ",row);
                            scanf("%d",&diff);
                            row--;
                            
                            if(strcmp(matrix1, a) == 0) numrowadd(A,dim11,dim12,row,diff);
                            if(strcmp(matrix1, b) == 0) numrowadd(B,dim21,dim22,row,diff);
                            if(strcmp(matrix1, c) == 0) numrowadd(C,dim31,dim32,row,diff);
                        }else if(strcmp(operation,"numrowmul") == 0){
                            int scalor ,row = atoi(matrix2);

                            printf("Κατά πόσο μεταβάλλεται η σειρά %d: ",row);
                            scanf("%d",&scalor);
                            row--;
                            
                            if(strcmp(matrix1, a) == 0) numrowmul(A,dim11,dim12,row,scalor);
                            if(strcmp(matrix1, b) == 0) numrowmul(B,dim21,dim22,row,scalor);
                            if(strcmp(matrix1, c) == 0) numrowmul(C,dim31,dim32,row,scalor);
                        }else if(strcmp(operation,"numcoladd") == 0){
                            int diff,row = atoi(matrix2);

                            printf("Κατά πόσο μεταβάλεται η στήλη %d: ",row);
                            scanf("%d",&diff);
                            row--;
                            
                            if(strcmp(matrix1, a) == 0) numcoladd(A,dim11,dim12,row,diff);
                            if(strcmp(matrix1, b) == 0) numcoladd(B,dim21,dim22,row,diff);
                            if(strcmp(matrix1, c) == 0) numcoladd(C,dim31,dim32,row,diff);
                        }else if(strcmp(operation,"numcolmul") == 0){
                            int scalor,row = atoi(matrix2);

                            printf("Κατά πόσο μεταβάλεται η στήλη %d: ",row);
                            scanf("%d",&scalor);
                            row--;
                            
                            if(strcmp(matrix1, a) == 0) numcolmul(A,dim11,dim12,row,scalor);
                            if(strcmp(matrix1, b) == 0) numcolmul(B,dim21,dim22,row,scalor);
                            if(strcmp(matrix1, c) == 0) numcolmul(C,dim31,dim32,row,scalor);
                        }

                        
                    }
                    fflush(stdin);
                    
            break;

            case '1': printf("Λίστα εντολών\n");
                    printf("--------------------------------------------------------------\n");
                    printf("Ορίζουσα:                         det,()\n");
                    printf("Αντίστροφος πίνακας:              inv,()\n");
                    printf("Ανάστροφος πίνακας:               adj,()\n");
                    printf("Ίχνος πίνακα:                     trace,()\n");
                    printf("Πρόσθεση πινάκων:                 matadd,(),()\n");
                    printf("Πολλαπλασιασμός πίνακα με αριθμό: matsmul,(scalor)\n");
                    printf("Πολλαπλασιασμός πινάκων:          matmul,(),()\n");
                    printf("Μεταθετικός πίνακας:              trans,()\n");
                    printf("Πρόσθεση μεταξύ σειρών:           rowadd,(),(number)\n");
                    printf("Πολλαπλασιασμός μεταξύ σειρών:    rowmul,(),(number)\n");
                    printf("Πρόσθεση μεταξύ στηλών:           colladd,(),(number)\n");
                    printf("Πολλαπλασιασμός μεταξύ στηλών:    colmul,(),(number)\n");
                    printf("Πρόσθεση αριθμού σε σειρά:        numrowadd,(),(number)\n");
                    printf("Πολλαπλασιασμός αριθμού με σειρά: numrowmul,(),(scalor)\n");
                    printf("Πρόσθεση αριθμού σε στήλη:        numcoladd,(),(number)\n");
                    printf("Πολλαπλασιασμός αριθμού με στήλη: numcolmul,(),(number)\n");
                    printf("--------------------------------------------------------------\n");
                    printf("Πατήστε οποιοδήποτε κουμπί για να συνεχίσετε.");
                    fgets(input,2,stdin);
                    fflush(stdin);
                    choice ='0';
            break;

            case '2': printf("Επιστροφή\n\n");
                    status = '0';
            break;

            default: choice = '0';

            
        }

    }
}


int main(){
    for(int i=0; i<MAX_SIZE; i++){
        for(int j=0; j<MAX_SIZE; j++){
            A[i][j]=0;
            B[i][j]=0;
            C[i][j]=0;
            TEMP[i][j]=0;
        }
    }
    int array_index;
    int status=1;
    printf("\n");
    char choice='0';
    
    while(status==1){
    
    switch(choice){
        case '0': printf("\n\n\n");
                printf("1.Δημιουργία Συστοιχίας\n"
               "2.Προβολή Διαθέσιμων Συστοιχιών\n"
               "3.Ενεργοποίηση Συστοιχίας\n"
               "4.Πράξεις Διανυσμάτων\n"
               "5.Πράξεις Πινάκων\n"
               "6.Τερματισμός Προγράμματος\n\n\n");
                
                scanf("%c", &choice);
                if(isalpha(choice)){
                    printf("ΜΗ ΕΓΚΥΡΗ ΕΙΣΑΓΩΓΗ.");
                    choice = '0';
                }
                fflush(stdin);
        break;
        
        
        
        case '1': case1();
                choice = '0';
        break;


        
        case '2': case2();
                choice = '0';
        break;

        
        
        case '3': printf("Ενεργοποίηση Συστοιχίας\n");
                    printf("Θέση συστοιχίας(/3): ");
                    scanf("%d",&array_index);
                printf("Διαστάσεις της εισαγόμενης συστοιχίας: ");
                if(array_index==1){
                    scanf("%d%d", &dim11, &dim12);
                    case3(dim11, dim12, 1);
                }
                if(array_index==2){
                    scanf("%d%d", &dim21, &dim22);
                    case3(dim21, dim22, 2);
                }
                if(array_index==3){
                    scanf("%d%d", &dim31, &dim32);
                    case3(dim31, dim32, 3);
                }
                printf("Η συστοιχία φορτώθηκε επιτυχώς.");
                choice = '0';
        break;



        case '4': case4();
                choice = '0';
        break;


        
        case '5': case5();
                choice = '0';
        break;


        
        case '6': 
        status = 0;
        break;


        
        default: choice = 0;
    
    }

    }

printf("\nΤερματισμός Προγράμματος.");
    return 0;
}