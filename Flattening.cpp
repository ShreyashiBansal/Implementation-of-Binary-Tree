// Given a binary tree, flatten it into linked list in place. After flattening, left of each node should point to null and right should contain the next node in preorder sequence.

/*
Algorithm:
 1) Recursively Faltten the left and right subtree.
 2) Store the left tail and right tail.
 3) Store right subtree as 'temp' and make left subtree as right subtree.
 4) Join right subtree with left tail.
 5) Return right tail.
 
*/

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void flatten(Node* root){
    if(root != NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    
    if(root->left != NULL){
        flatten(root->left);
        
        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        Node* t = root->right;
        while(t->right != NULL){
            t = t->right;
        }
        t->right = temp;
    }
    flatten(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
/*
       1
      /  \
     2    3
    / \  / \
   4  5  6  7
*/

int main(){
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left  = new Node(6);
    root->right->right = new Node(7);
    
    preorder(root);
    flatten(root);
    cout<<endl;
    preorder(root);
    
    return 0;
}
Output:
1 2 4 5 3 6 7 
1 2 4 5 3 6 7
