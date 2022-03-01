//7
//preorder -> 1 2 4 5 3 6 7 
//inorder  -> 4 2 5 1 6 3 7
//postorder-> 4 5 2 6 7 3 1
//   
//
//                 1
//                /  \
//               2    3
//             / \   / \
//            4  5  6   7
//
//

#include<bits/stdc++.h>
using namespace std;
struct node{
    public:
    int data;
    struct node*left;
    struct node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorder(struct node*root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    struct node*root =new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
return 0;
}