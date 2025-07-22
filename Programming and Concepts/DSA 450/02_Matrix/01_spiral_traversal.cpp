#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c)
{
	// code here

	vector<int> ans;

	int top = 0, bottom = r - 1, left = 0, right = c - 1;

	while (left <= right and top <= bottom) {


		// left to right (row same : top)

		if (top <= bottom) {

			for (int i = left; i <= right; i++) {

				ans.push_back(matrix[top][i]);

			}

			top++;
		}


		// top to bottom (column same : right)

		if (left <= right) {

			for (int i = top; i <= bottom; i++) {

				ans.push_back(matrix[i][right]);

			}

			right--;
		}

		// right to left (row same : bottom)

		if (top <= bottom) {

			for (int i = right; i >= left; i--) {

				ans.push_back(matrix[bottom][i]);

			}

			bottom--;
		}

		// bottom to top (column same : left)


		if (left <= right) {

			for (int i = bottom; i >= top; i--) {

				ans.push_back(matrix[i][left]);
			}

			left++;
		}
	}

	return ans;
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


	vector<int> spiral = spirallyTraverse(matrix, r, c);

	for (int i = 0; i < spiral.size(); ++i)
	{
		cout << spiral[i] << " ";
	}

	cout << "\n";

	return 0;
}