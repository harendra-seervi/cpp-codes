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
int ind;
node* buildTree(int post[],int in[],int st,int end,unordered_map<int,int>mp){
    if(st>end) return NULL;
    node* root = new node(post[ind]);
    ind--;
    if(st==end) return root;
    int mid=mp[root->data];
    root->right=buildTree(post,in,mid+1,end,mp);
    root->left=buildTree(post,in,st,mid-1,mp);
    return root;
}
void levelOrderTraversal(node* root){
    if(root==NULL) return ;
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(q.empty()!=true){
        node* n=q.front();
        q.pop();
        if(n!=NULL){
            cout<<n->data<<" ";
            if(n->left!=NULL) q.push(n->left);
            if(n->right!=NULL) q.push(n->right);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}
int main(){
    int n;
    cin>>n;
    ind=n-1;
    int post[n];
    int in[n];
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp.insert({in[i],i});
    }
    node*newroot=buildTree(post,in,0,n-1,mp);
    levelOrderTraversal(newroot);
    
return 0;
}