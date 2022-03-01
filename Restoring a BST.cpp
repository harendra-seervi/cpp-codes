#include<iostream>
#include<bits./stdc++.h>
using namespace std;
struct node{
    public:
    node*left;
    node*right;
    int data;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void swap(node*root,int a,int b){
    if(root==NULL) return;
    if(root->data==a){
        root->data=b;
        return  ;
    }
    if(root->data==b){
        root->data=a;
        return ;
    }
    swap(root->left,a,b);
    swap(root->right,a,b);
}
vector<int>v;
void inorder(node*root){
    if(root==NULL) return ;
    inorder(root->left);
    v.push_back(root->data);
    inorder(root->right);
}
void inorder2(node*root){
    if(root==NULL) return ;
    inorder2(root->left);
    cout<<root->data<<" ";
    inorder2(root->right);
}
int main(){
    node*root=new node(3);
    root->left=new node(2);
    root->left->left=new node(1);
    root->right=new node(7);
    root->right->left=new node(5);
    root->right->left->left=new node(6);
    root->right->left->right=new node(4);
    inorder(root);
    vector<int>cp;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
        cp.push_back(v[i]);
    }
    sort(cp.begin(),cp.end());
    vector<int>ans;
    for(int i=0;i<v.size();i++){
        if(v[i]!=cp[i]){
            ans.push_back(v[i]);
        }
    }
    int a=ans[0];
    int b=ans[1];
    swap(root,a,b);
    cout<<endl;
    cout<<"new inoder after swaping:- "<<endl;
    inorder2(root);
    return 0;
}