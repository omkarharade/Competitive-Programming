#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

const int N = 1e5 + 10;
bool vis[N];
vector<vector<char>> g;
int height = -1;

int dfs(int i, int j, int h, int w, char nxtChar) {

	if (vis[int(g[i][j] - 65)]) return 0;

	if (i < 0 or j < 0) return 0;
	if (i >= h or j >= w) return 0;
	if (nxtChar > 'Z') return 0;

	if ((g[i][j] != nxtChar)) return 0;
	else;

	vis[int(g[i][j] - 65)] = true;

	int maxLen = -1;

	maxLen = max( maxLen, 1 + dfs(i - 1, j, h, w, nxtChar + 1));
	maxLen = max(maxLen, 1 + dfs(i + 1, j, h, w, nxtChar + 1));
	maxLen = max(maxLen, 1 + dfs(i, j + 1, h, w, nxtChar + 1));
	maxLen = max(maxLen, 1 + dfs(i, j - 1, h, w, nxtChar + 1));
	maxLen = max(maxLen, 1 + dfs(i + 1, j + 1, h, w, nxtChar + 1));
	maxLen = max(maxLen, 1 + dfs(i - 1, j - 1, h, w, nxtChar + 1));
	maxLen = max(maxLen, 1 + dfs(i + 1, j - 1, h, w, nxtChar + 1));
	maxLen = max(maxLen, 1 + dfs(i - 1, j + 1, h, w, nxtChar + 1));

	return maxLen;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int h, w;
	cin >> h >> w;

	g.resize(h);

	for (int i = 0; i < h; i++) {
		g[i].resize(w);
		for (int j = 0; j < w; ++j)
		{
			cin >> g[i][j];

		}
	}

	for (auto v : g) {
		for (auto e : v) {
			cout << e << " ";
		}
		cout << nline;
	}

	cout << dfs(0, 0, h, w, 'A') << nline;

	return 0;
}