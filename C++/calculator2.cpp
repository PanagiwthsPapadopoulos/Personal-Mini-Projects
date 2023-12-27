#include <iostream>

using namespace std;

class Calculator{
    public: template <typename X> X addition(X num1, X num2) {return (num1+num2);}
    public: template <typename X> X subtraction(X num1, X num2) {return (num1-num2);}
    public: template <typename X> X multiplication(X num1, X num2) {return (num1*num2);}
    public: template <typename X> X division(X num1, X num2) {if(num2!=0)return (num1/num2); else return 99999;}
};


int main(){

 Calculator calc;
 cout << endl;

 cout << "Addition is: " << calc.addition(10, 20) << endl;
 cout << "Subtraction is: " << calc.subtraction(10, 20) << endl;
 cout << "Multiplication is: " << calc.multiplication(10.0, 20.0) << endl;
 cout << "Division is: " << calc.division(10.0, 20.0) << endl;



    cout << endl;
    return 0;
}