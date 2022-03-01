// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    string remove(string s){
        // code here
        bool check=false;
        int ct=0;
        int end;
        for(int i=0;i<s.size();i++){
            if(s[i]==s[i+1] && (i+1)<s.size()){
                ct++;
                check=true;
            }
            else{
                if(check==true){
                    s.erase(i-ct,ct+1);
                    i=i-ct-1;
                }
                check=false;
                ct=0;
            }
        }
        return s;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}  // } Driver Code Ends

// acaaabbbacdddd
// ans-> acac