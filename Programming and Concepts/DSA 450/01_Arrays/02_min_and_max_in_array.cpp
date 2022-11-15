#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void print_array(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << nline;
}



pair<int, int> get_min_max(int arr[], int n) {

	pair<int, int> minmax;

	minmax.first = arr[0];
	minmax.second = arr[0];

	for (int i = 0; i < n; i++) {

		if (minmax.first > arr[i]) {
			minmax.first = arr[i];
		}
		else if (minmax.second < arr[i]) {
			minmax.second = arr[i];
		}
	}

	return minmax;
}


// first element in the pair is considered as minimum
// second element in the pair is considered as maximum

pair<int, int> get_min_max2(int arr[], int lo, int hi) {

	pair<int, int> minmaxL, minmaxR, minmaxTotal;


	// for array containing only one element

	if (lo == hi) {
		minmaxTotal.first = arr[lo];
		minmaxTotal.second = arr[hi];
		return minmaxTotal;
	}

	// for array with two elements

	if (lo + 1 == hi) {

		minmaxTotal.first = (arr[lo] <= hi ? arr[lo] : arr[hi] );
		minmaxTotal.second = (arr[lo] >= arr[hi] ? arr[lo] : arr[hi]);
		return minmaxTotal;
	}

	int mid = lo + (hi - lo) / 2;

	minmaxL = get_min_max2(arr, lo, mid);
	minmaxR = get_min_max2(arr, mid + 1, hi);

	// comparing minimums

	if (minmaxL.first <= minmaxR.first) minmaxTotal.first = minmaxL.first;
	else minmaxTotal.first = minmaxR.first;

	// comparing maximums

	if (minmaxL.second >= minmaxR.second) minmaxTotal.second = minmaxL.second;
	else minmaxTotal.second = minmaxR.second;

	return minmaxTotal;
}

int main() {

	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	pair<int, int> minmax, minmax2;
	minmax = get_min_max(arr, n);
	minmax2 = get_min_max2(arr, 0, n - 1);

	cout << "minimum element : " << minmax.first << nline;
	cout << "maximum element : " << minmax.second << nline;

	cout << "minimum element : " << minmax2.first << nline;
	cout << "maximum element : " << minmax2.second << nline;




	return 0;
}