#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


int partition(vector<int> &vec, int l, int r) {

	int i = l - 1;
	int pivot = vec[r];

	for (int j = l; j <= r - 1; ++j)
	{
		if (vec[j] <= pivot) {
			i++;
			swap(vec[i], vec[j]);
		}
	}

	swap(vec[i + 1], vec[r]);

	return i + 1;
}

void quickSort(vector<int> &vec, int l, int r) {

	if (l >= r) return;

	int p = partition(vec, l, r);

	quickSort(vec, l, p - 1);

	quickSort(vec, p + 1, r);

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

	quickSort(vec, 0, n - 1);

	for (auto x : vec) {
		cout << x << " ";
	}
	cout << nline;


	return 0;
}