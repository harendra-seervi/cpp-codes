// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//Back-end complete function Template for C++

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

int ind=0;
node* buidprein(int pre[],int in[],int st,int end,unordered_map<int,int >&mp){
	if(st>end) return NULL;
	node*root=new node(pre[ind++]);
	if(st==end) return root;
	int mid=mp[root->data];
	root->left=buidprein(pre,in,st,mid-1,mp);
	root->right=buidprein(pre,in,mid+1,end,mp);
	return root;
}

void postt(node*root,vector<int>&v){
	if(root==NULL) return;
	postt(root->left,v);
	postt(root->right,v);
	v.push_back(root->data);
}

class Solution{
    public:
    bool checktree(int pre[], int in[], int post[], int n) 
    { 
    	// Your code goes here
		unordered_map<int,int>mp;
		for(int i=0;i<n;i++){
			mp.insert({in[i],i});
		}
		node*root=buidprein(pre,in,0,n-1,mp);
		vector<int>v;
		postt(root,v);
		bool check=true;
		for(int i=0;i<n;i++){
			if(v[i]!=post[i]){
				check=false;
			}
		}
		return check;
    } 

};


// { Driver Code Starts.


// 1
// 5
// 1 2 4 5 3
// 4 2 5 1 3
// 4 5 2 3 1




int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 

  // } Driver Code Ends