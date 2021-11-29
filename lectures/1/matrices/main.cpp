#include <iostream>
using namespace std;

void matrixExamples() {
    int m = 0, n = 0;
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;
    // !!! int a[m][n]; // !!!!!
    const int MAX = 100;
    int a[MAX][MAX] = {0};

    for(int i = 0; i < m; i++) // за всеки индекс i на ред
                               // въведи ред i
        for(int j = 0; j < n; j++) { // за реда i за всеки индекс на колона j
            cout << "Въведете a[" << i << "][" << j << "] = ";
            cin >> a[i][j];    // въведи елемента на индекс j в ред i
        }
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }
}

int main(int, char**) {
    matrixExamples();    
}
