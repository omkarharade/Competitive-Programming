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



/*


	This is the recursive way to process inorder traversal
	of the binary tree

*/

void processInorder(TreeNode* node, vector<int> &inorder) {

	if (node == nullptr) return;

	processInorder(node -> left, inorder);
	inorder.push_back(node -> val);
	processInorder(node -> right, inorder);

}



vector<int> inorderTraversal(TreeNode* root) {
	vector<int> inorder;
	processInorder(root, inorder);
	return inorder;
}




/*

	Iterative approach goes as follows
	we try to mimick the dfs approach just as recursive flow but using stack

	we try to reach to the leftmost node, in the process adding the current nodes
	till we reach the null pointer

	then we remove the top element from the stack which at that point is the
	leftmost node of the tree

	we add the value of popped node to  inorder array and try to process the right child of the
	popped node

	and the loop goes on ......

*/

vector<int> inorderTraversalIter(TreeNode* root) {

	vector<int> inorder;

	if (root == nullptr) return inorder;

	stack<TreeNode*> st;
	TreeNode* currNode = root;



	while (true) {

		if (currNode != nullptr) {

			st.push(currNode);

			currNode = currNode -> left;
		}
		else {

			if (st.empty()) {

				break;
			}

			TreeNode* topNode = st.top();
			st.pop();

			inorder.push_back(topNode -> val);
			currNode = topNode -> right;
		}
	}


	return inorder;


}

int main() {


	return 0;
}