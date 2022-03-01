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
    struct node* left;
    struct node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorder(node* root){
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int ind=0;
node* buildtree(int pre[],int in[],int st,int end,unordered_map<int,int>mp){
    if(st>end) return NULL;
    node* root=new node(pre[ind++]);
    if(st==end) return root;
    int pos=mp[root->data];
    root->left=buildtree(pre,in,st,pos-1,mp);
    root->right=buildtree(pre,in,pos+1,end,mp);
    return root;
}
vector<vector<int>>v;
void levelorder(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    vector<int>temp;
    temp.push_back(root->data);
    v.push_back(temp);
    temp.clear();
    while(q.empty()!=true){
        node* n=q.front();
        q.pop();
        if(n!=NULL){
            // temp.push_back(n->data);
            // cout<<n->data<<" ";
            if(n->left!=NULL) {
                q.push(n->left);
                temp.push_back(n->left->data);
            }
            if(n->right!=NULL) {
            q.push(n->right);
            temp.push_back(n->right->data);
            }
        }
        else if(q.empty()!=true){
            v.push_back(temp);
            temp.clear();
            q.push(NULL);
        }
    }
}
int height_bt(node* root){
    if(root==NULL) return 0;
    int left=height_bt(root->left)+1;
    int right=height_bt(root->right)+1;
    return max(left,right);
}
int sum_at_k(node* root,int k){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while(q.empty()!=true){
        node*n=q.front();
        q.pop();
        if(n!=NULL){
            if(level==k) sum+=n->data;
            if(n->left!=NULL) q.push(n->left);
            if(n->right!=NULL) q.push(n->right);
        }
        else if(q.empty()!=true){
            level++;
            q.push(NULL);
        }
    }
    return sum;
}
int  sumall(node* root){
    if(root==NULL) return 0;
    return sumall(root->left)+ sumall(root->right)+root->data;
}
int ctnode(node* root){
    if(root==NULL) return 0;
    return ctnode(root->right)+ctnode(root->left)+1;
}
int maxi=-999999;
int dia(node*root){
    if(root==NULL){
        return 0;
    }
    int left=dia(root->left);
    int right=dia(root->right);
    maxi=max(maxi,left+right+1);
    return 1+max(left,right);
}
void sumreplacemet(node*root){
    if(root==NULL) return;
    sumreplacemet(root->left);
    sumreplacemet(root->right);
    node* n=root;
    if(n->left) {
        n->data+=(n->left->data);
    }
    if(n->right){
        n->data+=(n->right->data);
    }
}
bool isbalanced(node* root){
    if(root==NULL) return true;
    if(isbalanced(root->left)==false){
        return false;
    }
    if(isbalanced(root->right)==false){
        return false;
    }
    int lh=height_bt(root->left);
    int rh=height_bt(root->right);
    int f=lh-rh;
    if(f<0){
        f=f*(-1);
    }
    if(f<=1){
        return true;
    }
    else{
        return false;
    }
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
    int st=0;
    node*root=buildtree(pre,in,0,n-1,mp);
    if(isbalanced(root)){
        cout<<"Balanced tree"<<endl;
    }
    else{
        cout<<"Unbalanced tree"<<endl;
    }
return 0;
}