#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int getPairsCount_Naive(int arr[], int n, int k) {
	// code here

	int count = 0;

	for (int i = 0; i < n; i++) {

		int currSum = arr[i];

		for (int j = i + 1; j < n; j++) {

			if (arr[j] == (k - arr[i])) {
				count++;
			}
		}
	}

	return count;

	// Time Complexity: O(n^2)
	// Auxiliary Space: O(1)

}

int getPairsCount_Efficient2(int arr[], int n, int k) {

	// if array is sorted : using Binary Search
	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		int target = k - arr[i];

		int lo = lower_bound(arr + (i + 1), arr + n, target) - arr;
		int hi = upper_bound(arr + (i + 1), arr + n, target) - arr;

		count += (hi - lo);
	}

	return count;

	// Time Complexity: O(n * log(n) )
	// Auxiliary Space: O(1)
}


int getPairsCount_Efficient(int arr[], int n, int k) {

	// using hash map with two loops

	unordered_map<int, int> unmap;
	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		unmap[arr[i]]++;
	}

	for (int i = 0; i < n; ++i)
	{
		unmap[arr[i]]--;

		if (unmap.find(k - arr[i]) != unmap.end()) {
			count += (unmap[k - arr[i]]);
		}
	}

	return count;

	// Time Complexity: O(n)
	// Auxiliary Space: O(n)
}

int getPairsCount_Efficient3(int arr[], int n, int k) {

	// using hash map with one loops

	unordered_map<int, int> unmap;
	int count = 0;

	for (int i = 0; i < n; ++i)
	{

		if (unmap.find(k - arr[i]) != unmap.end()) {
			count += (unmap[k - arr[i]]);
		}

		unmap[arr[i]]++;
	}

	return count;

	// Time Complexity: O(n)
	// Auxiliary Space: O(n)
}

int main() {

	int n, k;
	cin >> n >> k;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << getPairsCount_Naive(arr, n, k) << nline;
	cout << getPairsCount_Efficient(arr, n, k) << nline;
	cout << getPairsCount_Efficient2(arr, n, k) << nline;
	cout << getPairsCount_Efficient3(arr, n, k) << nline;


	return 0;
}