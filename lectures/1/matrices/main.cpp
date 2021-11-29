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

    int columnSums[MAX] = { 0 };
    for(int j = 0; j < n; j++) // за всяка колона j
        for(int i = 0; i < m; i++) // за всеки елемент i в колоната j
            columnSums[j] += a[i][j]; 


    for(int j = 0; j < n; j++)
        cout << "Сумата на колона " << j << " е " << columnSums[j] << endl;

    int x;
    cout << "x = ";cin >> x;

    for(int i = 0; i < m; i++) {
        int j = 0;
        while (j < n && a[i][j] != x)
            j++;
        // j == n:         не сме намерили x и сме стиганали до края на реда
        // или
        // a[i][j] == x:   намерили сме x
        if (j < n)
            cout << x << " се среща на ред " << i << endl;
    }

    int j = 0, min;
    do {
        min = a[0][j];
        for(int i = 1; i < m; i++)
            if (a[i][j] < min)
                min = a[i][j];
        j++;
    } while (j < n && min % 2 != 0);
    // j == n, разгледали сме всички колони и нито една няма минимален четен елемент
    // или
    // min % 2 == 0, намерили сме колона с минимален четен елемент
    // възможно е И двете да са верни! (ако последната колона е с минимален четен елемент)

    if (min % 2 == 0)
        cout << "Има";
    else
        cout << "НЯМА";
    cout << " колона, чийто най-малък елемент е четно число" << endl;

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


}

int main(int, char**) {
    matrixExamples();    
}
