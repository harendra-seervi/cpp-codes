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
vector<vector<int>>ans;
void levelwise(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    vector<int>v;
    v.push_back(root->data);
    ans.push_back(v);
    v.clear();
    while(q.empty()!=true){
        node*n=q.front();
        q.pop();
        if(n!=NULL){
            if(n->left){
                 q.push(n->left);
                 v.push_back(n->left->data);
            }
            if(n->right){
             q.push(n->right);
             v.push_back(n->right->data);
            }
        }
        else if(q.empty()!=true){
            q.push(NULL);
            ans.push_back(v);
            v.clear();
        }
    }
}

void preorder(node*root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->right=new node(6);
    root->right->left=new node(7);
    levelwise(root);
    int level=1;
    for(int i=0;i<ans.size();i++){
        vector<int>t=ans[i];
        if(level%2==0){
            for(int j=0;j<t.size();j++){
                cout<<t[j]<<" ";
            }
        }
        else{
            for(int j=t.size()-1;j>=0;j--){
                cout<<t[j]<<" ";
            }
        }
        level++;
        cout<<endl;
    }
return 0;
}