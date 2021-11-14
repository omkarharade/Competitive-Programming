#include <bits/stdc++.h>
using namespace std;

void printPattern(int n){
    // base case
    if(n == 0) return;

    else{
        cout << "* "; 
        printPattern(n-1);
        cout << "\n";

        printPattern(n+n-1);
    }
    
}

int main(){
    printPattern(5);
    return 0;
}