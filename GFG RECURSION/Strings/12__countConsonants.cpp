#include <bits/stdc++.h>
using namespace std;

int countConsonants(string str, int i, int count){
    if(i > str.length())
        return 0;

    char ch = toupper(str[i]);
    
    if(ch == 'A'|| ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return 1 + countConsonants(str, i+1, count); 
    
    else return countConsonants(str, i+1, count);
}

int main(){
    string str = "Abcd YtIt";
    cout << countConsonants(str, 0, 0);
    return 0;
}