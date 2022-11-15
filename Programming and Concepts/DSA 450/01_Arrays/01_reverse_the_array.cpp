#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void print_array(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << nline;
}



void reverse_the_array(int arr[], int n) {

	int lo = 0, hi = n - 1;

	while (lo < hi) {
		swap(arr[lo], arr[hi]);
		lo++, hi--;
	}
}

int main() {

	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	reverse_the_array(arr, n);
	print_array(arr, n);

	return 0;
}