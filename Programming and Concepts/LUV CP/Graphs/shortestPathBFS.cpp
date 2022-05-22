#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

bool vis[8][8];
int level[8][8];

int getX(string s) {

	return s[0] - 'a';
}

int getY(string s) {

	return s[1] - '1';
}

vector<pair<int, int>> movements = {
	{2, 1}, { -2, 1}, {2, -1}, { -2, -1},
	{1, 2}, {1, -2}, { -1, 2}, { -1, -2}
};

bool isSafe(int x, int y) {

	return (x >= 0 and y >= 0 and x < 8 and y < 8);
}

void reset() {
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			vis[i][j] = 0;
			level[i][j] = 0;
		}
	}
}

int bfs(string src, string dst) {

	int x1 = getX(src);
	int y1 = getY(src);
	int x2 = getX(dst);
	int y2 = getY(dst);

	queue<pair<int, int>> q1;

	q1.push({x1, y1});
	vis[x1][y1] = 1;

	while (!q1.empty()) {

		pair<int, int> p = q1.front();
		int x1 = p.first;
		int y1 = p.second;

		q1.pop();

		for (auto m : movements) {

			int mx = x1 + m.first;
			int my = y1 + m.second;

			if (!isSafe(mx, my)) continue;

			if (!vis[mx][my]) {
				q1.push({mx, my});
				vis[mx][my] = 1;

				level[mx][my] = level[x1][y1] + 1;
			}

			if (vis[x2][y2]) break;
		}
	}

	return level[x2][y2];
}

void solve() {

	string s1, s2;
	cin >> s1 >> s2;

	reset();

	cout << bfs(s1, s2) << nline;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int t;
	cin >> t;

	while (t--) {

		solve();
	}


	return 0;
}