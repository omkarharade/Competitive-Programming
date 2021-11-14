#include <bits/stdc++.h>
using namespace std;

void copyString(char str1[], char str2[], int index){

    str2[index] = str1[index];

    if(str1[index] == '\0')
        return;
    
    // cout << str1[index] << " " << str2[index] << "\n";
    copyString(str1, str2, ++index);
}

int main(){
    
    char str1[100] = "omkar";
    char str2[100] = "";

    copyString(str1, str2, 0);

    int i = 0;
    cout << str2;

    return 0;
}