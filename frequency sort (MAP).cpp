// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
bool mycompair(pair<int,int>p1,pair<int,int>p2){
    return p1.second>p2.second;
}
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {  
        //Your code here
        map<int,int>m;
        for(int i=0;i<n;i++){
            auto itr=m.find(arr[i]);
            if(itr==m.end()){
                m[arr[i]]=1;
            }
            else{
                m[arr[i]]++;
            }
        }

        vector<pair<int,int>>v;
        for(auto val:m){
            v.push_back(make_pair(val.first,val.second));
           
        }
        cout<<endl;
        sort(v.begin(),v.end(),mycompair);
        vector<int>ans;
        for(int i=0;i<v.size();i++){
            ans.push_back(v[i].first);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends