#include <stdio.h>

// Να γραφεί ένα πρόγραμμα που να υπολογίζει το ακέραιο πηλίκο και το
//υπόλοιπο μιας διαίρεσης ενός πραγματικού διαιρετέου με έναν ακέραιο
//διαιρέτη.

int main(){

    float D, y;
    int d, p;

    D=100;
    d=7;




    p = D/d;
    y = D - p*d;



printf("Phliko: %d     ypoloipo: %.2f", p, y);

return 0;

}