#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


void bubbleSortRecur(vector<int> &vec, int n) {

	if (n == 1) return;

	for (int i = 0; i + 1 < n; i++) {

		if (vec[i] > vec[i + 1]) {
			swap(vec[i], vec[i + 1]);
		}
	}
	bubbleSortRecur(vec, n - 1);
}


void bubbleSortTotalRecur(vector<int> &vec, int n, int i) {

	if (i + 1 == n) return;
	if (n == 1) return;


	if (vec[i] > vec[i + 1]) {
		swap(vec[i], vec[i + 1]);
	}
	bubbleSortTotalRecur(vec, n, i + 1);

	bubbleSortTotalRecur(vec, n - 1, 0);
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; i++) cin >> vec[i];

	// bubbleSortRecur(vec, n);
	bubbleSortTotalRecur(vec, n, 0);

	for (auto v : vec) {
		cout << v << " ";
	}
	cout << nline;

	return 0;
}