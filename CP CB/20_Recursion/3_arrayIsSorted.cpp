#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

bool isSorted(vector<int> &vec, int i, int n) {

	if ((i == n - 1) or (i == n)) return true;

	if ((vec[i] <= vec[i + 1]) and (isSorted(vec, i + 1, n))) {
		return true;
	}
	else return false;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	if (isSorted(vec, 0, n)) cout << "Array is Sorted" << nline;
	else cout << "Array is not Sorted" << nline;


	return 0;
}