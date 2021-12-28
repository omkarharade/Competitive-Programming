#include <bits/stdc++.h>
using namespace std;

void permutation_backtrack(char str[], int i, int n, vector<char>& osf){
    
    if(i == n){
        for(auto op : osf){
            cout << op << " ";
        }
        cout << "\n";
        return;
    }
    

    osf.push_back(str[i]);
    permutation_backtrack(str, i+1, n, osf);
    osf.pop_back();
    permutation_backtrack(str, i+1, n, osf );

}

int main(){
    char str[] = "abc";
    vector<char> osf;
    permutation_backtrack(str, 0, 3, osf);
    return 0;
}