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


vector<int> leftSideView(TreeNode* root) {

	vector<int> leftView;
	if (root == nullptr) return leftView;

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {

		int size = q.size();

		// here we are processing the leftmost node in the current level

		TreeNode* leftNode = q.front();
		q.pop();

		// we only store the leftmost node in the current level
		// like this here below
		leftView.push_back(leftNode->val);

		if (leftNode -> left != nullptr) q.push(leftNode -> left);
		if (leftNode -> right != nullptr) q.push(leftNode -> right);

		// lets process all the nodes except the leftmost node
		// in the current level

		for (int i = 1; i < size; i++) {

			TreeNode* node = q.front();
			q.pop();

			if (node -> left != nullptr) q.push(node -> left);
			if (node -> right != nullptr) q.push(node -> right);
		}
	}

	return leftView;

}


int main() {


	return 0;
}