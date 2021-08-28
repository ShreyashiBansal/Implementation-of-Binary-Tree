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

int CalcDiameter(Node* root, int* height){
    if(root == NULL){
        return 0;
        
    }
    int lheight = 0;
    int rheight = 0;
    
    int lDiameter = CalcDiameter(root->left, &lheight);
    int rDiameter = CalcDiameter(root->right, &rheight);
    int currDiameter = lheight + rheight + 1;
    *height = max(lheight,rheight) + 1;
    
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
    int height = 0;
    cout<<CalcDiameter(root, &height);
	return 0;
}
output: 5
//time complexity : O(N)
