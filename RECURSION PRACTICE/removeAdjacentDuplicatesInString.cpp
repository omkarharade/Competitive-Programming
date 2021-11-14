#include <bits/stdc++.h>
using namespace std;

string removeAdjDup(string str){
    
    // base case

    if(str.length() == 1) return str;
    if(str.length() == 2 && str[0] == str[1]){
        return str = str.substr(0,1);
    }

    // recursive intution and self work
    if(str[0] == str[1]){
        str =  removeAdjDup(str.substr(1));
    }
    else str = str.substr(0,1) + removeAdjDup(str.substr(1));

    return str;
}

int main(){
    string str = "aabccdeef";
    cout << removeAdjDup(str) << endl;
    return 0;
}