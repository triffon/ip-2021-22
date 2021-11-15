#include <iostream>
using namespace std;

void arrayExamples() {
    int a[10] = {1, 2, 3, 4};
    int b[10] = {1, 2, 3, 4};
    cout << a[1] << endl;
    // !!! cout << a[1000000] << endl;
    // !!! a = b;
    cout << (a == b) << endl;
    cout << (a == a) << endl;
    // !!! cin >> a;
    cout << a << endl;
}

int main() {
    const int N = 100;
    int a[N];
    int n;
    do {
        cout << "Въведете брой на елементите: ";
        cin >> n;
    } while (n <= 0 || n > N);
    for(int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
        cout << "a[" << i << "] = " << a[i] << endl;

    int sum = 0;

    for(int i = 0; i < n; i++)
        sum += a[i];

    cout << "Сумата на елементите е: " << sum << endl;

    cout << "Въведете число за търсене: ";
    int x;
    cin >> x;

    /* for е по-подходящ за задачи за всяко
    for(int i = 0; i < n; i++)
        if (a[i] == x)
            cout << "Числото " << x << " се среща в масива";
    */

    // цикъл за търсене
    int i = 0;
    // n == N, x не се среща в масива, тогава i == n, a[100]!!!
    while(i < n && a[i] != x)
        // инвариант: x не е равно на нито едно от a[0], a[1], ..., a[i]
        i++;
    // добър вариант (да): a[i] == x 
    // лош вариант   (не): i >= n
    cout << "Числото " << x;
    if (i == n)
        cout << " НЕ";
    cout << " се среща в масива" << endl;

    // magic
    i = 0;
    while (i < n - 1 && a[i] <= a[i+1])
        i++;
    // добър вариант (да): i == n - 1    (няма нарушение)
    // лош   вариант (не): a[i] > a[i+1] (има нарушение)
    cout << "Редицата от елементите ";
    if (i < n - 1)
        cout << "НЕ ";
    cout << "е монотонно растяща" << endl;
    return 0;
}