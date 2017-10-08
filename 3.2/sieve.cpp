#include <iostream>
#include <array>

template <class I>
void mark_sieve(I first, I last, int factor) {
    *first = false;
    while(last - first > factor) {
        first = first + factor;
        *first = false;
    }
}

template <class I>
void sift(I first, int n) {
    I last = first + n;
    std::fill(first, last, true);
    int i = 0;
    int index_square = 3;
    int factor = 3;
    while(index_square < n) {
        if(first[i]) {
            mark_sieve(first + index_square, last, factor);
        }
        ++i;
        index_square += factor;
        factor += 2;
        index_square += factor;
    }
}

int main() {
    const int Size = 100;
    std::array<bool, Size> ar;
    sift(ar.begin(), Size);
    for(int i = 0; i < Size; ++i) {
        std::cout << i << ":" << i + i + 3 << ":" << ar[i] << std::endl;
    }
}
