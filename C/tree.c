//Να γραφεί ένα πρόγραμμα το οποίο να προβάλλει στην οθόνη ένα
//χριστουγεννιάτικό δέντρο προς στόλισμα, όπως φαίνεται στο παράδειγμα.
//Το ύψος του δέντρου θα δίνεται από το χρήστη ως πλήθος γραμμών και θα
//πρέπει να είναι μεταξύ τεσσάρων και είκοσι. Παράδειγμα, για ύψος 6
//είναι,
#include <stdio.h>

int main(){
    
    int num;
    do{
        printf("Enter the height of the tree (natural number > 3): ");
        scanf("%d", &num);
    }while(num<3);
    
    for(int i=1; i<num; i++){       
        for(int j=0; j < ((2* (num-1) ) - 1 -(2*i-1))/2; j++){
            printf(" ");
        }
        for(int j=0; j < 2*i-1; j++){
            printf("*");
        }            
        printf("\n");
    }

    for(int j=0; j < num-2; j++){
        printf(" ");
    }
    printf("*\n");


    return 0;
}