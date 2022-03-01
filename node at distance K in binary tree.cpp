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

void stackFlatten(node*root){
    stack<node*>st;
    st.push(root);
    while(st.empty()!=true){
        node*n=st.top();
        st.pop();
        if(n->right) st.push(n->right);
        if(n->left) st.push(n->left);
        if(st.empty()!=true){
            n->right=st.top();
            n->left=NULL;
        }
    }
}

node*pre=NULL;
void flatten(node*root){
    if(root==NULL){
        return;
    }
    flatten(root->right);
    flatten(root->left);
    root->right=pre;
    root->left=NULL;
    pre=root;
}
void psubtree(node*root){

}
node*fnode(node*root,int a,int h){
    if(root==NULL) return NULL;
    if(root->data==a){
        return root;
    }
    node*ln=fnode(root->left,a,h+1);
    node*rn=fnode(root->right,a,h+1);
    if(ln!=NULL) return ln;
    return rn;
}

void pnodeatk(node*root,int h,int k){
    if(root==NULL) return ;
    if(h==k){
        cout<<root->data<<" ";
    }
    pnodeatk(root->left,h+1,k);
    pnodeatk(root->right,h+1,k);
}
int main(){
    node*root=new node(1);
    root->right=new node(2);
    root->left=new node(5);
    root->left->left= new node(6);
    root->left->left->right= new node(7);
    root->left->left->right->right= new node(9);
    root->left->left->right->left=new node(8);
    root->right->right= new node(4);
    root->right->left=new node(3);
    node*n=fnode(root,5,0); // CASE -1
    pnodeatk(n,0,3);
    // CASE -2 (BFS lagayenge baad me easy ho jayega);
    // after lerning graphs then i will able to do;
return 0;
}