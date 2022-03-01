// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User functio  n template for C++

class Solution {
  public:
    void solve(vector<int>v,int idx, int sum, vector<vector<int>>&ans,vector<int>&temp)
   {
       
       if(sum==0)
       {
           ans.push_back(temp);
           return;
       }
       
       for(int i=idx;i<v.size();i++)
       {
           if(sum-v[i]>=0)
           {
               temp.push_back(v[i]);
               sum=sum-v[i];
               solve(v,i,sum,ans,temp);
             
               sum+=v[i];
                temp.pop_back();
           }
       }
   }
   vector<vector<int> > combinationSum(vector<int> &A, int B) {
       // Your code here
       
       set<int>s;
       for(int i=0;i<A.size();i++)
       s.insert(A[i]);
       
       vector<int>v;
       vector<vector<int>>ans;
       for(auto it = s.begin();it!=s.end();it++)
       v.push_back(*it);
       
      vector<int>temp;
      
      solve(v, 0,B,ans,temp);
      
      return ans;
   }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
            cout<<endl;
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends