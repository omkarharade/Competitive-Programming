#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int firstOcc(vector<int> &vec, int i, int n, int target) {

	if (i == n) return -1;

	if (vec[i] == target) return i;

	return firstOcc(vec, i + 1, n, target);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	vector<int> vec(n);
	int target = 3;

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	int ans = firstOcc(vec, 0, n, target);

	if (ans == -1) {
		cout << "Element not Present" << nline;
	}
	else cout << "First Occurance at index : " << ans << nline;

	return 0;
}