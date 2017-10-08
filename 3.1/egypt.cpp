#include <iostream>
#include "../common.hpp"

int egypt(int n, int a) {
    if(n == 1) return a;
    return egypt(half(n), a + a) + (odd(n) ? a : 0);
}

int main() {
    std::cout << egypt(32, 4) << std::endl;
}
