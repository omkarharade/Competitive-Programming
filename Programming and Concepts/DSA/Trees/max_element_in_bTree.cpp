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

int max_element_bTree(Node* root){

    if(root == NULL) return INT_MIN;

    return max(root->data, max(max_element_bTree(root->left), max_element_bTree(root->right)));
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

    cout << "max element  of binary tree is "<<  max_element_bTree(root) << "\n";
    
    return 0;
}