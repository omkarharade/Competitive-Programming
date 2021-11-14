#include <bits/stdc++.h>
using namespace std;

int cutRope(int n, int a, int b, int c){

    // base case
    if(n == 0)
        return 0;
    if(n < 0)
        return -1;

    //recursive intution
     int maxValue =  max(cutRope(n-a, a, b, c),
                        max(cutRope(n-b, a, b, c),cutRope(n-c, a, b, c))
                    );
    
    // self work
    if(maxValue == -1)
        return -1;
    else return maxValue + 1;
}

int main(){
    int n, a, b, c;

    n = 9; a = 2; b = 2, c = 2;

    cout << cutRope(n, a, b, c);
    return 0;
}