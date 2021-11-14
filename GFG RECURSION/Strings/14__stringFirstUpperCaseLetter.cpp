#include <bits/stdc++.h>
using namespace std;

char firstUpperCase(string str, int i){
    if(i > str.length())
        return 0;
    
    if(isupper(str[i]))
        return str[i];
    else{
        return firstUpperCase(str,i+1);
    }
}

int main(){
    
    string str = "geeksfoRgeeks";
    char res = firstUpperCase(str, 0);

    if(res == 0)
        cout << "No uppercase letter";
    
    else cout << res << "\n";
    return 0;
}