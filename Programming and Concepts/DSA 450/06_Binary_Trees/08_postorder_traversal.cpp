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


void processPostorder(TreeNode* node, vector<int> &postorder) {

	if (node == nullptr) return;

	processPostorder(node -> left, postorder);
	processPostorder(node -> right, postorder);
	postorder.push_back(node -> val);

}


vector<int> postorderTraversal(TreeNode* root) {

	vector<int> postorder;
	processPostorder(root, postorder);
	return postorder;

}

int main() {


	return 0;
}