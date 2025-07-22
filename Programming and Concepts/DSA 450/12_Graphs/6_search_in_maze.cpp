
#include <bits/stdc++.h>
using namespace std;
#define nline "\n";




bool isSafe(int i, int j, int n) { // to prevent going out of bound of matrix

	return (i < n and i >= 0 and j < n and j >= 0);
}



void paths(int r, int c, int n, vector<vector<int>>& grid, vector<vector<bool>>& vis, string path, vector<string>& pathStore) {


	if (!isSafe(r, c, n)) return;
	if (grid[r][c] == 0) return;
	if (vis[r][c]) return;


	if (r == n - 1 and c == n - 1) {
		pathStore.push_back(path);
	}
	vis[r][c] = 1;

	paths(r + 1, c, n, grid, vis, path + 'D', pathStore);
	paths(r - 1, c, n, grid, vis, path + 'U', pathStore);
	paths(r, c + 1, n, grid, vis, path + 'R', pathStore);
	paths(r, c - 1, n, grid, vis, path + 'L', pathStore);

	vis[r][c] = 0;
	return;
}


vector<string> findPath(vector<vector<int>> &m, int n) {
	// Your code goes here

	vector<string> pathStore;
	vector<vector<bool>> vis(n, vector<bool>(n, 0));

	paths(0, 0, n, m, vis, "", pathStore);

	return pathStore;
}


int main() {

	int n;
	cin >> n;


	vector<vector<int>> maze(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> maze[i][j];
		}
	}

	vector<string> ans = findPath(maze, n);


	return 0;
}