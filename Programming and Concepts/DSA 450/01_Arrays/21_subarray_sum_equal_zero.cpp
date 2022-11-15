#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

bool subArrayExists_Naive(int arr[], int n) {

	bool ok = 0;

	for (int i = 0; i < n; ++i)
	{
		int sum = 0;

		for (int j = i; j < n; ++j)
		{
			sum += arr[j];

			if (sum == 0) {
				ok = 1;
				break;
			}
		}

		if (ok) break;
	}

	return ok;
}

bool subArrayExists_efficient(int arr[], int n)
{
	//Your code here
	unordered_set<int> unset;

	int sum = 0;
	bool ok = 0;

	// for arrays whose total elements sum is 0;
	unset.insert(0);

	for (int i = 0; i < n; i++) {
		sum += arr[i];

		if (unset.find(sum) == unset.end()) {
			unset.insert(sum);
		}
		else {
			ok = 1;
			break;
		}
	}

	return ok;
}


int main() {

	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	bool ans1 = subArrayExists_Naive(arr, n);
	bool ans2 = subArrayExists_Naive(arr, n);

	cout << (ans1 ? "Yes" : "No") << nline;
	cout << (ans2 ? "Yes" : "No") << nline;


	return 0;
}