#include <bits/stdc++.h>
using namespace std;
 
void printDigits(int n){
    if(n == 0)
        return;
 
    else{
        printDigits(n / 10);
        cout << n % 10 << " ";
    }
}
 
int main(){
    
    int t;
    cin >> t;
 
    while (t --> 0)
    {
        int n;
        cin >> n;

        if(n == 0){
            cout << 0 << " ";
        }
 
        printDigits(n);
        cout << "\n";
    }
    
    return 0;
}