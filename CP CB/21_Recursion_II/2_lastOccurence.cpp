#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int lastOccurence(vector<int> &vec, int i, int n, int target) {

	if (i == n) return -1;

	int ans  = lastOccurence(vec, i + 1, n, target);

	if (ans == -1) {

		if (vec[i] == target) {
			return i;
		}
		else return -1;
	}
	else return ans;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	vector<int> vec(n);
	int target = 4;

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	int ans = lastOccurence(vec, 0, n, target);

	if (ans == -1) {
		cout << "Number is not Present" << nline;
	}
	else {
		cout << "Number is Present at index : " << ans << nline;
	}

	return 0;
}