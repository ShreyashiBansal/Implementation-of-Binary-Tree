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
Node* BuildTree(int postorder[], int inorder[], int start, int end){
    static int idx = 4;
    if(start>end){
        return NULL;
    }
    int curr = postorder[idx];
    idx--;
    Node* node = new Node(curr);
    if(start == end) return node;
    int pos = search(inorder, start, end, curr);
    node->right = BuildTree(postorder, inorder, pos+1, end);
    node->left = BuildTree(postorder, inorder, start, pos-1);
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
    int postorder[] = {4,2,5,3,1};
    int inorder[] = {4,2,1,5,3};
    int n = sizeof(postorder)/sizeof(postorder[0]);
    
    Node* root = BuildTree(postorder,inorder,0,n-1);
    inorderprint(root);
    return 0;
}
//output: 4 2 1 5 3 
