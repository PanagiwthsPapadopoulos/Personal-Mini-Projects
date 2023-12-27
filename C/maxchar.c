#include <stdio.h>

int main(){

    char ch[100];
    int i=0, num[255], max;
    
    for(int k=0; k<255; k++){
        num[k]=0;
        //printf("%d", num[k]);
    }
    
    scanf("%s", ch);
    
    while(ch[i] != '\0'){
        ++num[(int)(ch[i])];
        i++;
    }
    
    for(int i=0; i<255; i++){
        if(num[i]>max) max=i;
    }

    printf("The most frequently used character is '%c' with a frequency of %d", max, num[max]);
    
    
    
    return 0;
}