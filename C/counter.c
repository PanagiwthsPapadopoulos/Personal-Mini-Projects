#include <stdio.h>
#include <unistd.h>

int main()
{
    int icounter;
    printf("enter icounter: ");
    scanf("%d", &icounter);

    while(icounter != -1)
    {
        printf("\n\n\t%d", icounter);
        icounter--;
        sleep(1);

    }

 
    return 0;
}