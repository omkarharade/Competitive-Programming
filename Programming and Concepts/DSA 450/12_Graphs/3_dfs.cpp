#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

void dfs(vector<int> g[], vector<bool>& vis, int vertex, int parent = -1) {

	/*
	take action on vertex after
	entering the vertex
	*/

	for (int child : g[vertex]) {

		/*
		take action on child before
		entering the child node
		*/


		if (child == vertex) continue;

		dfs(g, vis, child, vertex);

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

	int n, m; // n - no. of nodes and m - no. of edges
	cin >> n >> m;

	vector<int> g[n + 1];
	vector<bool> visited(n + 1, 0);


	for (int i = 0; i < m; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;

		g[v1].push_back(v2);
		g[v2].push_back(v1);

		dfs(g, visited, 1);
	}


	return 0;
}