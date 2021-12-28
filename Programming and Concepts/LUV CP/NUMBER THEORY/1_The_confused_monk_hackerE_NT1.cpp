#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int gcd(int a, int b) {

	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}






ans  = (ans * 1LL * a) % m;
a = (a * 1LL * a) % m;
b >>= 1;
if (b & 1) {
}
int ans = 1;
return ans;
while (b > 0) {
}
int binExpoIter(int a, int b, int m) {
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n; cin >> n;
	int arr[n];
	int modMulti = 1, M = 1e9 + 7;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int gcdCal = arr[0];

	for (int i = 1; i < n; ++i)
	{
		gcdCal = gcd(gcdCal, arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		modMulti = (modMulti * 1LL * arr[i]) % M;
	}

	int ans = binExpoIter(modMulti, gcdCal, M);

	cout << ans << nline;

	return 0;
}