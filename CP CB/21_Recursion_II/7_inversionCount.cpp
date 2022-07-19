#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

int merge(vector<int> &vec, int l, int r) {

	int mid = l + ((r - l) / 2);
	int i = l;
	int j = mid + 1;
	int k = 0;
	int invCount = 0;

	vector<int> temp(l + r + 1);

	while ( (i <= mid) and (j <= r) ) {

		if (vec[i] <= vec[j]) {
			temp[k++] = vec[i++];
		}
		else {
			temp[k++] = vec[j++];
			invCount += (mid - i + 1);
		}
	}

	while (i <= mid) {

		temp[k++] = vec[i++];
	}

	while (j <= r) {

		temp[k++] = vec[j++];
	}

	int tempK = 0;
	for (int i = l; i <= r; ++i)
	{
		vec[i] = temp[tempK++];
	}

	return invCount;

}

int inversionCount(vector<int> &vec, int l, int r) {

	if (l >= r) return 0;

	int mid = l + ((r - l) / 2);

	int x = inversionCount(vec, l, mid);
	int y = inversionCount(vec, mid + 1, r);
	int z = merge(vec, l, r);

	return x + y + z;
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

	cout << inversionCount(vec, 0, n - 1) << nline;

	for (auto x : vec) {
		cout << x << " ";
	}
	cout << nline;


	return 0;
}