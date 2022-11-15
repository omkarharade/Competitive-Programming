#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

bool isSafe(int i, int j, int n) {
	return i >= 0 and i < n and  j >= 0 and  j < n ;
}

void paths(int i, int j, vector<vector<int>> &m, vector<vector<bool>> &vis, int n, string &pathDes, vector<string> &ans) {


	if (!isSafe(i, j, n)) return;
	if (m[i][j] == 0) return;
	if (vis[i][j]) return;
	if (i == n - 1 and j == n - 1) {
		ans.push_back(pathDes);
		return;
	}

	vis[i][j] = 1;

	pathDes.push_back('U');
	paths(i - 1, j, m, vis, n, pathDes, ans);
	pathDes.pop_back();

	pathDes.push_back('D');
	paths(i + 1, j, m, vis, n, pathDes, ans);
	pathDes.pop_back();

	pathDes.push_back('L');
	paths(i, j - 1, m, vis, n, pathDes, ans);
	pathDes.pop_back();

	pathDes.push_back('R');
	paths(i, j + 1, m, vis, n, pathDes, ans);
	pathDes.pop_back();

	vis[i][j] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
	// Your code goes here

	vector<string> ans;
	vector<vector<bool>> vis(n, vector<bool>(n, 0));
	string pathDes;
	paths(0, 0, m, vis, n, pathDes, ans);

	return ans;
}

int main() {


	return 0;
}