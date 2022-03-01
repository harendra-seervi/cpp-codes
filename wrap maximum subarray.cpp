#include<iostream>
using namespace std;
int kadan(int array[],int n){
    int maxno=-500;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+array[i];
        if(sum<0){
            sum=0;
        }
        maxno=max(maxno,sum);
    }
    return maxno;
}
int main(){
    int n;
    cin>>n;
    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int wraparray;
    int nonwrap=kadan(array,n);
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum+=array[i];
        array[i]=-array[i];
    }
    wraparray=totalsum+kadan(array,n);
    cout<<max(wraparray,nonwrap);
    return 0;
}