#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

struct Node{
    Node *left, *right;
    int data;

    Node(int data){
        left = right = NULL;
        this -> data = data;
    }
};

void postorder(Node* root){

    if(root == NULL) return;
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";

}

void inorder(Node* root){

    if(root == NULL) return;
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(Node* root){

    if(root == NULL) return;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void levelorder(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);

    while(q.empty() == false){
        Node* curr = q.front();
        q.pop();

        cout << curr->data << " ";
        if(curr->left  != NULL) q.push(curr->left);
        if(curr->right  != NULL) q.push(curr->right);
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

    cout << "PREORDER TRAVERSAL" << nline;
    preorder(root); cout << nline;

    cout << "INORDER TRAVERSAL" << nline;
    inorder(root); cout << nline;

    cout << "POSTORDER TRAVERSAL" << nline;
    postorder(root); cout << nline;

    cout << "LEVELORDER TRAVERSAL" << nline;
    levelorder(root); cout << nline;
    
    return 0;
}