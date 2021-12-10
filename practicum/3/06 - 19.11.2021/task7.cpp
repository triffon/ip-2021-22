#include <iostream>

int main() {
    int arr[1024];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int startInd = 0;
    int maxLen = 1;
    int maxStart = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            if (maxLen < i - startInd) {
                maxLen = i - startInd;
                maxStart = startInd;
            }
            startInd = i;
        }
    }
    if (maxLen < n - startInd) {
        maxLen = n - startInd;
        maxStart = startInd;
    }

    for (int i = maxStart; i < maxStart + maxLen; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
