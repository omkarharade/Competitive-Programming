#include <bits/stdc++.h>
using namespace std;

void diceAndWays(int n, int remDist, string stepsSF){

    if(remDist == 0){ 
        cout << stepsSF << "\n";
        return;
    }

    if(remDist < 0){
        return;
    }

    for (int i = 1; i <=6 ; i++)
    {
        diceAndWays(n, remDist-i, stepsSF + to_string(i) +"->");
    }
    
}

//sanket's function for this problem
void dicePath(int n, int i, string osf){

    if(i >= n) return;

    if(i == n-1){
        cout << osf << "\n";
        return;
    }

    for (int j = 1; j <= 6 ; j++)    {
        dicePath(n, i+j, osf + to_string(j) + "->" );
    }
    
}

int main(){
    int n = 6;

    diceAndWays(n, n-1, "");
    // dicePath(n, 0, "");
    return 0;
}