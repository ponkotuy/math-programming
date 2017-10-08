#include <iostream>
#include <cstdio>
#include "../common.hpp"

int fibonacci_quotient(int a, int b) {
    if(a < b) return 0;
    int c = b;
    int n = 1;
    int m = 1;
    do {
        int tmp = c;
        c += b;
        b = tmp;
        tmp = m;
        m += n;
        n = tmp;
    } while(c <= a);
    int o = 0;
    do {
        if(b <= a) {
            a -= b;
            o += n;
        }
        int tmp = c - b;
        c = b;
        b = tmp;
        tmp = n;
        n = m - n;
        m = tmp;
    } while(b < c);
    return o;
}

int fibonacci_reminder(int a, int b) {
    if(a < b) return 0;
    int c = b;
    do {
        int tmp = c;
        c += b;
        b = tmp;
    } while(c <= a);
    do {
        if(b < a) a -= b;
        int tmp = c - b;
        c = b;
        b = tmp;
    } while(b < c);
    return a;
}

int largest_doubling(int a, int b) {
    while(a - b >= b) {
        b += b;
    }
    return b;
}

int quotient(int a, int b) {
    if(a < b) return 0;
    int c = largest_doubling(a, b);
    a = a - c;
    int n = 1;
    while(c != b) {
        c = half(c);
        n += n;
        if(c <= a) {
            a = a - c;
            ++n;
        }
    }
    return n;
}

int reminder(int a, int b) {
    if(a < b) return a;
    int c = largest_doubling(a, b);
    a = a - c;
    while(c != b) {
        c = half(c);
        if(c < a) a = a - c;
    }
    return a;
}

int segment_reminder(int a, int b) {
    while(b < a) a = a - b;
    return a;
}

int fast_segment_reminder(int a, int b) {
    if(a < b) return a;
    if(a - b <= b) return a - b;
    a = fast_segment_reminder(a, b + b);
    if(a <= b) return a;
    return a - b;
}

int gcm(int a, int b) {
    while(a != b) {
        a = fast_segment_reminder(a, b);
        std::swap(a, b);
    }
    return a;
}

int main() {
    std::cout << gcm(48, 36) << "="
              << reminder(48, 36) << "="
              << fibonacci_reminder(48, 36) << std::endl;
    std::cout << gcm(1022, 2) << "="
              << reminder(1022, 2) << "="
              << fibonacci_reminder(1022, 2) << std::endl;
    std::cout << quotient(48, 36) << "="
              << fibonacci_quotient(48, 36) << std::endl;
    std::cout << quotient(48, 4) << "="
              << fibonacci_quotient(48, 4) << std::endl;
    return 0;
}
