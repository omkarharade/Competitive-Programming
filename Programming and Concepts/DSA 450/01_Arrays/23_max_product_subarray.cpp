#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

long long maxProduct(vector<int> arr, int n) {
	// code here

	int ptr = 0;
	long long product = 1LL;
	long long maxProduct = LLONG_MIN;

	while (ptr < n) {
		int firstNeg = -1, lastNeg = -1;
		long long product = 1LL;

		while (ptr < n and arr[ptr] != 0) {

			if (arr[ptr] < 0) {

				if (firstNeg == -1) {
					firstNeg = ptr;
				}
				else {
					lastNeg = ptr;
				}

				product *= arr[ptr];
			}
			else {
				product *= arr[ptr];
			}

			cout << firstNeg << " " << lastNeg << " " << ptr << " " << product << " " << maxProduct << nline;

			ptr++;
		}

		// if (ptr < n and arr[ptr] == 0) {

		// 	if (product > 0) {
		// 		maxProduct = max(maxProduct, product);
		// 	}
		// 	else if (product < 0) {

		// 		long long negNum1 = LLONG_MAX, negNum2 = LLONG_MAX;
		// 		negNum1 = arr[firstNeg];

		// 		if (lastNeg == -1) {
		// 			negNum2 = arr[lastNeg];
		// 		}

		// 		long long minNegNumber = -1 * min(llabs(negNum1), llabs(negNum2));

		// 		// product = product / (minNegNumber);
		// 		// maxProduct = max(maxProduct, product);
		// 	}
		// 	else {
		// 		maxProduct = max(maxProduct, 0LL);
		// 	}

		// 	cout << firstNeg << " " << lastNeg << " "  << ptr << " " << product << " " << maxProduct << nline;

		// 	ptr++;
		// }
		ptr++;
	}

	return maxProduct;
}

int main() {

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {

		cin >> arr[i];
	}

	cout << maxProduct(arr, arr.size());

	return 0;
}