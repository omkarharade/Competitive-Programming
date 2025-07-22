#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


int smallestSubWithSum_Naive(vector<int>& arr, int n, int x)
{

	int smallest_length = n + 1;

	// simple approach to traverse from start pointer to end pointer

	for (int start = 0; start < n; ++start)
	{
		int curr_sum = arr[start];

		if (curr_sum > x) return 1; // 1 is the smallest answer possible, direct return it

		for (int end = start + 1; end < n; ++end)
		{
			curr_sum += arr[end];

			if (curr_sum > x and (end - start + 1) < smallest_length) {

				smallest_length = min(smallest_length, end - start + 1);

			}
		}
	}

	return smallest_length  == n + 1 ? 0 : smallest_length;

}


int smallestSubWithSum_Optimal(vector<int>& arr, int n, int x) {

	int left = 0, right = 0;
	int currSum = 0, minLength = n + 1;


	while (right < n) {

		// while currSum is not greater than x , keep adding elements

		while (currSum <= x and right < n) {

			currSum += arr[right++];
		}

		// if currSum becomes greater than x do this

		while (currSum > x and left < n) {

			// update length
			minLength = min(minLength, right - left);

			// start reducing the array from left in that case
			currSum -= arr[left++];
		}

	}

	return minLength == n + 1 ? 0 : minLength;

}

int main() {

	int n, x;
	cin >> n >> x;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin  >>  vec[i];
	}

	cout << smallestSubWithSum_Naive(vec, n, x) << nline;
	cout << smallestSubWithSum_Optimal(vec, n, x) << nline;

	return 0;
}