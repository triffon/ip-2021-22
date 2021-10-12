#include <iostream>
#include <string>

using namespace std;

const string BOB = "Bob";
const string ALICE = "Alice";

int main() {
    string name;

    cout << "Name: ";
    cin >> name; 

    if (BOB.compare(name) == 0 || ALICE.compare(name) == 0) {
        cout << "Hello there, " << name << "!"<< endl;
    }

    return 0;
}
