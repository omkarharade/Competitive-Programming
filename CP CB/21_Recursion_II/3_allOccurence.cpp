#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


// void storeOcc(vector<int> &vec, int i, int n, int target, vector<int> &occ, int &j) {

// 	if (i == n) return;

// 	if (vec[i] == target) {
// 		occ[j] = i;
// 		j++;
// 	}
// 	storeOcc(vec, i + 1, n, target, occ, j);
// }


int storeOcc(vector<int> &vec, int i, int n, int target, vector<int> &occ, int j) {

	if (i == n) return j;

	if (vec[i] == target) {
		occ[j] = i;
		j++;
	}
	storeOcc(vec, i + 1, n, target, occ, j);
}

void allOcc(vector<int> &vec, int i, int n, int target) {

	if (i == n) return;

	if (vec[i] == target) {
		cout << "Present at index : " << i << nline;
	}
	allOcc(vec, i + 1, n, target);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here
	int n;
	cin >> n;

	vector<int> vec(n);
	vector<int> occ(n); // storing occurrence indexes
	int occSize = 0;
	int target = 4;

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	allOcc(vec, 0, n, target);
	occSize = storeOcc(vec, 0, n, target, occ, 0);

	for (int i = 0; i < occSize; ++i)
	{
		cout << occ[i] << " ";
	}
	cout << nline;


	return 0;
}