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

void solve(node*root,int hd,map<int,vector<int>>&mp){
    if(root==NULL) return;
    mp[hd].push_back(root->data);
    solve(root->left,hd-1,mp);
    solve(root->right,hd+1,mp);
}

int main(){
    node*root=new node(10);
    root->left=new node(7);
    root->right=new node(4);
    root->left->left=new node(3);
    root->left->right=new node(11);
    root->right->right=new node(6);
    root->right->left=new node(14);
    int hd=0;
    map<int,vector<int>>mp;
    solve(root,hd,mp);
    for(auto val:mp){
        vector<int>temp=val.second;
        cout<<val.first<<" ";
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
    }
return 0;
}