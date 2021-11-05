#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    double answer = 0, product = 1;

    for (int i = 1; i <= n; i++) {
        product *= i;
        answer += 1 / product;
    }

    cout << fixed << setprecision(7) << answer << endl;

    return 0;
}
