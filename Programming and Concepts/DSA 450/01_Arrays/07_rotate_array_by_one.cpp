#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

void print_array(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << nline;
}

void cycle_rotate_by_one_left(int arr[], int n) {

	int temp = arr[0];

	for (int i = 0; i + 1 < n; i++) {
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = temp;

	print_array(arr, n);
}

void cycle_rotate_by_one_right(int arr[], int n)
{
	int temp = arr[n - 1];

	for (int i = n - 1; i - 1 >= 0; i--) {
		arr[i] = arr[i - 1];
	}
	arr[0] = temp;

	print_array(arr, n);
}


int main() {

	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cycle_rotate_by_one_left(arr, n);
	cycle_rotate_by_one_right(arr, n);

	return 0;
}