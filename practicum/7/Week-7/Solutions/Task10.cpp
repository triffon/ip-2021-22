#include<iostream>

//task 10
unsigned on_bits_cnt(unsigned n) {
    unsigned cnt = 0;

    while (n) {
        if (n % 2)
            ++cnt;
        n /= 2;
    }

    return cnt;
}

unsigned off_bits_cnt(unsigned n) {
    unsigned cnt = 0;

    while (n) {
        if (!(n % 2))
            ++cnt;
        n /= 2;
    }

    return cnt;
}

unsigned max_on_bits(unsigned a, unsigned b) {
    return on_bits_cnt(a) > on_bits_cnt(b) ? a : b;
}

unsigned max_off_bits(unsigned a, unsigned b) {
    return off_bits_cnt(a) > off_bits_cnt(b) ? a : b;
}

int main() {

    unsigned a = 11, b = 4;

    std::cout << "More on bits in " << max_on_bits(a, b) << "\n";
    std::cout << "More off bits in " << max_off_bits(a, b) << "\n";

	return 0;
}