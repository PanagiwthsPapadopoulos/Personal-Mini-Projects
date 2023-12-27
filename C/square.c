//Να γίνει πρόγραμμα το οποίο θα σχηματίζει τετράγωνα στην οθόνη χρησιμοποιώντας το χαρακτήρα * και κενά. Το πρόγραμμα θα διαβάζει από το χρήστη 2 ακέραιους: τη πλευρά του τετραγώνου Ν (ακέραιος αριθμός στο διάστημα [2,13]) και το πάχος των τοιχωμάτων του τετραγώνου w (ακέραιος αριθμός 21).
//Το πρόγραμμα θα ελέγχει αρχικά αν οι τιμές των Ν και w είναι εντός των επιτρεπτών ορίων και αν μπορεί να σχηματιστεί τετράγωνο με τις δεδομένες τιμές των N και W. Π.χ. αν το Ν είναι 6 και το w είναι και τότε δεν μπορεί να σχηματιστεί τετράγωνο καθώς η πλευρά θα έβγαινε 8 (4+4) που είναι μεγαλύτερο από τη συνολική πλευρά του τετραγώνου (6). Αν οι τιμές είναι εκτός ορίων ή δεν μπορεί να σχηματιστεί τετράγωνο το πρόγραμμα θα πρέπει να εμφανίζει το μήνυμα "Wrong Input" και να τερματίζει.
//Διαφορετικά θα πρέπει να σχηματίζεται το συγκεκριμένο τετράγωνο.

#include <stdio.h>

int
main ()
{
    int pleyra, paxos;

    do{
        printf("Enter the height and thickness of the square: ");
        scanf("%d%d", &pleyra, &paxos);
    } while(pleyra<2 || paxos<1 || paxos>(pleyra/2));

    for(int i=1;i<=pleyra;i++){
        if(i<=paxos || i>pleyra-paxos){
            for(int j=1;j<=pleyra;j++){
                printf("*");
            }
        }
        else{
            for(int j=1; j<=pleyra; j++){
                if(j<=paxos || j>pleyra-paxos) printf("*");
                else printf(" ");
            }
        }
        printf("\n");
    }

return 0;
}


