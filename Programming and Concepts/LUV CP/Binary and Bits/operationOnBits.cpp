#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

void printBinary(int num) {
    for (int i = 10; i >= 0; --i) {
        cout << ((num >> i) & 1);
    }
    cout << nline;
}

int main() {

    printBinary(9);
    int a = 9;
    int i = 0;




    // [......checks if ith bit is set or not.......]

    if ((a & (1 << i)) != 0) {
        cout << "bit is set" << nline;
    }
    else {
        cout << "bit is not set" << nline;
    }




    // [...........set ith bit...........]

    i = 1;
    printBinary( a | (1 << i));



    // [..............unset jth bit............]

    int j = 3;
    printBinary(~(1 << j));
    printBinary(a & (~(1 << j)));




    // [..........toggle kth bit...............]
    int k = 2;
    printBinary( a ^ (1 << k) );




    // [.............count set bits..............]

    int ct = 0;
    for ( i = 31; i >= 0; i--) {

        if ((a & (1 << i)) != 0) {
            ct++;
        }
    }

    cout << ct << nline;




    // [.......builtin setbit counter..........]

    cout << __builtin_popcount(a) << nline;


    return 0;
}