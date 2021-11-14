#include <bits/stdc++.h>
using namespace std;

void printStringOfLengthK(char set[], int n, string currStr, int k){

    if(k == 0){
        cout << currStr << "\n";
        return;
    }
    for (int i = 0; i < n ; i++)
    {
        
        printStringOfLengthK(set, n, currStr + set[i], k - 1);
        
    }
}

int main(){
    char set[100] = "ab";
    printStringOfLengthK(set, 2, "", 3);
    return 0;
}