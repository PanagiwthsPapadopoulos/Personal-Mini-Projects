/*#include<stdio.h>



int main(){

    char str[100];
    int index=0;


    printf("Enter text: \n");
    //gets(str);
    scanf("%s", str);


    while( str(index) != '\0' ){
        printf("%c", str[index]);
        index ++;

    }





    return 0;
}



*/

#include <stdio.h>
int main()
{
    char str[100];
        
    printf("\n Please Enter any String  :  ");
    scanf("%s", str);
        
    for(int i = 0; str[i] != '\0'; i++)
    {
        printf("The Character at %d Index Position = %c \n", i, str[i]);
    }
    return 0;
}