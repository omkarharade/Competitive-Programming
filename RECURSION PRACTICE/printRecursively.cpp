#include <bits/stdc++.h>
using namespace std;

void printRecursive(string s){

    if(s.size() == 0)
        return;
    
    printRecursive(s.substr(1));
    cout << s[0];

}

int main(){
    string s = "stringTringTring";
    printRecursive(s);
    return 0;
}