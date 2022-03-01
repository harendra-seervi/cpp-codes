// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        // per  value  weight
        multimap<double,vector<int>,greater<int>>mp;
        for(int i=0;i<n;i++){
            int per= arr[i].value/(double)arr[i].weight;
            vector<int>temp;
            temp.push_back(arr[i].value);
            temp.push_back(arr[i].weight);
            mp.insert({per,temp});
        }
        for(auto val:mp){
            cout<<val.first<<" ";
            for(int i=0;i<val.second.size();i++){
                cout<<val.second[i]<<" ";
            }
            cout<<endl;
        }
        int sum=0;
        double maxval=0;
        for(auto val:mp){
            if(sum+val.second[1]<=w){
                sum+=val.second[1];
                maxval+=val.second[0];
            }
            else{
                double req=w-sum;
                sum+=req;
                maxval=maxval+(req*val.first);
            }
        }
        return maxval;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends