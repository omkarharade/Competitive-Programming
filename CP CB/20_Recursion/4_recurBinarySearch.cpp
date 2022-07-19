#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int recurBinarySearch(vector<int> &vec, int l, int r, int target) {

	if (l > r) return -1;

	int mid = l + ((r - l) / 2);

	if (vec[mid] == target) return mid;

	if (vec[mid] < target) return recurBinarySearch(vec, mid + 1, r, target);
	else return recurBinarySearch(vec, l, mid - 1, target);

}



int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	vector<int> vec(n);
	int target = 8;

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	int ans = recurBinarySearch(vec, 0, n - 1, target);

	if (ans == -1) {
		cout << "Number is not present" << nline;
	}
	else cout << "Number is present at index : " << ans << nline;


	return 0;
}