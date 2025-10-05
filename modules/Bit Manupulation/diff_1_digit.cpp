#include <math.h>

#include <iostream>
#include <vector>
using namespace std;

void print_bits(int no) {
    while (no) {
        cout << no % 2;
        no = no >> 1;
    }
    cout << endl;
    return;
}

int rightmost_bit(int no) {
    return log2(no & -no);
}

int leftmost_bit(int no) {
    return log2(no);
}

int main() {
    int number  = 608;
    int number2 = 108;
    print_bits(number);
    print_bits(number2);

    print_bits(abs(number - number2));

    int ans = number ^ number2;
    print_bits(ans);
    int and_bit = number & number2;
    print_bits(and_bit);

    cout << ans << ' ' << and_bit << endl;
    return 0;
}
