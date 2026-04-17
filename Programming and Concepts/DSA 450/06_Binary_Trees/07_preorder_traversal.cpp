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



void processPreorder(TreeNode* node, vector<int> &preorder) {

	if (node == nullptr) return;

	preorder.push_back(node -> val);

	processPreorder(node -> left, preorder);
	processPreorder(node -> right, preorder);
}


vector<int> preorderTraversal(TreeNode* root) {

	vector<int> preorder;
	if (root == nullptr) return preorder;

	processPreorder(root, preorder);
	return preorder;
}




vector<int> preorderTraversalIter(TreeNode* root) {

	vector<int> preorder;
	if (root == nullptr) return preorder;

	stack<TreeNode*> st;
	TreeNode* currNode = root;

	while (true) {

		if (currNode != nullptr) {

			preorder.push_back(currNode -> val);
			st.push(currNode);

			currNode = currNode -> left;
		}
		else {

			if (st.empty()) {

				break;
			}

			TreeNode* topNode = st.top();
			st.pop();

			currNode = topNode -> right;
		}
	}

	return preorder;

}









int main() {


	return 0;
}