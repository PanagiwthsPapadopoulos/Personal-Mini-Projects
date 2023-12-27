#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int num, num11[10];
    int i=0;

    for(int k=0; k<10; k++){
        num11[k] = 0;
    }

    cout << "Enter a number: ";
    cin >> num;
    cout << endl << endl;
    
    while(num>0){        
        num11[i] = num%10;
        num = num/10;
        i++;
    }
    //for(int j=10; j>=0; j--){
    //    if(num11[j] == 0) i--;
    //}
    i--;

    if(i<1){
        cout << "The number must be a double digit number. Program terminated." << endl;
        exit(-1);
    }else{
        num = 0;
        num = num11[i];
        for(int j=1; j<i; j++){
            num = num + num11[j]*pow(10, j);
        }
        num = num + num11[0]*pow(10, i);

        cout << "The new number is " << num << ".";
    }

    return 0;
}