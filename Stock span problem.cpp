#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans;
    stack<pair<int,int>>st;
    for(int i=0;i<n;i++){
        int day=1;
        while(st.empty()!=true && st.top().first<=arr[i]){
            day+=st.top().second;
            st.pop();
        }
        st.push({arr[i],day});
        ans.push_back(day);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
return 0;
}
// 7
// 100 80 60 70 60 75 85


//ans :- 1 1 1 2 1 4 6  