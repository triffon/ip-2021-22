#include <iostream>

int chocolateFeast(int n, int c, int m) {
    int wrapper = 0;
    wrapper = n / c; //max choc wrapper boby can get with his money
    int chocCount = wrapper; //=> 1 choc gives 1 wrapper
    while (wrapper >= m)    // while bobby has enough wrappers to buy a choc (price is m)
    {
        wrapper = wrapper - m;//exchange wrapper for choc
        wrapper++;//new choc means new wrapper
        chocCount++;//increase choc count
    }
    return chocCount;
}

int main() {

}