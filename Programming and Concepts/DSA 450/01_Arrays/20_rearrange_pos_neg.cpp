#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

void rearrange_pos_neg(vector<int> &arr) {

	int n = arr.size();

	vector<int> pos;
	vector<int> neg;

	for (int i = 0; i < n; i++) {

		if (arr[i] < 0) {
			neg.push_back(arr[i]);
		}
		else {
			pos.push_back(arr[i]);
		}
	}

	int posPtr = 0, negPtr = 0, arrPtr = 0;

	while (arrPtr < n and posPtr < pos.size() and  negPtr < neg.size()) {

		arr[arrPtr] = pos[posPtr];
		arrPtr++;
		posPtr++;

		if (arrPtr < n and negPtr < neg.size()) {
			arr[arrPtr] = neg[negPtr];
			arrPtr++, negPtr++;
		}
	}

	while (posPtr < pos.size()) {
		arr[arrPtr++] = pos[posPtr++];
	}

	while (negPtr < neg.size()) {
		arr[arrPtr++] = neg[negPtr++];
	}

	// Time complexity : O(N)
	// Space complexity : O(N)

}

void rotate_array(vector<int> &arr, int beg, int end) {

	int num = arr[end];

	for (int i = end; i - 1 >= beg; i--) {
		arr[i] = arr[i - 1];
	}

	arr[beg] = num;
}


void rearrange_pos_neg_efficient(vector<int> &arr) {

	int n = arr.size();

	// positive number index are even indexes
	// negative number index are odd indexes

	for (int i = 0; i < n; ++i)
	{
		if (i % 2 == 0) {

			if (arr[i] < 0) {

				// find first occuring +ve number

				for (int j = i + 1; j < n; ++j)
				{
					if (arr[j] >= 0) {
						rotate_array(arr, i, j);
						break;
					}
				}
			}
		}
		else {

			if (arr[i] >= 0) {

				// find first occuring -ve number

				for (int j = i + 1; j < n; ++j)
				{
					if (arr[j] < 0) {
						rotate_array(arr, i, j);
						break;
					}
				}
			}
		}
	}

	// Time Complexity : O(N*N)
	// Space Complexity : O(1)
}

int main() {

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	// rearrange_pos_neg(arr);
	rearrange_pos_neg_efficient(arr);

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << nline;

	return 0;
}