#include <stdio.h>

//int N=0;
char characters[] = {'A', 'K', 'Q', 'J', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


int check(char c){
    for(int i=0; i<13; i++){
        if(c == characters[i]) return 1;
    }
    return 0;
}

void input(char a, int n, int card[13][4]){
   int i;
   
   if(a == 'A') i = 0;
   else if(a == 'K') i = 1;
   else if(a == 'Q') i = 2;
   else if(a == 'J') i = 3;
   else if(a == '9') i = 5;
   else if(a == '8') i = 6;
   else if(a == '7') i = 7;
   else if(a == '6') i = 8;
   else if(a == '5') i = 9;
   else if(a == '4') i = 10;
   else if(a == '3') i = 11;
   else if(a == '2') i = 12;
   else i = 4;

   card[i][n]++;
}


int main(){
    
    FILE *fptr;
    int card[13][4];
    char in;
    int total = 0, count = 0;
    printf("test");
    fptr = fopen("as.txt", "r");
    printf("test");
    for(int j=0; j<13; j++){
        for(int k=0; k<4; k++){
            card[j][k] = 0;
        }
    }
    printf("test");
    while((in = fgetc(fptr)) != EOF){
        if(in == ']'){
            fseek(fptr, 11, SEEK_CUR);
           // N++;
        }
        else if( check(in) ){
            char temp = in;
            fseek(fptr, 1, SEEK_CUR);
            if(in == '1') fseek(fptr, 1, SEEK_CUR);
            in = fgetc(fptr);
            input(temp, (int)in, card);
        }
    }
    fclose(fptr);


    do{
        for(int j=0; j<13; j++){
            for(int k=0; k<4; k++){
                if(card[j][k] >= 1) count++;
            }
        }

        if(count == 52){
            count = 0;
            total++;
            for(int j=0; j<13; j++){
                for(int k=0; k<4; k++){
                    card[j][k]--;
                }
            }
        }else in = '0';


    }while(in != '0');


    printf("%d, [", total);
    for(int i=0; i<13; i++){
        for(int k=0; k<4; k++){
            char a;
            if(i == 0) a = 'A';
            else if(i == 1) a = 'K';
            else if(i == 2) a = 'Q';
            else if(i == 3) a = 'J';
            else if(i == 5) a = '9';
            else if(i == 6) a = '8';
            else if( i == 7) a = '7';
            else if(i == 8) a = '6';
            else if(i == 9) a = '5';
            else if(i == 10) a = '4';
            else if(i == 11) a = '3';
            else if(i == 12) a = '2';
            //else if(i == 4) a = '10';
            if(card[i][k] > 0) printf("'%c-%d", a, k);
            if(card[i][k] > 0 && i == 4) printf("'%c-%d", 10, k);
            count--;
            if(count>0) printf("', ");
            else printf("']");
        }
    }

    return 0;
}