#include <bits/stdc++.h>
using namespace std;

int atoi(string str, int n){

    if(n == 0){
        return 0;
    }
    else{

        return atoi(str, n-1) * 10 + str[n-1] - '0';
    }
}

int main(){
    string str = "123456789";
    cout << atoi(str, str.length());
    return 0;
}