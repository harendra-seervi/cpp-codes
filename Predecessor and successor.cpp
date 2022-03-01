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
            cout<<endl;
        }
    }
}
node*f;
bool BST(node*root,int val){
    if(root==NULL) return false;
    if(root->data==val){ 
        f=root;
        return true;
    }
    bool lt=BST(root->left,val);
    bool rt=BST(root->right,val);
    if(lt==true|| rt==true){
        return true;
    }
    return false;
}
void inorder(node*root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void inpre(node*root,node*&pre){
    node*p=root->left;
    while(p->right){
        p=p->right;
    }
    pre= p;
}
void insucc(node*root,node*&suc){
    node*p=root->right;
    while(p->left) p=p->left;
    suc=p;
}
void findPreSucc(node*root,node*&pre,node*&suc,int key){
    if(root==NULL) return;
    if(root->data==key){
        if(root->left) inpre(root,pre);
        if(root->right) insucc(root,suc);
        return; 
    }
    if(root->data<key){
        pre=root;
        findPreSucc(root->right,pre,suc,key);
    }
    if(root->data>key){
        suc=root;
        findPreSucc(root->left,pre,suc,key);
    }
}   

int main(){
    node*root=new node(5);
    root->left=new node(1);
    root->right=new node(7);
    root->left->right=new node(3);
    root->left->right->right=new node(4);
    root->left->right->left=new node(2);
    node*pre;
    node*suc;
    inorder(root);
    int key;
    cin>>key;
    findPreSucc(root,pre,suc,key);
    cout<<endl;
    cout<<pre->data<<" "<<suc->data<<" ";
return 0;
}
