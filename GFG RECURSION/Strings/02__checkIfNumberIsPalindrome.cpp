#include <bits/stdc++.h>
using namespace std;

bool ifNumberIsPalindrome(string str, int i, int j){

    if(i >= j)
        return true;

    if(str[i] == str[j]){
        return ifNumberIsPalindrome(str, i+1, j-1);
    }
    return false;
}

int main(){
    string str;
    cin >> str;
    if(ifNumberIsPalindrome(str, 0, str.length()-1))
        cout << "true";
    else cout << "false";
    return 0;
}