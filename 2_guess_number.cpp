#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void playGame(int lower, int upper) {
    srand(time(0));
    int secretNumber = lower + rand() % (upper - lower + 1);
    int guess, attempts = 0;
    
    cout << "Guess the number between " << lower << " and " << upper << "!" << endl;
    
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;
        
        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
    } while (guess != secretNumber);
}

int main() {
    int difficulty;
    int lower = 1, upper;
    
    cout << "Select Difficulty Level:\n1. Easy (1-50)\n2. Medium (1-100)\n3. Hard (1-500)\nChoose: ";
    cin >> difficulty;
    
    switch (difficulty) {
        case 1: upper = 50; break;
        case 2: upper = 100; break;
        case 3: upper = 500; break;
        default: 
            cout << "Invalid choice, defaulting to Medium (1-100)." << endl;
            upper = 100;
    }
    
    playGame(lower, upper);
    return 0;
}
