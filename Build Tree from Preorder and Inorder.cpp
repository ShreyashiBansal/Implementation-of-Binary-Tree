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

void inorderprint(Node* root){
    if(root == NULL){
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}

int search(int inorder[], int start, int end, int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i] == curr){
            return i;
        }
    }
    return -1;
}
Node* BuildTree(int preorder[], int inorder[], int start, int end){
    static int idx = 0;
    if(start>end){
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    Node* node = new Node(curr);
    if(start == end) return node;
    int pos = search(inorder, start, end, curr);
    node->left = BuildTree(preorder, inorder, start, pos-1);
    node->right = BuildTree(preorder, inorder, pos+1, end);
    return node;
}

/*
       1
      /  \
     2    3
    / \  / \
   4  5  6  7
*/

int main(){
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};
    int n = sizeof(preorder)/sizeof(preorder[0]);
    
    Node* root = BuildTree(preorder,inorder,0,n-1);
    inorderprint(root);
    return 0;
}
//output: 4 2 1 5 3 
