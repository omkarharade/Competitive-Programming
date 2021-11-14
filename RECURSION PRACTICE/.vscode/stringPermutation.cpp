#include <bits/stdc++.h>
using namespace std;

void stringPermutation(string str, int l, int r){

    // base case
    if(l == r){
        cout << str << endl;
        return;
    }

    // self work & recursive intution
    for (int i = l; i <= r; i++)
    {
        swap(str[l], str[i]);
        stringPermutation(str, l+1, r);
        swap(str[l], str[i]);
    }
    
}

int main(){
    string str = "abc";
    stringPermutation(str, 0, str.length() -1);
    return 0;
}