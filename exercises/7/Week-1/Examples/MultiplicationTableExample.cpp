#include<iomanip>
#include <iostream>

using namespace std;

void printTableHeader() {
    cout << "   | ";
    for(int row = 0; row < 12; ++row) {
        cout << setfill(' ') << setw(4) << row + 1 << " |";
    }
    cout << endl << setfill('-') << setw(77) << "" << endl;
}

void printTableFooter() {
    cout << setfill('-') << setw(77) << "" << endl;
}

int main() {

    printTableHeader();
    for(int row = 0; row < 12; ++row) {
        cout << setfill(' ') << setw(2) << row + 1 << " | ";
        for(int column = 0; column < 12; ++column) {
            cout << setfill(' ') << setw(4) << (row + 1) * (column + 1) << " |";
        }

        cout << endl;   
    }
    printTableFooter();

    return 0;
}
