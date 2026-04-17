#include <bits/stdc++.h>
using namespace std;
#define nline "\n";



class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}
};


vector<vector<int>> verticalOrderUsingMap(Node *root) {
	// code here
	// Time: O(nlogn)
	// Space: O(n);

	vector<vector<int>> ans;
	queue<pair<int, Node*>> q;
	map<int, vector<int>> traversalMap;

	q.push({0, root});

	while (!q.empty()) {

		int size = q.size();

		for (int i = 0; i < size; i++) {

			pair<int, Node*> frontPair = q.front();
			q.pop();

			int currHIndex = frontPair.first;
			Node* node = frontPair.second;

			traversalMap[currHIndex].push_back(node->data);

			if (node->left != nullptr) {

				q.push({currHIndex - 1, node->left});
			}

			if (node->right != nullptr) {

				q.push({currHIndex + 1, node->right});
			}
		}

	}

	for (auto it : traversalMap) {
		ans.push_back(it.second);
	}

	return ans;
}



vector<vector<int>> verticalOrderUsingUnorderedMap(Node *root) {
	// code here
	// Time: O(n)
	// Space: O(n)

	vector<vector<int>> ans;
	queue<pair<int, Node*>> q;
	unordered_map<int, vector<int>> traversalMap;

	int minHIndex = 0, maxHIndex = 0;
	q.push({0, root});


	while (!q.empty()) {

		int size = q.size();

		for (int i = 0; i < size; i++) {

			pair<int, Node*> frontPair = q.front();
			q.pop();

			int currHIndex = frontPair.first;
			Node* node = frontPair.second;

			traversalMap[currHIndex].push_back(node->data);
			minHIndex = min(minHIndex, currHIndex);
			maxHIndex = max(maxHIndex, currHIndex);



			if (node->left != nullptr) {

				q.push({currHIndex - 1, node->left});
			}

			if (node->right != nullptr) {

				q.push({currHIndex + 1, node->right});
			}
		}

	}

	for (int i = minHIndex; i <= maxHIndex; i++) {

		ans.push_back(traversalMap[i]);
	}

	return ans;
}




int main() {


	return 0;
}