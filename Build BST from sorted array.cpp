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
node* insucc(node*root){
    node*p=root->right;
    while(p->left)  p=p->left;
    return p;
}
void swap(int &temp1,int &temp2){
    int temp=temp1;
    temp1=temp2;
    temp2=temp;
}
node*deletenode(node*root,int key){
    if(!root) return NULL;
    if(root->data<key) root->right=deletenode(root->right,key);
    else if(root->data>key) root->left=deletenode(root->left,key);
    else{
        if(!root->right){
            node*temp=root->left;
            delete(root);
            return temp;
        }
        else if(!root->left){
            node*temp=root->right;
            delete(root);
            return temp;
        }       
        else{
            node*temp=insucc(root);
            swap(temp->data,root->data);
            root->right=deletenode(root->right,key);
        }
    }
    return root;
}
int ind=0;
node*buildTreePreorder(int arr[],int min,int maxi,int n){
    if(ind>=n||arr[ind]<min || arr[ind]>maxi) return NULL;
    node*root=new node(arr[ind++]);
    root->left=buildTreePreorder(arr,min,root->data,n);
    root->right=buildTreePreorder(arr,root->data,maxi,n);
    return root;
}
void levelWise(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(q.empty()!=true){
        node*n=q.front();
        if(n!=NULL){
            cout<<n->data;
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        else if(q.empty()!=true){
            q.push(NULL);
            cout<<endl;
        }
    }
}
node*buildbstsorted(int arr[],int st,int end){
    if(st>end) return NULL;
    int mid=(st+end)/2;
    node*n=new node(arr[mid]);
    n->left=buildbstsorted(arr,st,mid-1);
    n->right=buildbstsorted(arr,mid+1,end);
    return n;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node*root=buildbstsorted(arr,0,n-1);
    levelwise(root);
return 0;
}

//210310507402