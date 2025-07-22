#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void print_array(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << nline;
}


pair<int, int> kthMinMax(int arr[], int n, int k) {

	pair<int, int> minMax;
	sort(arr, arr + n);

	minMax.first = arr[k - 1];
	minMax.second = arr[n - k];

	return minMax;
}
/*

Time complexity : O( n * log n )
Space complexity : O(1)

*/


int kthSmallest(int arr[], int n, int k) {

	multiset<int, greater<int>> multiSet;


	for (int i = 0; i < n; i++) {

		multiSet.insert(arr[i]);

		if (multiSet.size() > k) {

			multiSet.erase(multiSet.begin());

		}
	}

	return *multiSet.begin();
}
/*

Time complexity : O( n * log K )
Space complexity : O(k)

*/

int main() {

	int n, k;
	cin >> n >> k;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	pair<int, int> minMax = kthMinMax(arr, n, k);

	cout << k << "th minimum element is " << minMax.first << nline;
	cout << k << "th maximim element is " << minMax.second << nline;
	cout << k << "th minimum element is " << kthSmallest(arr, n, k);

	return 0;
}