#include <iostream>

using namespace std;

class Athlete
{
   public:
        static int number;

   protected:
        string name;
        int age;
        string sport;
        string team;
        int skills;

    virtual void status() = 0;
};

class FootballPlayer : protected Athlete
{
public:
    FootballPlayer(){
        sport = "Football";
        number++;
    }
    FootballPlayer(string name, int age, string team, int skills){
        number++;
        sport = "Football";
        this->name = name;
        this->age = age;
        this->team = team;
        this->skills = skills;
    }
        void status(){
            cout << "Name:" << name << endl;
            cout << "Age:" << age << endl;
            cout << "Sport:" << sport << endl;
            cout << "Team:" << team << endl;
            cout << "Skills:" << skills << "/10" << endl;
        }
};

class FormulaDriver : protected Athlete
{
public:
    FormulaDriver(){
        sport = "Motor racing";
        number++;
    }
    FormulaDriver(string name, int age, string team, int skills){
        sport = "Motor racing";
        this->name = name;
        this->age = age;
        this->team = team;
        this->skills = skills;
        number++;
    }
    void status(){
       cout << "Name:" << name << endl;
       cout << "Age:" << age << endl;
       cout << "Sport:" << sport << endl;
       cout << "Team:" << team << endl;
       cout << "Skills:" << skills << "/10" << endl;
    }
    void overtake(FormulaDriver *driver1){
        cout << driver1->name << " was overtaken by " << this->name << ".\n";
    }
    void overtake(FormulaDriver driver1){
        cout << driver1.name << " was overtaken by " << this->name << ".\n";
    }
};

class BasketballPlayer : protected Athlete
{
public:
    BasketballPlayer(){
        sport = "Basketball";
        number++;
    }
    BasketballPlayer(string name, int age, string team, int skills){
    sport = "Basketball";
    this->name = name;
    this->age = age;
    this->team = team;
    this->skills = skills;
    number++;
    }
    void status(){
       cout << "Name:" << name << endl;
       cout << "Age:" << age << endl;
       cout << "Sport:" << sport << endl;
       cout << "Team:" << team << endl;
       cout << "Skills:" << skills << "/10" << endl;
    }

};

void createDynamicArray()
{
    //      FIRST METHOD: POINTER TO AN ARRAY OF OBJECTS
    FormulaDriver* racer = new FormulaDriver[2];
    racer[0] = FormulaDriver("Fernando Alonso", 60, "Alpine", 10);
    racer[1] = FormulaDriver("Lewis Hamilton", 45, "Mercedes AMG", 9);

    for(int i=0; i<2; i++){
        racer[i].status();
        cout << endl;
    }
    racer[0].overtake(racer[1]);
    delete [] racer;
}

void createDynamicArrayWithPointers()
{
    FormulaDriver **gp = new FormulaDriver*[2];
    gp[0] = new FormulaDriver("Fernando Alonso", 60, "Alpine", 10);
    gp[1] = new FormulaDriver("Lewis Hamilton", 45, "Mercedes AMG", 9);
    gp[0]->overtake(gp[1]);
    for(int i=0; i<2; i++){
        gp[i]->status();
        cout << endl;
    }
    for(int i=0; i<Athlete::number+1; i++) delete gp[i];
    delete [] gp;
}

int Athlete::number = 0;


int main(){

    cout << endl;
    createDynamicArrayWithPointers();
    
    cout << "Number of objects created: " << Athlete::number << endl;


    return 0;
}