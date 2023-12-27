#include <stdio.h>
#include <stdlib.h>

void input1(char name1[], int birth[], int years[], float productivity1[], float meanefficiency[]);
void input2(char name2[], int birth[], int years[], float productivity2[], float meanefficiency[]);
void input3(char name3[], int birth[], int years[], float productivity3[], float meanefficiency[]);
void prospect1(int years[], float productivity1[], float prospect[]);
void prospect2(int years[], float productivity2[], float prospect[]);
void prospect3(int years[], float productivity3[], float prospect[]);

int main(){

    char name1[30];                                                                    //ονομα πρωτου υποψηφιου
    char name2[30];                                                                    // ονομα δευτερου υποψηφιου
    char name3[30];                                                                     // ονομα τριτου υποψηφιου
    int birth[3];                                                                       // πινακας με της ημερομηνιες γεννησης    θεση 0--> υποψηφιος 1
    int years[3];                                                                      // πινακας με τα χρονια εργασιας στην εταιρια    θεση 0--> υποψηφιος 1
    float productivity1[12];                                                          // δεικτες αποδοτικοτητας πρωτου υποψηφιου για τους τελευταιους 12 μηνες
    float productivity2[12];                                                            // δεικτες αποδοτικοτητας δευτερου υποψηφιου για τους τελευταιους 12 μηνες
    float productivity3[12];                                                             // δεικτες αποδοτικοτητας τριτου υποψηφιου για τους τελευταιους 12 μηνες
    float meanefficiency[] = {0, 0, 0};                                                 // μεσος ορος δεικτων αποδοτικοτητας
    float prospect[] = {0, 0, 0};

    
    input1(name1, birth, years, productivity1, meanefficiency);
    input2(name2, birth, years, productivity2, meanefficiency);
    input3(name3, birth, years, productivity3, meanefficiency);

    printf("\n\n Candidate: %s", &name1[30]);                                               // εκτυπωση δεδομενων για τον πρωτο υποψηφιο
    printf("\n Age: %d", birth[0]);
    printf("\t\t Years in company: %d", years[0]);
    printf("\n Mean efficiency for past 12 months: %.2f", meanefficiency[0]);

    printf("\n\n Candidate: %s", &name2[30]);
    printf("\n Age: %d", birth[1]);                                                         //εκτυπωση δεδομενων για τον δευτερο υποψηφιο
    printf("\t\t Years in company: %d", years[1]);
    printf("\n Mean efficiency for past 12 months: %.2f", meanefficiency[1]);

    printf("\n\n Candidate: %s", &name3[30]);
    printf("\n Age: %d", birth[2]);                                                         //εκτυπωση δεδομενων για τον τριτο υποψηφιο
    printf("\t\t Years in company: %d", years[2]);
    printf("\n Mean efficiency for past 12 months: %.2f", meanefficiency[2]);



    prospect1(years, productivity1, prospect);
    prospect2(years, productivity2, prospect);
    prospect3(years, productivity3, prospect);

    printf("\n\n Candidate: %s", &name1[30]);
    printf("\t\t Candidacy prospect: %.2f", prospect[0]);
    printf("\n\n Candidate: %s", &name2[30]);
    printf("\t\t Candidacy prospect: %.2f", prospect[1]);
    printf("\n\n Candidate: %s", &name3[30]);
    printf("\t\t Candidacy prospect: %.2f", prospect[2]);

    
    if( prospect[0] < 6.67 && prospect[1] < 6.67 && prospect[2] < 6.67 || prospect[0] == prospect[1] == prospect[2]){           //καθορισμος απονομης προαγωγης
        printf("Unfortunately none of the candidates are eligible for a promotion.");
    } else if(prospect[0]>prospect[1] && prospect[0]>prospect[2]){
        printf("\nCongratulations %s for your new promotion!", &name1[30]);
    }else if(prospect[1]>prospect[2]){
        printf("\nCongratulations %s for your new promotion!", &name2[30]);
    }else printf("\nCongratulations %s for your new promotion!", &name3[30]);
    
    
 

return 0;
}


