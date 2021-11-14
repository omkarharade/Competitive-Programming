#include <bits/stdc++.h>
using namespace std;

void printWithoutCons_1s(char str[], int i, int k){

    if(i == k){
        str[i] = '\0';
        cout << str << " ";
        return;
    }
    str[i] = '0';
    printWithoutCons_1s(str, i+1, k);

    if(str[i-1] == '1'){
        return;
    }
    else{
        str[i] = '1';
        printWithoutCons_1s(str, i+1, k);
    }
    
}

void initializations(int k){

    if(k <= 0)
        return;

    char str[k+1];

    str[0] = '0';
    printWithoutCons_1s(str, 1, k);

    str[0] = '1';
    printWithoutCons_1s(str, 1, k);
}

int main(){
    int k = 3;
    initializations(k);
    return 0;
}