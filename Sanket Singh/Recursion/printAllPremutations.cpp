#include <bits/stdc++.h>
using namespace std;

void permutationsSwapMethod(string str, int sIndex, int n){

    if(sIndex == n-1){
        cout << str <<"\n";
        return;
    }

    for (int i = sIndex; i < n; i++)
    {
        swap(str[sIndex], str[i]);
        permutationsSwapMethod(str, sIndex +1,  n);
    }

}

// this function can handle duplicates
void permutationAppendMethod(string str, int n, string osf){

    if(n == 0){
        cout << osf << "\n";
        return;
    }
    // set for handling duplicate characters in string
    unordered_set<char> s;

    for (int i = 0; i < n; i++){
        char ch = str[i];

        if(s.count(ch) == 0){
            s.insert(ch);
            permutationAppendMethod(str.substr(0,i)+str.substr(i+1), n-1, osf + str[i]);
        }
    }
    
}

int main(){
    string str = "acc";
    int n = str.length();
    // both of the below method works properly
    // permutationsSwapMethod(str, 0, n);
    permutationAppendMethod(str, n, "");
    return 0;
}