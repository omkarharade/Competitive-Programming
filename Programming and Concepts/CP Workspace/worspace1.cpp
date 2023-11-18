#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

bool isSafe(int i, int j, int n) {

	return i < n and j < n and  i >= 0 and j >= 0;
}



vector<pair<int, int>> diag = {

	{ -1, -1}, { -1, 1}, {1, -1}, {1, 1}
};



void printDiag(vector<vector<int>> &mat, set<int> &st, int i, int j, int n) {

	if (!isSafe(i, j, n)) return;
	if (st.count(mat[i][j] > 0)) return;
	st.insert(mat[i][j]);

	cout << mat[i][j] << " ";

	for (int k = 0; k < 4; ++k)
	{
		int newX = i + diag[k].first, newY = j + diag[k].second;

		if (!isSafe(i, j, n)) return;
		if (st.count(mat[i][j] > 0)) return;
		st.insert(mat[i][j]);

		cout << mat[newX][newY] << " ";
	}
}


int main() {

	int n;
	cin >> n;

	vector<vector<int>> mat(n, vector<int>(n));
	set<int> st;


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> mat[i][j];
		}
	}

	return 0;
}