#include <iostream>

using namespace std;

void outoflives(){
    cout << "You have 0 lives left. You lose!\n";
}

void won(){
    cout << "Congratulations, you cracked the password. You may enter. \n";
}

int main(){

    string password = "my password";
    string guess;
    int lives = 3;
    bool crack = false;

    cout << "Try to guess the password. ";

    while(!crack && lives>0){
        cout << "You have " << lives << " lives remaining.\n";
        cout << "Enter your guess: ";
        getline(cin, guess); 
        if(guess == password) crack = true;
        else lives--;
    }

    if(lives == 0) outoflives();
    else won();

    return 0;
}