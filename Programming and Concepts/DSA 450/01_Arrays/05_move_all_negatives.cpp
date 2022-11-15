#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void print_array(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << nline;
}


void move_negatives(int arr[], int n) {

	int negative = 0;

	for (int i = 0; i < n; i++) {

		if (arr[i] < 0) {
			swap(arr[i], arr[negative++]);
		}
	}

	print_array(arr, n);
}

void move_negatives2(int arr[], int n) {

	int lo = 0, hi = n - 1;

	while (lo < hi) {

		if (arr[lo] < 0 and  arr[hi] < 0) {
			lo++;
		}
		else if (arr[lo] >= 0 and  arr[hi] < 0) {
			swap(arr[lo], arr[hi]);
			hi--; lo++;
		}
		else if (arr[lo] >= 0 and arr[hi] >= 0) {
			hi--;
		}
		else if (arr[lo] < 0 and  arr[hi] >= 0) {
			lo++, hi--;
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

	move_negatives(arr, n);
	move_negatives2(arr, n);

	return 0;
}