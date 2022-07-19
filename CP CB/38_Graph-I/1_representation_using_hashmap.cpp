#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

class Graph {

	unordered_map<string, list<pair<string, int>>> l;

public:

	void addEdge(string x, string y, bool biDir, int wt) {

		l[x].push_back(make_pair(y, wt));

		if (biDir) l[y].push_back(make_pair(x, wt));
	}

	void printAdjList() {

		for (auto li : l) {
			cout << li.first << " -> {";
			for (auto x : li.second) {

				cout << "(" <<  x.first << "," << x.second << "), ";
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

	Graph g;

	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "C", true, 10);
	g.addEdge("C", "D", true, 40);
	g.addEdge("A", "D", true, 50);

	g.printAdjList();


	return 0;
}