#include <bits/stdc++.h>
using namespace std;

#define endl   '\n'
#define omkarNum  1007

int main(){
    int n = 12;
    int m = 14;

    if(n % 2 == 0 and m % 2 == 0){
        cout << "both are even" << endl;
    }
    else if(n % 2 == 0 or m % 2 == 0){
        cout << "atleast one is odd" << endl;
        cout << omkarNum << "\n";
    }
    return 0;
}