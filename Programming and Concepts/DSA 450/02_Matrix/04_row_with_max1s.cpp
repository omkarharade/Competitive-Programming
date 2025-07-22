#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


/*


Naive approach :

	for each row i count number of 1s present in there

	time complexity : O(r*c)
	space complexity : O(1)


Expected approach :

	the idea is to traverse from top left element
	as it is sorted so

 	if the curr element is 1 we go to left (col--)
 	to check if more 1s are there or not

 	if curr element is 0 then we cant get any max 1s here
 	so we move down (row++)

 	hence we traverse the matrix in linear fashion

 	time complexity : O(r + c)
 	space complexity : O(1)
*/

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	// code here

	int currR = 0, currC = m - 1;

	int  maxCount = 0;
	int result_row = -1;

	while (currR < n and currC >= 0) {

		if (arr[currR][currC] == 1) {
			if (m - currC > maxCount) {
				result_row = currR;
			}

			currC--;
		}

		else if (arr[currR][currC] == 0) {

			currR++;

		}

	}

	return result_row;
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

	cout << rowWithMax1s(matrix, r, c) << nline;

	return 0;
}