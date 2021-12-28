#include <bits/stdc++.h>
using namespace std;
#define nline "\n";
struct Node{
    Node *left, *right;
    int data;

    Node(int data){
        left = right = NULL;
        this -> data = data;
    }
};

void printKDist(Node *root, int k){

    if(root == NULL) return;
    else if(k == 0) cout << root -> data << " ";
    else {
        printKDist(root->left, k-1);
        printKDist(root->right, k-1);
    }
}


int main() {

    // Contrust the Tree
    //      1
    //     /  \
    //    2    3
    //   / \    
    //  4   5

    struct Node *root = new Node(1);
    root->left    = new Node(2);
    root->right    = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5); 

    printKDist(root, 2);

    
    return 0;
}