#include <bits/stdc++.h>
using namespace std;

// recursive code
int fib(int n){

    if(n == 0 || n == 1) return n;

    return fib(n-1) + fib(n-2);
}

int fibTD(int n, vector<int>&dp){

    if(n == 0 || n == 1) return n;
    if(dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = fibTD(n-1, dp) + fibTD(n-2, dp);

}
int fibBU(int n){

    if(n == 0 || n == 1) return n;
    vector<long long> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <=n ; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << fibTD(n, dp) << "\n";
    cout << fibBU(n) << "\n";
    return 0;
}