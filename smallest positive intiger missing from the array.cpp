#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){ 
        cin>>array[i];
    }
    int N=1e6+2;
    bool check[N];
    for(int i=0;i<n;i++){
        check[i]=false;
    }
    for(int i=0;i<n;i++){
        if(array[i]>=0){
            check[array[i]]=true;
        }
    }
    int ans=-1;  
    for(int i=1;i<N;i++){
        if(check[i]==false){
            ans=i;
            break;
        }  
    }
    cout <<ans <<" is the no is missing from an array"<<endl;
return 0;
}