#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

	vector<vector<int>> zigzag;
	if (root == nullptr) return zigzag;

	queue<TreeNode*> q;
	int currLevel = 1;

	q.push(root);

	while (!q.empty()) {

		int size = q.size();
		vector<int> nodesStore;

		for (int i = 0; i < size; i++) {

			TreeNode* node = q.front();
			q.pop();

			nodesStore.push_back(node -> val);

			if (node -> left != nullptr) {
				q.push(node -> left);
			}

			if (node -> right != nullptr) {
				q.push(node -> right);
			}

		}

		// if the current level is even
		// reverse the traversed nodes

		if (currLevel % 2 == 0) {
			reverse(nodesStore.begin(), nodesStore.end());
		}

		zigzag.push_back(nodesStore);
		currLevel++;
	}

	return zigzag;
}


int main() {


	return 0;
}