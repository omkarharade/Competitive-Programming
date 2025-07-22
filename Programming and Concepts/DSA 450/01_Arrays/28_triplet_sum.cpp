#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


// Naive Solution : O(N^3) solution
bool findTriplet(int arr[], int n, int X) {

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if (arr[i] + arr[j] + arr[k]) {

					return true;
				}
			}
		}
	}

	return false;
}


// Efficient Solution : loop + 2 pointer  = O(N^2) solution
bool find3Numbers(int A[], int n, int X)
{
	//Your Code Here

	sort(A, A + n);
	bool ok = 0;

	for (int i = 0; i < n; i++) {

		int req = X - A[i], lo = i + 1, hi = n - 1;

		while (lo < hi) {

			int currSum = A[lo] + A[hi];

			if (currSum == req) {
				ok = 1;
				break;
			}
			else if (currSum > req) {
				hi--;
			}
			else {
				lo++;
			}
		}

		if (ok) break;
	}

	return ok;
}

int main() {


	return 0;
}