#include <bits/stdc++.h>
using namespace std;

void stringPowerSet(string str, int i, string curr){

    // best case
    if(i == str.length()){
        cout << curr << endl;
        return;
    }

    // self work & recursive intution
    stringPowerSet(str, i+1, curr + str[i]);
    stringPowerSet(str, i+1, curr);

}

int main(){
    stringPowerSet("abc", 0, "");
    return 0;
}