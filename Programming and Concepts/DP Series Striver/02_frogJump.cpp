#include <bits/stdc++.h>

// Problem link : https://bit.ly/3JPcoOx


const int N = 1e5 + 10;
const int INF = 1e9 + 100;
vector<int> dp(N, -1);

void init(int n) {
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
    }
}

int ways(int i, int n, vector<int> &heights) {

    if (i < 0) return INF;
    if (i == 0) return 0;
    int way1 = INF, way2 = INF;
    if (i - 1 >= 0) way1 = abs(heights[i] - heights[i - 1]) + ways(i - 1, n, heights);
    if (i - 2 >= 0) way2 = abs(heights[i] - heights[i - 2]) + ways(i - 2, n, heights);
    int minWay = min(way1, way2);
    if (minWay >= INF) return INF;
    else return minWay;
}

// top down
int waysTD(int i, int n, vector<int> &heights) {

    if (i < 0) return INF;
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];
    int way1 = INF, way2 = INF;
    if (i - 1 >= 0) way1 = abs(heights[i] - heights[i - 1]) + ways(i - 1, n, heights);
    if (i - 2 >= 0) way2 = abs(heights[i] - heights[i - 2]) + ways(i - 2, n, heights);
    int minWay = min(way1, way2);
    if (minWay >= INF) return dp[i] =  INF;
    else return dp[i] = minWay;

}

// Bottom up / iterative
int waysBU(int n, vector<int> &heights) {
    vector<int> DP(n + 10, INF);
    DP[0] = 0;

    for (int i = 1; i < n; i++) {
        if (i - 1 >= 0) {
            DP[i] = min(DP[i], abs(heights[i] - heights[i - 1]) + DP[i - 1]);
        }
        if (i - 2 >= 0) {
            DP[i] = min(DP[i], abs(heights[i] - heights[i - 2]) + DP[i - 2]);
        }
    } return DP[n - 1];

}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    init(n);
    return waysBU( n, heights);
}

int main() {

    return 0;
}