#include<stdio.h>
#include<string.h>
#define MAX_SIZE 30


int main(){

    int i=0;
    char name[5][MAX_SIZE];

    while(i<5){
        printf("Enter name No.%d: ", i+1);
        fgets(name[i], MAX_SIZE, stdin);
        name[i][strcspn(name[i], "\n")]='\0';
        for(int j=0; j<i; j++){
            if(strcmp(name[i], name[j]) == 0){
                printf("Duplicate names not allowed. \n");
                i--;
            }
        }
        i++;
    }

    return 0;
}