void input1(char name1[], int birth[], int years[], float productivity1[], float meanefficiency[]){                // εγχωρηση δεδομενων για τον πρωτο υποψηφιο.
    
    printf("\n Candidate #1 please enter your name: ");
    scanf(" %s", &name1[30]);

    printf(" Please enter your year of birth: ");
    scanf(" %d", &birth[0]);

    printf(" How many years in company: ");
    scanf(" %d", &years[0]);

    for(int i=0; i<12; i++){
        printf(" Enter productivity #%d: ", i+1);
        scanf(" %f", &productivity1[i]);
        if( productivity1[i] < 0.0 || productivity1[i] > 1.0){
            printf("INVALID INPUT. TERMINATING PROGRAM.");
            exit(-1);
        }
        meanefficiency[0] = meanefficiency[0] + productivity1[i];
    }

    meanefficiency[0] = meanefficiency[0] / 12;
    
    
}

void input2(char name2[], int birth[], int years[], float productivity2[], float meanefficiency[]){                   // εγχωρηση δεδομενων για τον δευτερο υποψηφιο.
    
    printf("\n Candidate #2 please enter your name: ");
    scanf(" %s", &name2[30]);

    printf(" Please enter your year of birth: ");
    scanf(" %d", &birth[1]);

    printf(" How many years in company: ");
    scanf(" %d", &years[1]);

    for(int i=0; i<12; i++){
        printf(" Enter productivity #%d: ", i+1);
        scanf(" %f", &productivity2[i]);
        if( productivity2[i] < 0.0 || productivity2[i] > 1.0){
            printf("INVALID INPUT. TERMINATING PROGRAM.");
            exit(-1);
        }
        meanefficiency[1] = meanefficiency[1] + productivity2[i];
    }
    meanefficiency[1] = meanefficiency[1] / 12;

   
}


void input3(char name3[], int birth[], int years[], float productivity3[], float meanefficiency[]){                 // εγχωρηση δεδομενων για τον τριτο υποψηφιο.
    
    printf("\n Candidate #3 please enter your name: ");
    scanf(" %s", &name3[30]);

    printf(" Please enter your year of birth: ");
    scanf(" %d", &birth[2]);

    printf(" How many years in company: ");
    scanf(" %d", &years[2]);

    for(int i=0; i<12; i++){
        printf(" Enter productivity #%d: ", i+1);
        scanf(" %f", &productivity3[i]);
        if( productivity3[i] < 0.0 || productivity3[i] > 1.0){
            printf("INVALID INPUT. TERMINATING PROGRAM.");
            exit(-1);
        }
        meanefficiency[2] = meanefficiency[2] + productivity3[i];
    }
    meanefficiency[2] = meanefficiency[2] / 12;

    
}


void prospect1(int years[], float productivity1[], float prospect[]){
    int y=0;
    float points = 0.0;
    prospect[0] = (years[0] * 0.6);
    if (prospect[0] > 5) prospect[0] = 5;                                                                               //απονομη βαθμων με βαση τα χρονια

    for(int i=0; i<12; i++){
        if (productivity1[i] > 0.68) prospect[0] = prospect[0] + 0.4;                                 // απονομη βαθμων με βαση το βαθμο αποδοτικοτητας καθε μηνα
        else if(productivity1[i] < 0.2) y++;
    }
    if(years[0] < 2 || y > 4 ) prospect[0] = 0;

}

void prospect2(int years[], float productivity2[], float prospect[]){
    int y=0;
    float points = 0.0;
    prospect[1] = (years[1] * 0.6);
    if (prospect[1] > 5) prospect[1] = 5;                                                                               // απονομη βαθμων με βαση τα χρονια

    for(int i=0; i<12; i++){
        if (productivity2[i] > 0.68) prospect[1] = prospect[1] + 0.4;                                 // απονομη βαθμων με βαση το βαθμο αποδοτικοτητας καθε μηνα
        else if(productivity2[i] < 0.2) y++;
     }
    if(years[1] < 2 || y > 4 ) prospect[1] = 0;


}

void prospect3(int years[], float productivity3[], float prospect[]){
    int y=0;
    prospect[2] = (years[2] * 0.6);
    if (prospect[2] > 5) prospect[2] = 5;                                                                               // απονομη βαθμων με βαση τα χρονια

    for(int i=0; i<12; i++){
        if (productivity3[i] > 0.68) prospect[2] = prospect[2] + 0.4;                                 // απονομη βαθμων με βαση το βαθμο αποδοτικοτητας καθε μηνα
        else if(productivity3[i] < 0.2) y++;
    }
    if(years[2] < 2 || y > 4 ) prospect[2] = 0;

}

