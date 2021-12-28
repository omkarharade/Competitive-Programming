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

bool is_child_sum(Node* root){

    if(root == NULL) return true;
    if(root->left == NULL and root->right == NULL) return true;

    int sum = 0;

    if(root->left != NULL) sum += root->left->data;
    if(root->right != NULL) sum += root->right->data;

    return (root->data == sum) and (is_child_sum(root->left)) and( is_child_sum(root->right));

}

int main() {

    // Contrust the Tree
    //      10
    //     /  \
    //    4    6
    //   / \   / 
    //  1   3 6   

    struct Node *root = new Node(10);
    root->left    = new Node(4);
    root->right    = new Node(6);

    root->left->left = new Node(1);
    root->left->right = new Node(3); 

    root->right->left = new Node(6);

    if(is_child_sum(root)) cout << "True" << "\n";
    else cout << "False" << "\n";
    
    return 0;
}