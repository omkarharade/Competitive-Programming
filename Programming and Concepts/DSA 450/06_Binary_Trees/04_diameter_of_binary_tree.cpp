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
	problem link: https://leetcode.com/problems/diameter-of-binary-tree/description/


	Naive approach : Calculating height of left and right subtree for each node
	individually 

	Time Complexity: O(N*N)
	Space Complexity: O(h) where h is the height of the binary tree

	
	Efficient Solution : (This solution)
	max of the summation of height from left and right subtree of every nodes
	give us the diameter of the binary tree

	Time Complexity: O(n)
	Space Complexity: O(h) where h is the height of the binary tree

*/


int getHeight(TreeNode* root, int &diameter) {

	if (root == nullptr) return 0;

	int maxFromLeft = getHeight(root -> left, diameter);
	int maxFromRight = getHeight(root -> right, diameter);

	diameter = max(diameter, maxFromLeft + maxFromRight);

	return 1 + max(maxFromLeft, maxFromRight);
}


int diameterOfBinaryTree(TreeNode* root) {

	int diameter = 0;
	getHeight(root, diameter);
	return diameter;

}


int main() {


	return 0;
}