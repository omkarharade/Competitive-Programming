#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

void merge(vector<int> &vec, int l, int r) {

	int mid = l + ((r - l) / 2);
	vector<int> temp(l + r + 1);

	int i = l, j = mid + 1, k = 0;

	while ((i <= mid) and (j <= r)) {

		if (vec[i] <= vec[j]) {
			temp[k++] = vec[i++];
		}
		else {
			temp[k++] = vec[j++];
		}
	}


	while (j <= r) {
		temp[k++] = vec[j++];
	}

	while (i <= mid) {
		temp[k++] = vec[i++];
	}


	int tempK = 0;

	for (int i = l; i <= r; ++i)
	{
		vec[i] = temp[tempK++];
	}

}

void mergeSort(vector<int> &vec, int l, int r) {

	if (l >= r) return;

	int mid = l + ((r - l) / 2);

	mergeSort(vec, l, mid);
	mergeSort(vec, mid + 1, r);
	merge(vec, l, r);
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

	mergeSort(vec, 0, n - 1);

	for (auto v : vec) {
		cout << v << " ";
	}
	cout << nline;



	return 0;
}