#include <iostream>

using namespace std;


int factorial(int num){
    int res = 0;
    
    if(num == 0) return 1;
    else{
        res = 1;
        while(num>1){
            res = res*num;
            num--;
        }
    }
    return res;
}

int main(){

    double number=9.3;
    bool check=false;
    int res;

    do{
        
        cout << "\n\nEnter a number: ";
        cin >> number;
        if( (number > 0) && ((number - (int)number) == 0) ) check = true;   

    }while(check == false);

    res = factorial( (int)number );

    if(res == 0){
        cout << "There was an error." << "\n\n";
    }else cout << "The factorial of the number is: " << res << "\n\n";

    return 0;
}