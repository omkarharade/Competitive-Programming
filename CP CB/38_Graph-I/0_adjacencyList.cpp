#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

class Graph {
	int V;
	// array of list
	list<int> *l;

public:
	Graph(int v) {
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void printAdjList() {
		for (int i = 0; i < V; ++i)
		{
			cout << "[" << i << "] = {";
			for (auto x : l[i]) {

				cout << x << " ";
			}
			cout << "}" << nline;
		}
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	// int v, e;
	// cin >> v >> e;

	// Graph g(v);

	// for (int i = 0; i < e; ++i)
	// {
	// 	int v1, v2;
	// 	cin >> v1 >> v2;

	// 	g.addEdge(v1, v2);
	// }

	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 2);

	g.printAdjList();
	return 0;
}