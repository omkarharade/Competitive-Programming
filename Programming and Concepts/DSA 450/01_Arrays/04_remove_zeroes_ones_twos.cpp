#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void print_array(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << nline;
}

void sort_zero_ones_twos(int arr[], int n) {
	int cnt0 = 0, cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < n; i++) {

		if (arr[i] == 0) cnt0++;
		else if (arr[i] == 1) cnt1++;
		else if (arr[i] == 2) cnt2++;
	}

	int indx = 0;

	while (cnt0--) {

		arr[indx++] = 0;
	}

	while (cnt1--) {

		arr[indx++] = 1;
	}

	while (cnt2--) {

		arr[indx++] = 2;
	}

	print_array(arr, n);

}

void sort_zero_ones_twos2(int arr[], int n) {

	int lo = 0, hi = n - 1, mid = 0;

	while (mid <= hi) {

		if (arr[mid] == 0) {
			swap(arr[lo++], arr[mid++]);
		}
		else if (arr[mid] == 1) {
			mid++;
		}
		else if (arr[mid] == 2) {
			swap(arr[mid], arr[hi--]);
		}
	}

	print_array(arr, n);
}

int main() {

	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort_zero_ones_twos(arr, n);
	cout << "completed" << nline;
	sort_zero_ones_twos2(arr, n);

	cout << "completed" << nline;

	return 0;
}