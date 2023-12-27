#include <iostream>
#include <cmath>

using namespace std;

int main(){

    float num1, num2, res;
    char oper;
    bool isOper = true;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the operation: ";
    cin >> oper;
    cout << "Enter the second number: ";
    cin >> num2;
    if( (int)num2 == 0 && (oper == '/' || oper == '%') ) oper = '=';
    switch(oper){
        case '+': res = num1 + num2;
        break; 
        case '-': res = num1 - num2;
        break;
        case '*': res = num1 * num2;
        break;
        case '/': res = num1 / num2;
        break;
        case '%': res = (int)num1 % (int)num2;
        break;
        case '^': res = pow(num1, num2);
        break;
        default: cout << "Not a valid operand.";
                 isOper = false;
    }

    if(isOper) cout << "The operation was " << num1 << oper << num2 << " = " << res << endl;

    return 0;
}