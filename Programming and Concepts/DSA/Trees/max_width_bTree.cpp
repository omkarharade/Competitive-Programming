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

int maxWidth(Node* root){
    if(root == NULL) return 0;

    queue<Node*> q;
    q.push(root);
    int res = 0;
    while(q.empty() == false){

        int count = q.size();
        res = max(res,count);

        for (int i = 0; i < count; i++)
        {
        Node* curr = q.front();
        q.pop();

        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
            
        }
        
    }

    return res;
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

    root->right->left    = new Node(6);
    root->right->right    = new Node(7);


    cout << "max width of the binary tree is\n" << maxWidth(root) << nline;


    
    return 0;
}