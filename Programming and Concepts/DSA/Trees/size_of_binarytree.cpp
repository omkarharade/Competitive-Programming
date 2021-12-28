#include <bits/stdc++.h>
using namespace std;
#define nline "/n"

struct Node{
    Node *left, *right;
    int data;

    Node(int data){
        left = right = NULL;
        this -> data = data;
    }
};

int size_of_bTree(Node* root){

    if(root == NULL) return 0;

    return (size_of_bTree(root->left) + size_of_bTree(root->right) + 1);
}

int main() {

    // Contrust the Tree
    //      1
    //     /  \
    //    2    3
    //   / \   / 
    //  4   5 6   

    struct Node *root = new Node(1);
    root->left    = new Node(2);
    root->right    = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5); 

    root->right->left = new Node(6);

    cout << "size of binary tree is "<<  size_of_bTree(root) << "\n";
    
    return 0;
}