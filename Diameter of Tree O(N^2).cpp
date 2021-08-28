#include <iostream>
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

int CalcDiameter(Node* root){
    if(root == NULL){
        return 0;
        
    }
    int lheight = CalcHeight(root->left);
    int rheight = CalcHeight(root->right);
    int currDiameter = lheight + rheight + 1;
    
    int lDiameter = CalcDiameter(root->left);
    int rDiameter = CalcDiameter(root->right);
    
    return max(currDiameter, max(lDiameter, rDiameter));
    
}
/*
       1
      /  \
     2    3
    / \  / \
   4  5  6  7
*/
int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<CalcDiameter(root);
	return 0;
}
//output: 5
// Time Complexity : O(N^2)
