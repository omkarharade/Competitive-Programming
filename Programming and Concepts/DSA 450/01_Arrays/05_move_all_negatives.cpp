#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void print_array(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << nline;
}

// Naive approach is to sort the array so that negative element to left and positive element to right


// below two approach uses 2 pointer


void move_negatives(int arr[], int n) {

	int negative = 0;

	for (int i = 0; i < n; i++) {

		if (arr[i] < 0) {
			swap(arr[i], arr[negative++]); // this approach changes the relative ordering of elements
		}
	}

	print_array(arr, n);
}

void move_negatives2(int arr[], int n) {

	/*
		Two Pointer Approach: The idea is to solve this problem with constant space and linear time is by using a two-pointer or two-variable approach where we simply take two variables like left and right which hold the 0 and N-1 indexes. Just need to check that :

		Check If the left and right pointer elements are negative then simply increment the left pointer.
		Otherwise, if the left element is positive and the right element is negative then simply swap the elements, and simultaneously increment and decrement the left and right pointers.
		Else if the left element is positive and the right element is also positive then simply decrement the right pointer.
		Repeat the above 3 steps until the left pointer ? right pointer.

	*/


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