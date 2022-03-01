#include<bits/stdc++.h>
using namespace std;
class node{
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

void preorder(node*root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node*root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node*root){
    if(root==NULL) return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

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
        else if(n==NULL && q.empty()!=true){
            q.push(NULL);
            cout<<endl;
        }
    }
}
int ind=0;
node* buildFromPre(int pre[],int in[],int st,int end,unordered_map<int,int>mp){
    if(st>end){
        return NULL;
    }
    node*root=new node(pre[ind++]);
    if(st==end) return root;
    int mid=mp[root->data];
    root->left=buildFromPre(pre,in,st,mid-1,mp);
    root->right=buildFromPre(pre,in,mid+1,end,mp);
    return root;
}

int height(node*root){
    if(root==NULL) return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}

int maxdia=0;
int balanced(node*root,bool &check){
    if(root==NULL) return 0;
    int lh=balanced(root->left,check);
    int rh=balanced(root->right,check);
    if(lh-rh>1){
        check=false;
    }
    return max(lh,rh)+1;
}
int diameter(node*root){
    if(root==NULL) return 0;
    int ld=diameter(root->left);
    int rd=diameter(root->right);
    maxdia=max(ld+rd+1,maxdia);
    return max(ld,rd)+1;
}

int  sumreplacement(node*root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL){ 
        return root->data;
    }
    int ls=sumreplacement(root->left);
    int rs=sumreplacement(root->right);
    root->data=ls+rs+root->data;
    return root->data;
}

node*lca(node*root,int a,int b){
    if(root==NULL) return NULL;
    if(root->data==a || root->data== b){
        return root;
    }
    node*ln=lca(root->left,a,b);
    node*rn=lca(root->right,a,b);
    if(ln!=NULL && rn!=NULL){
        return root;
    }
    if(ln) return ln;
    return rn;
}

int heightOfGivenNode(node*root,int a){
    if(root==NULL) return -1;
    if(root->data==a){
        return 0;
    }
    int lh=heightOfGivenNode(root->left,a);
    int rh=heightOfGivenNode(root->right,a);
    if(lh!=-1 || rh!=-1) return max(lh,rh)+1;
    return -1;
}

int distancebwtwonode(node*root,int a,int b){
    node*lcanode=lca(root,a,b);
    int final= heightOfGivenNode(lcanode,a)+heightOfGivenNode(lcanode,b);
    cout<<lcanode->data<<endl;
    return final;
}

int maxSumPath(node*root){
    if(root==NULL){
        return 0;
    }
    int mls=maxSumPath(root->left);
    int mrs=maxSumPath(root->right);
    int orr=root->data;
    int ils=root->data+mls;
    int irs=root->data+mrs;
    return max({orr,ils,irs,mls+mrs+root->data,0});
}

int main(){
    node*root=new node(-1);
    root->left=new node(-2);
    root->right=new node(-3);
    root->right->right=new node(-7);
    root->right->left=new node(6);
    root->left->left=new node(-4);
    root->left->right=new node(-5);
    cout<<maxSumPath(root)<<endl;
return 0;
}