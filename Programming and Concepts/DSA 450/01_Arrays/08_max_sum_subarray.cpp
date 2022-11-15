#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void print_array(int arr[], int n) {

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << nline;
}


// kadane's Algorithm

long long naiveSubarraySum(int arr[], int n) {

	long long maxSum = LLONG_MIN;

	for (int i = 0; i < n; i++) {

		long long sum = 0;

		for (int j = i; j < n; j++) {

			sum += arr[j];

			maxSum = max(maxSum, sum);
		}
	}

	return  maxSum;
}

long long maxSubarraySum(int arr[], int n) {

	// Your code here

	long long sum = 0LL;
	long long maxSum = LLONG_MIN;

	for (int i = 0; i < n; i++) {

		sum += arr[i];
		maxSum = max(maxSum, sum);

		if (sum < 0) {
			sum = 0;
		}
	}

	return maxSum;

}

int main() {

	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long ans = maxSubarraySum(arr, n);
	long long ans2 = naiveSubarraySum(arr, n);
	cout << ans << nline;
	cout << ans2 << nline;


	return 0;


	return 0;
}