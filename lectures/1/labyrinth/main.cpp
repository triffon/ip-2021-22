#include <iostream>
using namespace std;

const unsigned MAX = 10;


bool findTreasure(char labyrinth[][MAX], unsigned n, int x, int y) {
    cout << "Пробваме да стъпим на (" << x << ',' << y << ")" << endl;
    // ако съм излязъл извън границите
    // или
    // ако има стена
    // или
    // ако тук съм стъпвал вече
    if (x == n || y == n || x < 0 || y < 0 || labyrinth[x][y] == '*' || labyrinth[x][y] == '.') {
        // провал!
        cout << "Не може!" << endl;
        return false;
    }
    if (labyrinth[x][y] == '$') {
        // успех!
        cout << "Съкровище!" << endl;
        return true;
    }
    // маркирам, че съм стъпил на [x][y]
    labyrinth[x][y] = '.';
    // стъпка на север
    if (findTreasure(labyrinth, n, x - 1, y   ))
        return true;
    // стъпка на юг
    if (findTreasure(labyrinth, n, x + 1, y   ))
        return true;
    // стъпка на изток
    if (findTreasure(labyrinth, n, x    , y + 1))
        return true;
    // стъпка на запад
    if (findTreasure(labyrinth, n, x    , y - 1))
        return true;
    // връщане назад
    cout << "Връщаме се назад от (" << x << ',' << y << ")" << endl;
    return false;
}

void testLabyrinth() {
    char labyrinth[MAX][MAX] = 
        { 
            "* ** ",
            "     ",
            " ***$",
            "    *",
            "  ** "
        };
    int startx = 4, starty = 1;
    if (findTreasure(labyrinth, 5, startx, starty))
        cout << "Намерихме съкровището!" << endl;
    else
        cout << "Не успяхме да намерим съкровището..." << endl;
}

int main(int, char**) {
    testLabyrinth();
}
