// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	long long int getNthUglyNo(long long int n) {
	    vector<long long int>v;
	    v.push_back(1);
	    long long int p2=0,p3=0,p5=0;
	    for(long long int i=1;i<n;i++){
	        long long int f2=2*v[p2];
	        long long int f3=3*v[p3];
	        long long int f5=5*v[p5];
	        long long int minno=min(f2,min(f3,f5));
            bool check=false;
	        if(minno==f2){
                v.push_back(f2);
                check=true;
	            p2++;
	        }
	        if(minno==f3){
                if(check==false){
                    v.push_back(f3);
                }
                check=true;
	            p3++;
	        }
	        if(minno==f5){
                if(check==false){
                    v.push_back(f5);
                }
	            p5++;
	        }
	    }
        cout<<endl;
        for(long long int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        long long int final=v[n-1];
	    return final;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends