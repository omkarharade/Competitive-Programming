#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(vector<vector<int>>& a, int n)
{

	// Traverse each cycle
	for (int i = 0; i < n / 2; i++) {
		for (int j = i; j < n - i - 1; j++) {

			// Swap elements of each cycle
			// in clockwise direction
			int temp = a[i][j];
			a[i][j] = a[n - 1 - j][i];
			a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
			a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
			a[j][n - 1 - i] = temp;
		}
	}
}

/*

Method 2:

Approach: The approach is based on the pattern made by indices after rotating the matrix. Consider the following illustration to have a clear insight into it.

Consider a 3 x 3 matrix having indices (i, j) as follows.

00 01 02
10 11 12
20 21 22

After rotating the matrix by 90 degrees in clockwise direction, indices transform into
20 10 00  current_row_index = 0, i = 2, 1, 0
21 11 01 current_row_index = 1, i = 2, 1, 0
22 12 02  current_row_index = 2, i = 2, 1, 0

*/



void rotate90Clockwise2(vector<vector<int>>& a, int n) {

	for (int j = 0; j < n; j++)
	{
		for (int i = n - 1; i >= 0; i--)
			cout << a[i][j] << " ";
		cout << '\n';
	}
}


/*
	Method 3:

	Approach: The Approach is to rotate the given matrix two times,
 	first time with respect to the Main diagonal, next time
 	rotate the resultant matrix with respect to the middle column

*/

void rotate90Clockwise3(vector<vector<int>>& a, int n)
{

	// First rotation
	// with respect to main diagonal
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			int temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	}

	// Second rotation
	// with respect to middle column
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n / 2; ++j)
		{
			int temp = a[i][j];
			a[i][j] = a[i][n - j - 1];
			a[i][n - j - 1] = temp;
		}
	}
}

/*
	Method 4:

	Approach: This approach is similar to method 3 the
 	only difference is that in first rotation we rotate about
 	the Secondary Diagonal and after that about the Middle row.
*/

void rotate90Clockwise4(vector<vector<int>>& a, int n) {

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			int temp = a[i][j];
			a[i][j] = a[n - 1 - j][n - 1 - i];
			a[n - 1 - j][n - 1 - i] = temp;
		}
	}

	// Second rotation
	// with respect to middle row
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = a[i][j];
			a[i][j] = a[n - 1 - i][j];
			a[n - 1 - i][j] = temp;
		}
	}
}

int main() {


	return 0;
}