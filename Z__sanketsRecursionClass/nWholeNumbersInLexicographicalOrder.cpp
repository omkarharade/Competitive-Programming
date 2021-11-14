#include <bits/stdc++.h>
using namespace std;

void printNNumbersLexi(int n, int i){

    if(i > n){
        return;
    }

    if(i <= n){
        cout << i << "\n";
    }

    // if(i == 0){
    //     // cout << "ran for i = " << i<< endl;

    //     for (int j = 1; j <= 9; j++)
    //     {
    //         // cout << "ran for i = " << i<< " j = " << j<< endl;
    //         printNNumbersLexi(n, (10*i)+j);
    //     }

    // }
    // else{
    //     for (int j = 0; j <= 9; j++)
    //     {
    //         // cout << "ran for i = " << i<< " j = " << j<< endl;
    //         printNNumbersLexi(n, (10*i)+j);
    //     }
    // }

    // instead of making two for loops based on condition we can 
    // alternatively write the code as follows

    for (int j = (i == 0)? 1 : 0 ; j < 9; j++)
    {
        // cout << "ran for i = " << i<< " j = " << j<< endl;
        printNNumbersLexi(n, (10*i) + j);
    }
    
}

int main(){
    
    printNNumbersLexi(15, 0);
    return 0;
}