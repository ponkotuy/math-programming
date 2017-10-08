#include <iostream>
#include "../common.hpp"

int mult_acc1(int r, int n, int a) {
    while(true) {
        if(odd(n)) {
            r = r + a;
            if(n == 1) return r;
        }
        n = half(n);
        a = a + a;
    }
}

int multiply4(int n, int a) {
    while(!odd(n)) {
        n = half(n);
        a = a + a;
    }
    if(n == 1) return a;
    return mult_acc1(a, half(n - 1), a + a);
}

int main() {
    std::cout << multiply4(20, 7) << std::endl;
}
