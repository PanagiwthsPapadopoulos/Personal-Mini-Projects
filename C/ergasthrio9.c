#include <stdio.h>  
  struct student{
          int id[50];
          float grade[50];
          int age[50];
      }student1;
  
  void function(int structsize,int id){
    int counter;
    if(id != 0){ 
        for(int i=0; i<structsize; i++){
            if(id == student1.id[i]){
                printf("Grades average: %.1f\nAge: %d\n",student1.grade[i],student1.age[i]);
                return;
            }else counter ++;
        }
    }
    if (counter==structsize) printf("ID not found.");
  }
  
  int main(){
      int structsize, id;
    printf("Give the student number:\n");
     scanf("%d",&structsize);
  for(int i=0; i<structsize; i++){
      
     
    printf("Student No. %d\n",i+1);
    
    printf("Give the ID:\n");
    scanf("%d",&student1.id[i]);
    printf("Give the grades average:\n");
    scanf("%f",&student1.grade[i]);
    printf("Give the age:\n");
    scanf("%d",&student1.age[i]);
      
  }

    printf("Give the ID to search [0: exit]:\n");
    scanf("%d",&id);
    function(structsize,id);
 

return 0;
}