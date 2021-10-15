/*
    Problem: Write a guessing game where the user has to guess a secret number. 
             After every guess the program tells the user whether their number
             was too large or too small. At the end the number of tries needed
             should be printed. It counts only as one try if they input the
             same number multiple times consecutively.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {   
    srand(time(0));

    int tries = 0;
    int guess = -1;
    int lastGuess = -1;
    int number = rand();
    
    while(guess != number) {
        cout << "Enter your guess: ";
        cin >> guess;

        tries += guess == lastGuess ? 0 : 1;

        if (guess > number) {
            cout << endl << "Your guess is too big. Try again..." << endl;
        } else if (guess < number) {
            cout << endl << "Your guess is too small. Try again..." << endl;
        } else {
            cout << endl << "You made it with " << tries << " attemps. Great job !" << endl;
        }
    }

    return 0; 
}