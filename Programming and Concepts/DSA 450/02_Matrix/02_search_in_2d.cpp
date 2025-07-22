#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

/*

consider the 2d matrix a single 1d array so the
number of elements is n*m

these elements are in sorted order so we can apply
binary search

now lo = 0, hi = n*m-1


so mid is mapped to 2d matrix as
rowIndex = index / no. of columns
columnIndex = index % no. of columns


if target is greater than mid move to right part of partition
else if target is smaller then move to left part of partition
else case means target is present then return true


*/


bool searchMatrix(vector<vector<int>>& matrix, int target) {

	int r = matrix.size();
	int c = matrix[0].size();

	int lo = 0, hi = r * c - 1;
	bool isPresent = 0;

	while (lo <= hi) {

		int mid = lo + (hi - lo) / 2;

		int currR = mid / c, currC = mid % c;

		// if element is less than target move to right
		if (matrix[currR][currC] < target) {
			lo = mid + 1;
		}

		// if element is greater than target move to left
		else if (matrix[currR][currC] > target) {
			hi = mid - 1;
		}
		else {

			// element is present
			return true;
		}
	}

	return false;
}



int main() {

	int r, c, target;
	cin >> r >> c >> target;

	vector<vector<int>> matrix(r, vector<int>(c));

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> matrix[i][j];
		}
	}

	cout << (searchMatrix(matrix, target) ?
	         "element is present" :
	         "element is not present"
	        ) << nline;

	cout << searchMatrix(matrix, target) << nline;
	return 0;
}