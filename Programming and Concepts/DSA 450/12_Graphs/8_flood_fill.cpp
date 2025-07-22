#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


/*

input as follows

first line contains no. of rows and columns
next n line follows n rows with m numbers each denoting color in that row and column
last line contains starting row and starting column and the color to be changed to


sample input :

5 5
3 3 3 3 3
3 1 1 1 3
3 1 1 1 3
3 1 1 1 3
3 3 3 3 3
2 2 5

sample output :

3 3 3 3 3
3 5 5 5 3
3 5 5 5 3
3 5 5 5 3
3 3 3 3 3


*/



bool isSafe(int i, int j, int n, int m) {

	return i >= 0 and j >= 0 and i < n and j < m;

}


void flood_fill_bfs(vector<vector<int>> grid, vector<vector<bool>>& visited, int sr, int sc, int color) {

	int target_color = grid[sr][sc];
	int n = grid.size();
	int m = grid[0].size();
	queue<pair<int, int>> q;


	// this vector is for the four directions to simplify the code

	vector<pair<int, int>> direction = {

		{ -1, 0}, {0, 1}, {1, 0}, {0, -1}
	};


	// pushing the initial given co-ordinate
	q.push({sr, sc});
	visited[sr][sc] = 1;

	while (!q.empty()) {

		pair<int, int> curr_element = q.front();
		q.pop();

		int r = curr_element.first, c = curr_element.second;

		for (int i = 0; i < 4; ++i)
		{
			int new_r = r + direction[i].first;
			int new_c = c + direction[i].second;


			// check the conditions required before changing the color of the current element

			if (isSafe(new_r, new_c, n, m)
			        and !visited[new_r][new_c]
			        and grid[new_r][new_c] == grid[sr][sc]
			   ) {

				visited[new_r][new_c] = 1;
				grid[new_r][new_c] = color;
				q.push({new_r, new_c});
			}
		}
	}
}


void flood_fill_dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int initialColor, int color, int curr_r, int curr_c, int n, int m) {

	// checking out of bound cases and base case

	if (!isSafe(curr_r, curr_c, n, m)) return;
	if (grid[curr_r][curr_c] != initialColor) return;
	if (visited[curr_r][curr_c]) return;

	// change color and mark visited
	grid[curr_r][curr_c] = color;
	visited[curr_r][curr_c] = 1;

	// top
	flood_fill_dfs(grid, visited, initialColor, color, curr_r - 1, curr_c, n, m);
	// right
	flood_fill_dfs(grid, visited, initialColor, color, curr_r, curr_c + 1, n, m);
	// down
	flood_fill_dfs(grid, visited, initialColor, color, curr_r + 1, curr_c, n, m);
	// left
	flood_fill_dfs(grid, visited, initialColor, color, curr_r, curr_c - 1, n, m);

}


int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m));


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >>  grid[i][j];
		}
	}

	int sr, sc, color, initialColor;
	cin >> sr >> sc >> color;
	initialColor = grid[sr][sc];

	// flood fill dfs
	flood_fill_dfs(grid, visited, initialColor, color, sr, sc, n, m);


	// printing the matrix

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout << grid[i][j] << " ";
		}

		cout << nline;
	}

	// flood fill bfs


	return 0;
}