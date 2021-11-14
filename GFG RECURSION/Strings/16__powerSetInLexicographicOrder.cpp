#include <bits/stdc++.h>
using namespace std;

void powerSet(string str, int i, vector<string>& strArray, string currStr){

    if(i == str.length()){
        strArray.push_back(currStr);
        return;
    }

    powerSet(str, i+1, strArray, currStr);
    powerSet(str, i+1, strArray, currStr + str[i]);
}


int main(){
    string str = "abc";
    vector<string> strArray;

    powerSet(str, 0, strArray, "");

    sort(strArray.begin(), strArray.end());

    for(auto s : strArray){
        cout << s << " ";
    }
    return 0;
}