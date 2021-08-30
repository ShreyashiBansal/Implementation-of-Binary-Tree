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

Node* LCA(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == n1 || root->data == n2){
        return root;
    }
    
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
    
    if(left != NULL && right != NULL){
        return root;
    }
    if(left!=NULL){
        return left;
    }
    return right;
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
    
    int n1=6, n2=7;
    
    Node* lca = LCA(root, n1, n2);
    cout<<lca->data;
    
    return 0;
}

//output: 3
