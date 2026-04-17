#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*

	Problem link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

	Time Complexity: O(n)
	Space Complexity: O(h)
*/


// recursive solution (DFS)........

int findDepth(TreeNode* node) {

	if (node == nullptr) return 0;

	int leftHalf =  1 + findDepth(node -> left);
	int rightHalf =  1 + findDepth(node -> right);

	return max(leftHalf, rightHalf);
}


int maxDepth(TreeNode* root) {

	return findDepth(root);
}






/*

	Time Complexity: O(n)
	Space Complexity: O(w} = O(n/2)

	because when you try to calculate the width of the tree (w) ie. the max(nodes at any level)

*/




// iterative solution (BFS)......

int findDepthRecur(TreeNode* root) {

	int height = 0;
	if (root == nullptr) return height;


	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {

		int size = q.size();
		vector<int> level;

		for (int i = 0; i < size; i++) {

			TreeNode* node = q.front();
			q.pop();

			if (node -> left != nullptr) q.push(node -> left);
			if (node -> right != nullptr) q.push(node -> right);
			level.push_back(node -> val);
		}

		if (level.size() != 0) {
			height++;
		}

	}

	return height;
}



int main() {


	return 0;
}