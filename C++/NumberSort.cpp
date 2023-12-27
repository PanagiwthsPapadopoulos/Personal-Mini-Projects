#include <iostream>

using namespace std;

void ascending(float numbers[20], int counter){
    float temp;
    
    for(int i=0; i<counter; i++){
        for(int j=0; j<counter; j++){
            if(numbers[i] < numbers[j]){
                temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = temp;
            }
        }
    }

}

void descending(float numbers[20], int counter){
    float temp;
    
    for(int i=0; i<counter; i++){
        for(int j=0; j<counter; j++){
            if(numbers[i] > numbers[j]){
                temp = numbers[j];
                numbers[j] = numbers[i];
                numbers[i] = temp;
            }
        }
    }

}


int main(){
    
    int counter = 0;
    float buffer;
    float numbers[20] = { 0 };
    string input;
    bool check = false;
    
    cout << "Enter a stream of numbers: ";

    do{
       cin >> buffer;
       numbers[counter] = buffer;
       counter++;
    }while (buffer != 9999);
    
    cout << "Input was stored\n. Select the order of the numbers:(ascending/descending): ";
    
    do{
        cin >> ws;
        getline(cin, input);
        if(input == "ascending"){
            ascending(numbers, counter-1);
            check = true;
        }
        else if(input == "descending"){
            descending(numbers, counter-1);
            check = true;
        }
        else cout << "Incorrect input. Please try again." << endl;

    }while(!check);

    for(int i=0; i<counter-1; i++){
        cout << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}