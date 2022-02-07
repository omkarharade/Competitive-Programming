#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

const int N = 1e5 + 10;
vector<int> g[N];

int depth[N], height[N];

void dfs(int vertex, int parent = 0) {

	/*
	take action on vertex after
	entering the vertex
	*/


	for (auto child : g[vertex]) {

		/*
		take action on child before
		entering the child node
		*/

		if (child == parent) continue;

		depth[child] = depth[vertex] + 1;

		dfs(child, vertex);

		height[vertex] = max(height[vertex], height[child] + 1);
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

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}


	dfs(1);


	cout << nline;
	for (int i = 1; i <= n; ++i)
	{
		cout << depth[i] << " " <<  height[i] << nline;
	}


	return 0;
}