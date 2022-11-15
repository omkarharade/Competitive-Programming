#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


long long int countInversions_Naive(long long arr[], long long N) {

	long long int ans = 0;

	for (int i = 0; i < N; i++) {

		for (int j = i + 1; j < N; j++) {

			if (arr[i] > arr[j]) {
				ans++;
			}
		}
	}

	return ans;
}

long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right) {

	long long int lptr = left, rptr = mid + 1, tempPtr = left;
	long long int inversion_count = 0;

	while (lptr <= mid and rptr <= right) {

		if (arr[lptr] <= arr[rptr]) {
			temp[tempPtr++] = arr[lptr++];
		}
		else {
			temp[tempPtr++] = arr[rptr++];
			inversion_count += (mid - lptr + 1);
		}
	}

	while (lptr <= mid) {
		temp[tempPtr++] = arr[lptr++];
	}

	while (rptr <= right) {
		temp[tempPtr++] = arr[rptr++];
	}

	for (int i = left; i <= right; i++) {
		arr[i] = temp[i];
	}

	return inversion_count;
}

long long int merge_sort(long long arr[], long long temp[], long  left, long right) {

	long long int inversion_count = 0;

	if (left < right) {

		long long mid = left + (right - left) / 2;

		// split and calculate inversion of left subarray and right subarray

		inversion_count += merge_sort(arr, temp, left, mid);

		inversion_count += merge_sort(arr, temp, mid + 1, right);


		// merging and calculating inversionCount after merging

		inversion_count += merge(arr, temp, left, mid, right);

	}

	return inversion_count;
}

long long int inversionCount(long long arr[], long long N)
{
	// Your Code Here
	long long temp[N];
	long long int inversion_count = 0;

	long long left = 0, right = N - 1;

	for (int i = 0; i < N; ++i)
	{
		temp[i] = -1;
	}

	inversion_count += merge_sort(arr, temp, left, right);
	return inversion_count;

}


int main() {

	long long  N;
	cin >> N;

	long long arr[N];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cout << countInversions_Naive(arr, N) << nline;
	cout << inversionCount(arr, N) << nline;

	return 0;
}