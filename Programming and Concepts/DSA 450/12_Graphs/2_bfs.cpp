#include <bits/stdc++.h>
using namespace std;
#define nline "\n";



void bfs(vector<int> g[], vector<bool>& vis, int source) {

	queue<int> q;

	q.push(source);
	vis[source] = 1;

	while (!q.empty()) {

		int current_v = q.front();
		q.pop();

		cout << current_v << " ";

		// put all the child nodes for the current vertex inside queue

		for (int child : g[current_v]) {

			if (!vis[child]) {  // if child is not visited previously then consider it

				vis[child] = 1;
				q.push(child);

			}
		}

	}
	cout << nline;
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

		bfs(g, visited, 1);
	}


	return 0;
}