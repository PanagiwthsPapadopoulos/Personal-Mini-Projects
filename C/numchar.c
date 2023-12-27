//Να γίνει πρόγραμμα το οποίο να δέχεται έναη ακέραιο Ν (N>0) 
//και έναν χαρακτήρα k (kε [a,z)) χωρισμένα με ένα λευκό χαρακτήρα. 
//Αν ο ακέραιος ή ο χαρακτήρας είναι εκτός ορίων το πρόγραμμα θα 
//εμφανίζει "Wrong Input" και θα τερματίζει.
//Το πρόγραμμα θα πρέπει να εμφανίζει στην οθόνη Ν φορές 
//τον χαρακτήρα k και στο τέλος μία τελεία. Μετά από κάθε 
//πεντάδα χαρακτήρων k το πρόγραμμα θα πρέπει να αφήνει 
//έναν κενό χαρακτήρα (space) εκτός και αν δεν ακολουθούν 
//άλλες εμφανίσεις του k οπότε και θα βάζει απλά τη τελεία.

#include <stdio.h>

int
main ()
{
  
  int num, flag = 1;
  char ch;
  char xara[] =
    { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'l', 'k', 'j', 'h',
    'g', 'f', 'd', 's', 'a', 'm', 'n', 'b', 'v', 'c', 'x', 'z'
  };
  do
    {
      printf ("Enter a natural number and a character NN5[a,z]: ");
      scanf ("%d %c", &num, &ch);
      if (num <= 0)
	printf ("WRONG INPUT\n");
      for (int i = 0; i < 26; i++)
	{
	  if (ch == xara[i])
	    flag = 0;
	}
      if (flag != 0)
	printf ("WRONG INPUT\n");
    }
  while (num <= 0 || flag == 1);

  flag = 0;

  for (int i = 0; i < num; i++)
    {
      printf ("%c", ch);
      flag++;
      if (flag == 5)
	{
	  if (i != num - 1)
	    {
	      printf (" ");
	      flag = 0;
	    }
	  else
	    printf (".");
	}
      else if (i == num - 1)
	printf (".\n");
    }


  return 0;
}
