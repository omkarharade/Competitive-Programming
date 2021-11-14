#include <bits/stdc++.h>
using namespace std;

void printSubstring(string str, int n, int i, int j){

    if(i == n-1){
        cout << str[i] << "\n";
        return;
    }

    if(j > str.length()-1){
        return printSubstring(str, n, i+1, i+1);
    }

    else if(str[i] == str[j]){
        cout << str.substr(i,j+1-i) << "\n";
        
    }
    printSubstring(str, n, i, j+1); 
}

int main(){

    string str = "abcab"; 

    printSubstring(str, str.length(), 0, 0);
    
    
    return 0;
}