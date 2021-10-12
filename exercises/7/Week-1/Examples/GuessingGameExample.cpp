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