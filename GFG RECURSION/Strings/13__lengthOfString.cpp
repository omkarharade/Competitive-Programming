#include <bits/stdc++.h>
using namespace std;

int stringLength(string str, int i){

    if(str[i] == '\0')
        return 0;
    
    return 1+ stringLength(str,i+1);
}

int main(){
    string str = "abcde fghij";
    cout << stringLength(str, 0);
    return 0;
}