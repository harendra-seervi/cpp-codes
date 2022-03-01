#include<bits/stdc++.h>
using namespace std;
struct node{
    public:
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void levelwise(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(q.empty()!=true){
        node*n=q.front();
        q.pop();
        if(n!=NULL){
            cout<<n->data<<" ";
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        else if(q.empty()!=true){
            q.push(NULL);
            cout<<endl;
        }
    }
}

node*lca(node*root,int n1,int n2){
    if(root==NULL) return NULL;
    if(root->data==n1 || root->data==n2) return root;
    node*l=lca(root->left,n1,n2);
    node*r=lca(root->right,n1,n2);
    if(l && r) return root;
    if(l) return l;
    else return r;
}


int height(node*root){
    if(root==NULL) return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}
int ma;
int diameter(node*root){
    if(root==NULL) return 0;
    int lh=diameter(root->left);
    int rh=diameter(root->right);
    ma=max(ma,(lh+rh+1));
    return max(lh,rh)+1;
}

int sumreplacement(node*root){
    if(root==NULL) return 0;
    int ln=sumreplacement(root->left);
    int rn=sumreplacement(root->right);
    root->data=root->data+(ln+rn);
    return root->data;

}



bool check=true;

int balanced(node*root){
    if(root==NULL) return 0;
    int lh=balanced(root->left);
    int rh=balanced(root->right);
    int f=lh-rh;
    if(f<0) f=f*(-1);
    if(f>1) check=false;
    return max(lh,rh)+1;
}


int dh(node*root,int n1,int n2){
    if(root==NULL) return 0;
    if((root!=NULL ) && (root->data==n1 || root->data==n2)) return 1;
    int l=dh(root->left,n1,n2);
    int r=dh(root->right,n1,n2);
    return max(l,r)+1;
}

node*pre=NULL;
void flattenRecursive(node*root){
    if(root==NULL) return ;
    flattenRecursive(root->right);
    flattenRecursive(root->left);
    root->right=pre;
    root->left=NULL;
    pre=root;
}

void flatteniter(node*root){
    stack<node*>s;
    s.push(root);
    while(s.empty()!=true){
        node*curr=s.top();
        s.pop();
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
        if(!s.empty()){
            curr->right=s.top();
        }
        curr->left=NULL;
    }
}

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right=new node(3);
    root->right->right=new node(7);
    root->right->right->right=new node(9);
    root->right->left=new node(6);
    flatteniter(root);
    levelwise(root);
return 0;
}