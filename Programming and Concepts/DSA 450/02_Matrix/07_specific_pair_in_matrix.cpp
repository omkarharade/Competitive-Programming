#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int find_max_diff_naive(vector<vector<int>>& matrix, int n) {

	int maxValue = INT_MIN;

	for (int a = 0; a < n; a++) {

		for (int b = 0; b < n; b++) {

			// for all possible combinations of a and b


			for (int c = a + 1; c < n; ++c)
			{

				for (int d = b + 1; d < n; ++d)
				{

					if (a < c and  b < d) {

						maxValue = max(maxValue, matrix[c][d] - matrix[a][b]);

					}
				}
			}
		}
	}

	return maxValue;
}





int find_max_diff_better(vector<vector<int>>& matrix, int n) {


	int maxValue = INT_MIN;

	vector<vector<int>> maxArr(n, vector<int>(n, -1));
	maxArr[n - 1][n - 1] = matrix[n - 1][n - 1];


	int currMax = matrix[n - 1][n - 1];

	// preprocess last row
	for (int i = n - 2; i >= 0; --i)
	{
		if (matrix[n - 1][i] > currMax) currMax = matrix[n - 1][i];
		maxArr[n - 1][i] = currMax;
	}


	// preprocess last column
	for (int i = n - 2; i >= 0; --i)
	{
		if (matrix[i][n - 1] > currMax) currMax = matrix[i][n - 1];
		maxArr[i][n - 1] = currMax;
	}


	// now using the processed last row and col ,
	// preprocess all the rest of the elements


	for (int i = n - 2; i >= 0; --i)
	{
		for (int j = n - 2; j >= 0; --j)
		{

			// maxArr[i][j] contains max(maxArr[i+1][j], maxArr[i][j+1])
			// that is max from row(i+1 to n-1) & col(j+1 to n-1)

			if (maxArr[i + 1][j + 1]  - matrix[i][j] > maxValue) {


				// this below line stores the actual value to answer
				// this calculates difference of current matrix[i][j]
				// minus the max possible value from i+1 to end row
				// and j+1 column to end

				maxValue = maxArr[i + 1][j + 1] - matrix[i][j];

			}

			// now its time to update the maxArr of current i and j

			maxArr[i][j] = max(matrix[i][j], max(maxArr[i + 1][j], maxArr[i][j + 1]));

		}
	}

	return maxValue;
}



int find_max_diff_optimal(vector<vector<int>>& matrix, int n) {

	vector<int> temp1(n), temp2(n);
	int maxValue = INT_MIN;


	// fill temp1 array

	temp1[n - 1] = matrix[n - 1][n - 1];

	for (int j = n - 2; j >= 0; j--) {

		temp1[j] = max(temp1[j + 1], matrix[n - 1][j]);
	}

	// fill the rest of the array consider temp1 array to be the i+1_th row of maxarr


	for (int i = n - 2; i >= 0; i--) {

		// initializing last element of temp2

		temp2[n - 1] = max(temp1[n - 1], matrix[i][n - 1]);

		for (int j = n - 2; j >= 0; j--) {

			if (temp1[j + 1] - matrix[i][j] > maxValue)
				maxValue = temp1[j + 1] - matrix[i][j];

			temp2[j] = max({matrix[i][j], temp1[j], temp2[j + 1]});
		}

		// Set temp1 to temp2 for the next iteration
		temp1 = temp2;
	}

	// return max value
	return maxValue;

}


int main() {

	int n;
	cin >> n;

	vector<vector<int>> matrix(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> matrix[i][j];
		}
	}

	cout << "maximum difference of pairs is " << find_max_diff_naive(matrix, n) << nline;
	cout << "maximum difference of pairs is " << find_max_diff_better(matrix, n) << nline;
	cout << "maximum difference of pairs is " << find_max_diff_optimal(matrix, n) << nline;
	return 0;
}