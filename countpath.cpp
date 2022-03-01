#include<bits/stdc++.h>
using namespace std;
int counterpath(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count=0;
    for(int i=1;i<6;i++){
        
        count+=counterpath(s+i,e);
    }
    return count;
}
int main(){
    cout<<counterpath(0,4)<<endl;
    return 0;
}