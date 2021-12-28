#include <bits/stdc++.h>
using namespace std;
#define nline "/n"

struct Node
{
    Node *left, *right;
    int data;

    Node(int data)
    {
        left = right = NULL;
        this->data = data;
    }
};
// Note: iterative method is remaining to implement
void leftview_recur_v1(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    if (root->left != NULL && root->right != NULL)
        leftview_recur_v1(root->left);
    else if (root->left != NULL and root->right == NULL)
        leftview_recur_v1(root->left);
    else if (root->left == NULL and root->right != NULL)
        leftview_recur_v1(root->right);
    else
        return;
}

int maxLevel = 0;
void leftview_recur_v2(Node *root, int level)
{
    if (root == NULL)
        return;

    if (maxLevel < level)
    {
        cout << root->data << " ";
        maxLevel = level;
    }
    leftview_recur_v2(root->left, level + 1);
    leftview_recur_v2(root->right, level + 1);
}

int main()
{

    // Contrust the Tree
    //      30
    //      / \
    //    20   50         ans: 30 50 60 10
    //         /
    //        60
    //         \
    //         10

    struct Node *root = new Node(30);
    root->left = new Node(20);
    root->right = new Node(50);
    root->right->left = new Node(60);
    root->right->left->right = new Node(10);

    cout << "left view of binary tree is\n";
    leftview_recur_v1(root);
    cout << "\n";
    leftview_recur_v2(root, 1);
    cout << "\n";

    return 0;
}