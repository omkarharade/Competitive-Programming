#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

const int N = 1e5 + 10;
vector<int> g[N];
int par[N];

vector<int> getPath(int v) {

	vector<int> ans;
	while (v != -1) {

		v = par[v];
		ans.push_back(v);
	}

	reverse(ans.begin(), ans.end());
	return ans;
}

void dfs(int vertex, int parent = -1) {

	/*
	take action on vertex after
	entering the vertex
	*/

	par[vertex] = parent;


	for (auto child : g[vertex]) {

		/*
		take action on child before
		entering the child node
		*/

		if (child == parent) continue;

		dfs(child, vertex);

		/*
		take action on child after
		exiting the child node
		*/
	}

	/*
	take action on vertex before
	exiting the vertex
	*/

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int v;
	cin >> v;

	for (int i = 0; i < v - 1; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	dfs(1);

	int x, y; // vertices whos ancestor is to be found
	cin >> x >> y;

	vector<int> path1 = getPath(x);
	vector<int> path2 = getPath(y);

	int minLen = min(path1.size(), path2.size());
	int ans = -1;

	for (int i = 0; i < minLen; ++i)
	{
		if (path1[i] == path2[i])
			ans = path1[i];
		else
			break;
	}

	cout << ans << nline;
	return 0;
}