#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val){
        data  = val;
        left = NULL;
        right = NULL;
    }
};

int CalcHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    int lh = CalcHeight(root->left);
    int rh = CalcHeight(root->right);
    
    return max(lh,rh) + 1;
}

bool isBalanced(Node* root){
    if(root == NULL)
        return true;
    
    if(isBalanced(root->left) == false)
        return false;
    
    if(isBalanced(root->right) == false)
        return false;
    
    
    int lh = CalcHeight(root->left);
    int rh = CalcHeight(root->right);
    if(abs(lh-rh)<=1)
        return true;
    else
        return false;
}
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    if(isBalanced(root))
      cout<<"Tree is Balanced";
    else
      cout<<"Tree is Not Balanced";
	return 0;
}
//output: Tree is Balanced
