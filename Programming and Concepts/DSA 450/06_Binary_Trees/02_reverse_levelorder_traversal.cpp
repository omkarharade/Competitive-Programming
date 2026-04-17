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




class Solution {
public:


	/*
		problem link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/


		Just reverse the level order traversal final array

	*/


	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> q;

		if (root == nullptr) return ans;

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
				ans.push_back(level);
			}

		}

		int ansSize = ans.size();
		int left = 0, right = ansSize - 1;


		while (left < right) {

			vector<int> leftArray = ans[left];
			vector<int> rightArray = ans[right];

			ans[left] = rightArray;
			ans[right] = leftArray;

			left++;
			right--;
		}

		return ans;
	}
};


int main() {


	return 0;
}