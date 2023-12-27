#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char vehi;
    float cost, volume;
    int days;

    printf("Please enter the type of vehicle(car{c}/motorcycle{m}), its volume and the days to rent for: \n");
    scanf("%c %f %d", &vehi, &volume, &days);
    printf("%c  %f  %d", vehi, volume, days);

    if( volume <= 0 ) {
        printf("INVALID INPUT. TERMINATING PROGRAM.\n");
        exit(0);
    }
    if( days <= 0 ) {
        printf("INVALID INPUT. TERMINATING PROGRAM.\n");
        exit(0);
    }
    

    switch(vehi){
        case('m'):  
            if(volume <= 100){
                if(days<=2) cost = (days*30);
                else if(days<=5) cost = (2*30) + ((days-2)*25);
                else if(days>5) cost = (2*30) + (3*25) + ((days-5)*20);
            }
            else{
                if(days<=2) cost = (days*40);
                else if(days<=5) cost = (2*40) + ((days-2)*35);
                else if(days>5) cost = (2*40) + (3*35) + ((days-5)*30);
            }
        break;
        case('c'): 
            if(volume <= 1000){
                if(days<=2) cost = (days*60);
                else if(days<=5) cost = (2*60) + ((days-2)*55);
                else if(days>5) cost = (2*60) + (3*55) + ((days-5)*50);
            }
            else{
                if(days<=2) cost = (days*80);
                else if(days<=5) cost = (2*80) + ((days-2)*70);
                else if(days>5) cost = (2*80) + (3*70) + ((days-5)*60);
            }
        break;
        default:
            printf("INVALID INPUT. TERMINATING PROGRAM.\n");
            exit(0);
        break;
    }

    
    printf("The cost for renting the selected vehicle is %.2f€.\n", cost);
    printf("Would you like to add an additional insurance to the selected vehicle? \nThe new total sums up to %.2f€. ", cost*.05 + cost);
    printf("y/n \n");



    return 0;
}