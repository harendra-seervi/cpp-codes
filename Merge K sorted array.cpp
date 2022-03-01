#include<bits/stdc++.h>
using namespace std;

// 3
// 3
// 1 4 7
// 2
// 3 5  
// 3
// 2 6 7

// output
// 1 2 3 4 5 6 7 7

priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
int main(){
    int k;
    cin>>k;
    vector<vector<int>>v;
    for(int i=0;i<k;i++){
        int siz;
        cin>>siz;
        vector<int>temp;
        for(int j=0;j<siz;j++){
            int val;
            cin>>val;
            temp.push_back(val);
        }
        v.push_back(temp);
    }
    for(int i=0;i<k;i++){
        pq.push({v[i][0],i,0});
    }
    while(pq.empty()!=true){
        cout<<pq.top()[0]<<" ";
        int ind=pq.top()[2];
        ind++;
        if(v[pq.top()[1]].size()>ind){
            pq.push({v[pq.top()[1]][ind],pq.top()[1],ind});
        }
        pq.pop();
    }
    
return 0;
}