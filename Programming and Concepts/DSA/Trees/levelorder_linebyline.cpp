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

void levelorder_line_v1(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size() > 1){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL) {
            cout << "\n";
            q.push(NULL);
            continue;
        }

        cout << curr->data << " ";
        if(curr->left  != NULL) q.push(curr->left);
        if(curr->right  != NULL) q.push(curr->right);
    }
}

void levelorder_line_v2(Node* root){

    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(q.empty() == false){

        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right); 
        }
        cout << "\n";
    }
}

int main() {

    // Contrust the Tree
    //      1
    //     /  \
    //    2    3
    //   / \   / \
    //  4   5 6   7

    struct Node *root = new Node(1);
    root->left    = new Node(2);
    root->right    = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5); 

    root->right->left = new Node(6);
    root->right->right = new Node(7); 

    levelorder_line_v1(root); 
    cout << "\n";
    levelorder_line_v2(root);
    
    return 0;
}