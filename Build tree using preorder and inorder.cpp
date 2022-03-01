//preorder -> 1 2 4 5 3 6 7 
//inorder  -> 4 2 5 1 6 3 7

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

int ind=0;
node* buildTree(int pre[],int in[],int st,int end,unordered_map<int,int>mp){
    if(st>end) return NULL;
    node* root = new node(pre[ind++]);
    if(st==end) return root;
    int mid=mp[root->data];
    root->left=buildTree(pre,in,st,mid-1,mp);
    root->right=buildTree(pre,in,mid+1,end,mp);
    return root;
}           

int main(){
    int n;
    cin>>n;
    int pre[n];
    int in[n];
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp.insert({in[i],i});
    }
    node*newroot=buildTree(pre,in,0,n-1,mp);
    preorder(newroot);
    
return 0;
}