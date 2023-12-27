///Να γίνει πρόγραμμα το οποίο θα διαβάζει από το χρήστη ένα μη 
//αρνητικό ακέραιο και θα ελέγχει αν ο αριθμός αυτός είναι 
//αριθμός Kaprekar με βάση το 10. Ένας αριθμός λέγεται Kaprekar 
//με βάση το 10 αν η αναπαράσταση του τετραγώνου του αριθμού μπορεί
// να χωριστεί σε δύο τμήματα Α και Β τέτοια ώστε να αθροίζουν 
//στον αρχικό αριθμό. Κάθε τμήμα μπορεί να περιλαμβάνει μηδενικά
// πριν τον αριθμό, αλλά ενώ το τμήμα Α μπορεί να είναι Ο το Β πρέπει πάντα να είναι >0.
////Παραδείγματα
//O αριθμός 9 είναι Kaprekar γιατί 9^2 = 81 και το 81 μπορεί να χωριστεί σε A = 8 και Β =1, όπου A+B = 9
//Ο αριθμός 297 είναι Kaprekar γιατί 297^2 = 88209 και το 88209 μπορεί 
//να χωριστεί σε Α = 88 και Β =209, όπου A+B = 297
//Αντίθετα ο αριθμός 81 δεν είναι Kaprekar γιατί 81^2 = 6561 
//και με όποιο τρόπο και να χωριστεί το 6561 τα δύο μέρη δεν αθροίζουν στο 81:
//Ο + 6561 = 6561 (!= 81)    
//6 + 561 = 567 (!= 81)      
//65 + 61 = 126 (!= 81)       
//656 + 1 = 657 (!= 81).
#include <stdio.h>
#include <math.h>

int
main ()
{
    int num, numsq, remainder=0, i=0;

    do
    {
      printf ("Enter a natural number: ");
      scanf ("%d", &num);
      if (num <= 0)
	printf ("WRONG INPUT\n");
    }
    while (num <= 0);

    numsq = num*num;

    if(num==numsq) printf("The number %d is a Kaprekar number.\n", num);
    else while (numsq != 0)
	{
	  remainder = pow(10, i)*(numsq % 10) + remainder;
	  numsq = numsq / 10;
      i++;
      if( (remainder+numsq) == num ){
        printf("The number %d is a Kaprekar number.\n", num);
        i = -999999;
      }

	}
    
    if(i>0) printf("The number %d is NOT a Kaprekar number.\n", num);

    return 0;
}
