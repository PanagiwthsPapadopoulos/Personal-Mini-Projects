#include <iostream>

using namespace std;

bool numtodigit(int num, int num00[10]){
    bool check = true;
    int i=0;

    while(i<10 && check == true){        
        num00[i] = num%10;
        num = num/10;
        if(num00[i] < 0 || num00[i] > 1){
            cout << "The number was not binary. Please try again." << endl;
            check = false;
        }
        i++;
    }
    return check;
}


int main(){

    int num1, num2, carry = 0, counter = 10;
    int num11[10], num22[10], result[11];

    for(int i=0; i<10; i++){
        num11[i] = 0;
        num22[i] = 0;
        result[i] = 0;
    }
    result[10] = 0;
    
    do{
        cout << "Enter the first binary number: ";
        cin >> num1;
    }while( !numtodigit(num1, num11) );   


    do{
        cout << "Enter the second binary number: ";
        cin >> num2;
    }while( !numtodigit(num2, num22) );     
    
    cout << "\n\n";

    for(int i=0; i<10; i++){
        
        result[i] = num11[i] + num22[i] + carry;
        
        if(result[i] == 2){
            result[i] = 0;
            carry = 1;
        }
        else if(result[i] == 3){
            result[i] = 1;
            carry = 1;
        }else carry = 0;

    }
    result[10] = carry;

    while(result[counter] == 0){
        counter--;
    }
    counter++;
    
    cout << "The sum of ";
    
    for(int i=counter; i>=0; i--){
        cout << num11[i];
    }
    cout << " and ";
    for(int i=counter; i>=0; i--){
        cout << num22[i];
    }
    cout << " is equal to ";
    for(int i=counter; i>=0; i--){
        cout << result[i];
    }
    cout << "\n\n";
    
    
    
    return 0;
}