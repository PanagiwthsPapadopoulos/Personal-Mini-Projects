#include <stdio.h>
#include <stdlib.h>

void input();

struct candidate {
        char name[20];
        int birth;
        int years;
        float efficiency1;
        float efficiency2;
        float efficiency3;       
        float efficiency4;
        float efficiency5;
        float efficiency6;
        float efficiency7;
        float efficiency8;
        float efficiency9;
        float efficiency10;
        float efficiency11;
        float efficiency12;

    };

int main(){

}


void input(){
    struct candidate candidate1;
    struct candidate candidate2;
    struct candidate candidate3;

// ΠΡΩΤΟΣ ΥΠΟΨΗΦΙΟΣ   
    printf("\nCandidate #1 please enter your name: ");
    scanf(" %s", &candidate1.name[20]);
    printf("%s", &candidate1.name[20]);
    
    printf("\nplease enter your year of birth: ");
    scanf(" %d", &candidate1.birth);
    printf("%d", candidate1.birth);
    
    printf("\nhow many years in company: ");
    scanf(" %d", &candidate1.years);
    printf("%d", candidate1.years);
    
    printf("\nenter productivity #1: ");
    scanf(" %f", &candidate1.efficiency1);
    if(candidate1.efficiency1 < 0.0 || candidate1.efficiency1 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }
    printf("%f", candidate1.efficiency1);

    printf("\nenter productivity #2: ");
    scanf(" %f", &candidate1.efficiency2);
    if(candidate1.efficiency2 < 0.0 || candidate1.efficiency2 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }
    printf("%f", candidate1.efficiency2);

    printf("\nenter productivity #3: ");
    scanf(" %f", &candidate1.efficiency3);
    if(candidate1.efficiency3 < 0.0 || candidate1.efficiency3 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }
    printf("%f", candidate1.efficiency3);

    printf("\nenter productivity #4: ");
    scanf(" %f", &candidate1.efficiency4);
    if(candidate1.efficiency4 < 0.0 || candidate1.efficiency4 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }
    printf("%f", candidate1.efficiency4);

    printf("\nenter productivity #5: ");
    scanf(" %f", &candidate1.efficiency5);
    if(candidate1.efficiency5 < 0.0 || candidate1.efficiency5 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }
    printf("%f", candidate1.efficiency5);

    printf("\nenter productivity #6: ");
    scanf(" %f", &candidate1.efficiency6);
    if(candidate1.efficiency6 < 0.0 || candidate1.efficiency6 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }
    printf("%f", candidate1.efficiency6);

    printf("\nenter productivity #7: ");
    scanf(" %f", &candidate1.efficiency7);
    if(candidate1.efficiency7 < 0.0 || candidate1.efficiency7 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }
    printf("%f", candidate1.efficiency7);

    printf("\nenter productivity #8: ");
    scanf(" %f", &candidate1.efficiency8);
    if(candidate1.efficiency8 < 0.0 || candidate1.efficiency8 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }
    printf("%f", candidate1.efficiency8);

    printf("\nenter productivity #9: ");
    scanf(" %f", &candidate1.efficiency9);
    if(candidate1.efficiency9 < 0.0 || candidate1.efficiency9 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }
    printf("%f", candidate1.efficiency9);

    printf("\nenter productivity #10: ");
    scanf(" %f", &candidate1.efficiency10);
    if(candidate1.efficiency10 < 0.0 || candidate1.efficiency10 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }
    printf("%f", candidate1.efficiency10);

    printf("\nenter productivity #11: ");
    scanf(" %f", &candidate1.efficiency11);
    if(candidate1.efficiency1 < 0.0 || candidate1.efficiency11 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }
    printf("%f", candidate1.efficiency11);

    printf("\nenter productivity #12: ");
    scanf(" %f", &candidate1.efficiency12);
    if(candidate1.efficiency12 < 0.0 || candidate1.efficiency12 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }
    printf("%f", candidate1.efficiency12);


//ΔΕΥΤΕΡΟΣ ΥΠΟΨΗΦΙΟΣ
   
    printf("\nCandidate #2 please enter your name: ");
    scanf(" %s", &candidate2.name[20]);
    
    printf("\nplease enter your year of birth: ");
    scanf(" %d", &candidate2.birth);
    
    printf("\nhow many years in company: ");
    scanf(" %d", &candidate2.years);
    
    printf("\nenter productivity #1: ");
    scanf(" %f", &candidate2.efficiency1);
    if(candidate2.efficiency1 < 0.0 || candidate2.efficiency1 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #2: ");
    scanf(" %f", &candidate2.efficiency2);
    if(candidate2.efficiency2 < 0.0 || candidate2.efficiency2 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #3: ");
    scanf(" %f", &candidate2.efficiency3);
    if(candidate2.efficiency3 < 0.0 || candidate2.efficiency3 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #4: ");
    scanf(" %f", &candidate2.efficiency4);
    if(candidate2.efficiency4 < 0.0 || candidate2.efficiency4 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #5: ");
    scanf(" %f", &candidate2.efficiency5);
    if(candidate2.efficiency5 < 0.0 || candidate2.efficiency5 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #6: ");
    scanf(" %f", &candidate2.efficiency6);
    if(candidate2.efficiency6 < 0.0 || candidate2.efficiency6 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #7: ");
    scanf(" %f", &candidate2.efficiency7);
    if(candidate2.efficiency7 < 0.0 || candidate2.efficiency7 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #8: ");
    scanf(" %f", &candidate2.efficiency8);
    if(candidate2.efficiency8 < 0.0 || candidate2.efficiency8 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #9: ");
    scanf(" %f", &candidate2.efficiency9);
    if(candidate2.efficiency9 < 0.0 || candidate2.efficiency9 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #10: ");
    scanf(" %f", &candidate2.efficiency10);
    if(candidate2.efficiency10 < 0.0 || candidate2.efficiency10 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #11: ");
    scanf(" %f", &candidate2.efficiency11);
    if(candidate2.efficiency1 < 0.0 || candidate2.efficiency11 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #12: ");
    scanf(" %f", &candidate2.efficiency12);
    if(candidate2.efficiency12 < 0.0 || candidate2.efficiency12 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }


// ΤΡΙΤΟΣ ΥΠΟΨΗΦΙΟΣ

printf("\nCandidate #3 please enter your name: ");
    scanf(" %s", &candidate3.name[20]);
    
    printf("\nplease enter your year of birth: ");
    scanf(" %d", &candidate3.birth);
    
    printf("\nhow many years in company: ");
    scanf(" %d", &candidate3.years);
    
    printf("\nenter productivity #1: ");
    scanf(" %f", &candidate3.efficiency1);
    if(candidate3.efficiency1 < 0.0 || candidate3.efficiency1 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #2: ");
    scanf(" %f", &candidate3.efficiency2);
    if(candidate3.efficiency2 < 0.0 || candidate3.efficiency2 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #3: ");
    scanf(" %f", &candidate3.efficiency3);
    if(candidate3.efficiency3 < 0.0 || candidate3.efficiency3 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #4: ");
    scanf(" %f", &candidate3.efficiency4);
    if(candidate3.efficiency4 < 0.0 || candidate3.efficiency4 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #5: ");
    scanf(" %f", &candidate3.efficiency5);
    if(candidate3.efficiency5 < 0.0 || candidate3.efficiency5 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #6: ");
    scanf(" %f", &candidate3.efficiency6);
    if(candidate3.efficiency6 < 0.0 || candidate3.efficiency6 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #7: ");
    scanf(" %f", &candidate3.efficiency7);
    if(candidate3.efficiency7 < 0.0 || candidate3.efficiency7 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #8: ");
    scanf(" %f", &candidate3.efficiency8);
    if(candidate3.efficiency8 < 0.0 || candidate3.efficiency8 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #9: ");
    scanf(" %f", &candidate3.efficiency9);
    if(candidate3.efficiency9 < 0.0 || candidate3.efficiency9 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #10: ");
    scanf(" %f", &candidate3.efficiency10);
    if(candidate3.efficiency10 < 0.0 || candidate3.efficiency10 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #11: ");
    scanf(" %f", &candidate3.efficiency11);
    if(candidate3.efficiency1 < 0.0 || candidate3.efficiency11 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }

    printf("\nenter productivity #12: ");
    scanf(" %f", &candidate3.efficiency12);
    if(candidate3.efficiency12 < 0.0 || candidate3.efficiency12 > 1.0){
        printf("ΜΗ ΕΓΚΥΡΗ ΕΓΧΩΡΗΣΗ. ΤΕΡΜΑΤΙΣΜΟΣ ΠΡΟΓΡΑΜΜΑΤΟΣ");
        exit(-1);
    }


    printf("Candidate: %s", &candidate1.name);
    printf("Age: %d", candidate1.birth);
    printf("Mean efficiency for past 12 months: ");

    printf("Candidate: %s", &candidate2.name);
    printf("Age: %d", candidate2.birth);
    printf("Mean efficiency for past 12 months: ");

    printf("Candidate: %s", &candidate3.name);
    printf("Age: %d", candidate3.birth);
    printf("Mean efficiency for past 12 months: ");


return 0;
}

