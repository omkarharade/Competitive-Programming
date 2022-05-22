#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

template<typename T>
class Graph {

	map<T, list<T>> l;

public:

	void addEdge(T x, T y) {

		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(T src) {

		map<T, bool> visited;
		queue<T> q;

		q.push(src);
		visited[src] = true;

		while (!q.empty()) {

			T node = q.front();
			q.pop();

			cout << node << " ";

			for (auto x : l[node]) {
				if (!visited[x]) {
					q.push(x);
					visited[x] = true;
				}
			}
		}
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	Graph<int> g;

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	g.bfs(0);

	return 0;
}