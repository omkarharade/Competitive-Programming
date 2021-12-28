#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

void dfs(int vertex) {

	/*
	take action on vertex after
	entering the vertex
	*/

	vis[vertex] = 1;

	for (auto child : g[vertex]) {

		if (vis[child]) continue;

		/*
		take action on child before
		entering the child node
		*/


		dfs(child);

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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n, e;
	cin >> n >> e;

	for (int i = 0; i < e; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;

		g[v1].push_back(v2);
		g[v2].push_back(v1);

	}

	int cnt = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (vis[i]) continue;

		dfs(i);
		cnt++;
	}

	cout << cnt << nline;

	return 0;
}