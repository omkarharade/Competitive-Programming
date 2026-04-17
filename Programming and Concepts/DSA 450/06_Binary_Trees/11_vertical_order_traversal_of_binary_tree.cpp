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


vector<vector<int>> verticalTraversal(TreeNode* root) {

	vector<vector<int>> ans;
	queue<pair<int, TreeNode*>> q;
	map<int, vector<int>> traversalMap;

	q.push({0, root});

	while (!q.empty()) {

		int size = q.size();
		map<int, vector<int>> tempTree;

		for (int i = 0; i < size; i++) {

			pair<int, TreeNode*> frontPair = q.front();
			q.pop();

			int currHIndex = frontPair.first;
			TreeNode* node = frontPair.second;

			tempTree[currHIndex].push_back(node->val);

			if (node->left != nullptr) {

				q.push({currHIndex - 1, node->left});
			}

			if (node->right != nullptr) {

				q.push({currHIndex + 1, node->right});
			}
		}

		for (auto it : tempTree) {

			vector<int> arr = it.second;
			int hIndex = it.first;

			sort(arr.begin(), arr.end());
			traversalMap[hIndex].insert(traversalMap[hIndex].end(), arr.begin(), arr.end());
		}
	}

	for (auto it : traversalMap) {
		ans.push_back(it.second);
	}

	return ans;
}
};

int main() {


	return 0;
}