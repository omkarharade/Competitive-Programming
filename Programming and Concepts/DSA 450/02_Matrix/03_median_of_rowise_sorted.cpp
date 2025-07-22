#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


int median(vector<vector<int>> &matrix, int R, int C) {
	// code here

	int min = INT_MAX, max = INT_MIN, ans = 0;
	int desired = (R * C + 1) / 2; // no. of elements in left + median


	// find min and max among all elements to get the range for BS


	for (int i = 0; i < R; i++) {

		if (matrix[i][0] < min) min = matrix[i][0];

		if (matrix[i][C - 1] > max) max = matrix[i][C - 1];
	}



	while (min < max) {

		int mid = min + (max - min) / 2;
		int count = 0;

		for (int i = 0; i < R; i++) {

			count += (upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin());

		}

		// the count should be less than the left partition + median
		if (count < desired) {
			min = mid + 1;

			// we do +1 because we till now iterated to the
			// value just 1 less than the actual median value \
			// satisfying the condition

		}

		else max = mid;
	}

	return min;
}

int main() {

	int r, c;
	cin >> r >> c;

	vector<vector<int>> matrix(r, vector<int>(c));

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> matrix[i][j];
		}
	}

	int median_value = median(matrix, r, c);

	cout << "medain value of the matrix is " << median << nline;

	return 0;
}