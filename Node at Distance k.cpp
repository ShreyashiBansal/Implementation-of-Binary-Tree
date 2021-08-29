
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

//case 1 print the sub tree
void PrintSubTreeNodes(Node* root, int k){
    if(root == NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    PrintSubTreeNodes(root->left, k-1);
    PrintSubTreeNodes(root->right, k-1);
}

//case 2 print the ancestor Node
int PrintNodesAtK(Node* root, Node* target, int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        PrintSubTreeNodes(root,k);
        return 0;
    }
    int dl = PrintNodesAtK(root->left, target,k);
    if(dl!=-1){
        if(dl + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            PrintSubTreeNodes(root->right,k-dl-2);
        }
        return dl+1;
    }
    int dr = PrintNodesAtK(root->right, target,k);
    if(dr!=-1){
        if(dr + 1 == k){
            cout<<root->data<<" ";
        }
        else{
            PrintSubTreeNodes(root->left,k-dr-2);
        }
        return dr+1;
    }
}


/*
       1
      /  \
     2    3
    / 
   4  
*/

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    
    int x = PrintNodesAtK(root, root->left, 1);
    
	return 0;
}

output: 4 1
