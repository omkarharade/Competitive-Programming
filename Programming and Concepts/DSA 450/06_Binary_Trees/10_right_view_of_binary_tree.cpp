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


vector<int> rightSideView(TreeNode* root) {

	vector<int> rightView;
	if (root == nullptr) return rightView;

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {

		int size = q.size();


		// lets process all the nodes except the rightmost node
		// in the current level

		for (int i = 0; i < size - 1; i++) {

			TreeNode* node = q.front();
			q.pop();

			if (node -> left != nullptr) q.push(node -> left);
			if (node -> right != nullptr) q.push(node -> right);
		}


		// here we are processing the righmost node in the current level

		TreeNode* rightNode = q.front();
		q.pop();

		// we only store the rightmost node in the current level
		// like this here below
		rightView.push_back(rightNode->val);

		if (rightNode -> left != nullptr) q.push(rightNode -> left);
		if (rightNode -> right != nullptr) q.push(rightNode -> right);
	}

	return rightView;

}


int main() {


	return 0;
}