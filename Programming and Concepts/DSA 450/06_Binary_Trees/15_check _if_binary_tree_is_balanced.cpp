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


pair<int, bool> getHeightAndBalancedStatus(TreeNode* node) {

	if (node == nullptr) return {0, true};

	pair<int, bool> leftStatus = getHeightAndBalancedStatus( node -> left);
	pair<int, bool> rightStatus = getHeightAndBalancedStatus( node -> right);

	// if any one of the subtree of the current node is not balanced
	// return balanced status as false immediately
	if (!leftStatus.second || !rightStatus.second) return {0, false};


	bool balancedStatus = abs(leftStatus.first - rightStatus.first) <= 1 ? true : false;
	int maxDepth = 1 + max(leftStatus.first, rightStatus.first);

	return {maxDepth, balancedStatus};
}


bool isBalanced(TreeNode* root) {

	pair<int, bool> status = getHeightAndBalancedStatus(root);
	return status.second;
}



int main() {


	return 0;
}