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

		Problem Link: https://leetcode.com/problems/binary-tree-level-order-traversal/


	    1. push the root into the queue

	    2. run a while loop to process the queue

	    3. process all the elements that are present at the time
	       of entering / re-entering the while loop
	       to know the no. of elements to process we pre-calculate the size of queue initially

	    4. take the elements out of the queue one by one and push their respective left and right
	       child nodes inside the queue

	    5. after one element is processed and its child are pushed in the queue, its work is done
	       and we push the element with the elements who are processed for that current level

	    6. once all the elements of a specific level are processed we push the level array to final answer array

	    7. while loop continues and the process goes on

	    8. finally we get an array of arrays containing elements from the specific levels
	*/

	vector<vector<int>> levelOrder(TreeNode* root) {

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

		return ans;
	}
};



int main() {


	return 0;
}