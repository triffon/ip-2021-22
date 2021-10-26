#include <iostream>

using namespace std;

/**
 * Прочетете един символ от конзолата и изведете дали е главна буква,
 * малка буква, цифра или друг символ.
 */
int main()
{
    char ch;
    cin >> ch;

    // В ASCII таблицата буквите и цифрите са подредени [0; 9], [A; Z], [a; z].

    if ( ch >= 'A' && ch <= 'Z' )
    {
        cout << "Uppecase letter";
    }
    else if ( ch >= 'a' && ch <= 'z' )
    {
        cout << "Lowercase letter";
    }
    else if ( ch >= '0' && ch <= '9' )
    {
        cout << "Digit";
    }
    else
    {
        cout << "Other symbol";
    }

    return 0;
}
