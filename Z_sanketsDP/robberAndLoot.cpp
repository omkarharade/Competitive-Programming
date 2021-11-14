#include <bits/stdc++.h>
using namespace std;

int maxlootTD(int i, vector<int>& dp, int arr[]){

    // alternate base cases
    // if(i < 0) return 0;

    if(i == 0) return dp[i] = arr[i];

    if(i == 1){
        return dp[i] = max(arr[0], arr[1]);
    }

    if(dp[i] != -1) return dp[i];

    dp[i] = max((maxlootTD(i-2, dp, arr) + arr[i]), maxlootTD(i-1, dp, arr));

    return dp[i];

}

int maxlootBU(int arr[], int n){
    vector<int> dp(n, -1);

    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
    }
    return dp[n-1];
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    vector<int> dp(n, -1);
    cout << maxlootTD(n-1, dp, arr) << endl;
    cout << maxlootBU(arr, n) << endl;


    return 0;
}