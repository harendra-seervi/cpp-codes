#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node*left;
    node*right;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};
void buildBST(node*root,int val){
    if(root->data<val){
        if(root->right){
            buildBST(root->right,val);
        }
        else{
            root->right=new node(val);
            return;
        }
    }
    if(root->data>val){
        if(root->left){
            buildBST(root->left,val);
        }
        else{
            root->left=new node(val);
            return;
        }
    }
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
        else if(q.empty()!=true){
            q.push(NULL);
        }
    }
}
bool BST(node*root,int val){
    if(root==NULL) return false;
    if(root->data==val) return true;
    bool lt=BST(root->left,val);
    bool rt=BST(root->right,val);
    if(lt==true|| rt==true){
        return true;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int find;
    cin>>find;

    node*root=new node(arr[0]);
    for(int i=1;i<n;i++){
       buildBST(root,arr[i]);
    }
    cout<<BST(root,find)<<endl;
return 0;
}