#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


struct Node
{
	int data;
	Node* left, * right;
};


void traverse(Node* node, map<int, vector<int>> &traversalMap, int currDiagonalIndex) {

	traversalMap[currDiagonalIndex].push_back(node -> data);

	if (node -> left != nullptr) traverse(node -> left, traversalMap, currDiagonalIndex + 1);
	if (node -> right != nullptr) traverse(node -> right, traversalMap, currDiagonalIndex);

}
vector<int> diagonal(Node *root) {
	// code here

	// associate a diagonalIndex with the number
	// give same index number to the right child as the parent
	// give left child the index 1 + parent's index value
	// traverse the left subree first it says so lets do a dfs

	map<int, vector<int>> traversalMap;
	vector<int> ans;

	traverse(root, traversalMap, 0);


	for (auto it : traversalMap) {

		ans.insert(ans.end(), it.second.begin(), it.second.end());

	}

	return ans;

}

int main() {


	return 0;
}