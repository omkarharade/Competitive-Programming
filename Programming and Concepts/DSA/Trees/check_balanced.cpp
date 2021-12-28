#include <bits/stdc++.h>
using namespace std;
#define nline "\n";
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

int height(Node* root){

    if(root == NULL) return -1;

    return max(height(root -> left), height(root -> right)) +1;
}

bool is_balanced_v1(Node *root)
{
    // naive O(N^2)
    if (root == NULL)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);
 
    return(abs(lh-rh) <= 1 and is_balanced_v1(root->left) and is_balanced_v1(root->right));
}

int is_balanced_v2(Node* root){

    if(root == NULL) return 0;

    int lh = is_balanced_v2(root->left);
    if(lh == -1) return -1;
    int rh = is_balanced_v2(root->right);
    if(rh == -1) return -1;

    if(abs(lh-rh) > 1) return -1;
    else return max(lh, rh) +1; 
}

int main()
{

    // Contrust the Tree
    //      1
    //     /  \
    //    2    3     ans : tree is not balanced 
    //   / \    
    //  4   5
    //      /
    //     20

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(20);

    cout << "check if tree is balanced\n";

    if(is_balanced_v1(root)) cout << "True" << "\n";
    else cout << "False" << "\n";

    if(is_balanced_v2(root) == -1) cout << "Tree is not balanced" << "\n";
    else cout << "Tree is balanced" << "\n";


    return 0;
}