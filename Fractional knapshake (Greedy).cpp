#include<bits/stdc++.h>
using namespace std;
int main(){
    double n;
    cin>>n;
    multimap<double,vector<double>,greater<double>>mp;
    for(double i=0;i<n;i++){
        double f,s;
        cin>>f>>s;
        vector<double>temp;
        temp.push_back(f);
        temp.push_back(s);
        mp.insert({(f/s),temp});
    }
    double w;
    cin>>w;
    double sum=0;
    double maxval=0;
    for(auto val:mp){
        cout<<val.first<<" ";
        for(double i=0;i<val.second.size();i++){
            cout<<val.second[i]<<" ";
        }
        cout<<endl;
    }
    for(auto val:mp){
        if(val.second[1]+sum<=w){
            sum+=val.second[1];
            maxval+=val.second[0];
        }
        else if(sum==w){
            break;
        }
        else{
            double req=(w-sum);
            sum+=req;
            maxval+=(req*val.first);
        }
    }
    cout<<maxval<<endl;
return 0;
}