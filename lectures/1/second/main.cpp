#include <iostream>
using namespace std;
int main() {
  int a, b;
  cout << "a = " << a << endl;
  // първо въвеждаме стойности
  cout << "a = "; cin >> a;
  cout << "b = "; cin >> b;

  // събираме числата
  int c = a + b;
  const int d = a + b;
  // d = 2 * a + b;

  // cout << a << b << c;


  // извеждаме резултата
  cout << "a + b = " << c << endl;
  return 0;
}
