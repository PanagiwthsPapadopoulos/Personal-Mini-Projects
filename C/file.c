#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *ptr;
    char c;

    ptr = fopen("/Users/panagiwths/Desktop/textfile.txt","w");

    c = getchar();
    while(c != EOF)
    {
    fprintf(ptr,"%c",c);
    c = getchar();


    if(c == 'q') break;


    }

    fclose(ptr);
return 0;
}