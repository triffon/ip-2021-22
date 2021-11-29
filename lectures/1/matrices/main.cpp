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
    
    for(int i = 0; i < m; i++) {      // за всеки ред i,
        for(int j = 0; j < n; j++)    // изведи ред i, т.е. за всеки елемент j от него
            cout << a[i][j] << '\t';  // го изведи
        cout << endl;                 // и накрая сложи нов ред
    }

    /* Транспонирано извеждане, т.е. по колони вместо по редове */
    /*
    for(int j = 0; j < n; j++) {     // за всяка колона j
        for(int i = 0; i < m; i++)   // изведи колона j на един ред на екрана, т.е. за всеки ред i
            cout << a[i][j] << '\t'; // изведи елемента на ред i и колона j
        cout << endl;                // и накрая сложи нов ред
    }
    */

   // транспониране в нова матрица
   /*
   int b[MAX][MAX];
   for(int j = 0; j < n; j++)   
        for(int i = 0; i < m; i++)
            b[j][i] = a[i][j];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << b[i][j] << '\t';
        cout << endl;
    }
    */

   // транспониране на място по колони
   /*
   for(int j = 1; j < n; j++)   
        for(int i = 0; i < j; i++) {
            // a[j][i] = a[i][j]; // губим елементи!!!
            int tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    */

   // транспониране на място по редове
   for(int i = 0; i < m; i++)   
        for(int j = i + 1; j < n; j++) {
            // a[j][i] = a[i][j]; // губим елементи!!!
            int tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << a[i][j] << '\t';
        cout << endl;
    }

    int columnSums[MAX] = { 0 };
    

}

int main(int, char**) {
    matrixExamples();    
}
