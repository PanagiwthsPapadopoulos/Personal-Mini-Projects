#include<stdio.h>
#include<string.h>
#define MAX_SIZE 30


int main(){

    char name[MAX_SIZE];
    int num, check=1;

    printf("Input: ");
    fgets(name, MAX_SIZE, stdin);
    name[strcspn(name, "\n")]='\0';
    num=strcspn(name, "\0");
    for(int i=0; i<num; i++){
        if(name[i]!=name[num-1-i]) check = 0;
    }
    if(check==1) puts("Palindrome.");
    else puts("Not a Palindrome.");

    return 0;
}