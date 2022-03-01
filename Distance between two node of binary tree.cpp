//       1  <-root 
//      / \
//     2   3
//    /    /\
//   4    5  6
//       /
//      7

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

void postorder(node* root){
    if(root==NULL) return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

vector<vector<int>>v;
void leveltraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    vector<int>x;
    x.push_back(root->data);
    v.push_back(x);
    x.clear();
    while(q.empty()!=true){
        node*n=q.front();
        q.pop();
        if(n!=NULL){
             if(n->left){ 
                x.push_back(n->left->data);
                q.push(n->left);
            }
            if(n->right){
                x.push_back(n->right->data);
                q.push(n->right);
            }
        }
        else if(q.empty()!=true){
            v.push_back(x);
            x.clear();
            q.push(NULL);
        }
    }
}



int ind=0;
node* buildTree(int pre[],int in[],int st,int end,unordered_map<int,int>mp){
    if(st>end) return NULL;
    node*root=new node(pre[ind++]);
    if(st==end) return root;
    int mid=mp[root->data];
    root->left=buildTree(pre,in,st,mid-1,mp);
    root->right=buildTree(pre,in,mid+1,end,mp);
    return root;
}

int sumAtK(node*root,int k){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;
    while(q.empty()!=true){
        node*n=q.front();
        q.pop();
        if(n!=NULL){
            if(level==k){
                sum+=(n->data);
            }
            if(n->left){
                q.push(n->left);
            }
            if(n->right){
                q.push(n->right);
            }
        }
        else if(q.empty()!=true){
            level++;
            q.push(NULL);
        }
    }
    return sum;
}

int height(node*root){
    if(root==NULL){
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    return (max(l,r)+1);
}
int diameter_of_tree(node*root){
    if(root==NULL) return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    diameter_of_tree(root->left);
    diameter_of_tree(root->right);
    return 1;
}
int ma;
int diameter(node* root){
    if(root==NULL) return 0;
    int lh=diameter(root->left);
    int rh=diameter(root->right);
    ma=max(lh+rh+1,ma);
    return (max(lh,rh)+1);
}
int h(node*root){
    if(root==NULL) return 0;
    int lh=h(root->left);
    int rh=h(root->right);
    return 1+max(lh,rh);
}

node*lca(node*root,int n1,int n2){
    if(root==NULL) return NULL;
    if(root->data==n1|| root->data==n2) return root;
    node* l=lca(root->left,n1,n2);
    node* r=lca(root->right,n1,n2);
    if(l && r) return root;
    if(l) return l;
    else return r;
}
bool check=true;
int isbalanced(node* root){
    if(root==NULL) return 0;
    int lh=isbalanced(root->left);
    int rh=isbalanced(root->right);
    int f=(lh-rh);
    if(f<0) f=(f*(-1));
    if(f>1){
        check=false;
    }
    return 1+max(rh,lh);
}
vector<int> rightView(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    stack<int>a;
    vector<int>ans;
    while(q.empty()!=true){
        node*n=q.front();
        q.pop();
        if(n!=NULL){
            a.push(n->data);
            if(n->right){
                q.push(n->right);
            }
            if(n->left){
                q.push(n->left);
            }
        }
        else if(q.empty()!=true){
            int x=a.top();
            ans.push_back(x);
            q.push(NULL);
        }
    }
    ans.push_back(a.top());
    return ans;
}
int hl(node*root,int a,int b){
    if(root->data==a || root->data==b){
        return 0;
    }
    int hh=hl(root->left,a,b);
    return 1+hh;
}
int hr(node*root,int a,int b){
    if(root->data==a || root->data==b){
        return 0;
    }
    int hh=hr(root->right,a,b);
    return 1+hh;
}

int main(){
//       1  <-root node
//      / \
//     2   3
//    /    /\
//   4    5  6
//       /
//      7
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->right->left=new node(5);
    root->right->left->left=new node(7);
    root->right->right= new node(6);
    node*x=lca(root,4,6); // LCA (Lowest Common anccstor)
    cout<<x->data<<endl; 
    int f=hl(x,4,6)+hr(x,4,6);
    cout<<f<<endl;
}