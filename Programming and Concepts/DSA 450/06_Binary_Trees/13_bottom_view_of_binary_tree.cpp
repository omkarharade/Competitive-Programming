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
		left = nullptr;
		right = nullptr;
	}
};


vector<int> bottomView(Node *root) {
	// code here

	vector<int> ans;
	queue<pair<int, Node*>> q;
	map<int, int> traversalMap;

	q.push({0, root});

	while (!q.empty()) {

		int size = q.size();

		for (int i = 0; i < size; i++) {

			pair<int, Node*> frontPair = q.front();
			q.pop();

			int currHIndex = frontPair.first;
			Node* node = frontPair.second;


			// keep updating the elements for the respective horizontal index
			// as we progress through the level order traversal

			traversalMap[currHIndex] = node -> data;

			// check if there is a left child, if yes then add it
			if (node->left != nullptr) {

				q.push({currHIndex - 1, node->left});
			}

			// check if there is a right child, if yes then add it
			if (node->right != nullptr) {

				q.push({currHIndex + 1, node->right});
			}
		}

	}

	// add the top view values for each respective horizontal indexes
	// into the final array

	for (auto it : traversalMap) {
		ans.push_back(it.second);
	}

	return ans;
}



int main() {


	return 0;
}