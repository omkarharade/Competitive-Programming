#include <bits/stdc++.h>
using namespace std;

bool palindromeChk(string str, int i, int j){
    //base case
    if(i >= j)
        return true;

    // self work and recursive intution

    if(str[i] == str[j] && palindromeChk(str, i+1, j-1))
        return true;
    
    return false;
}

int main(){
    
    string str = "racecar";
    cout << palindromeChk(str, 0, str.length()-1) << endl;
    return 0;
}