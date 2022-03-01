#include<iostream>
using namespace std;
int kadan(int array[],int n){
    int sum=0;
    int maxno=-55;
    for(int i=0;i<n;i++){
        sum=sum+array[i];
        if(sum<0){
            sum=0;
        }
        maxno =max(sum,maxno);
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
    int wrapsum;
    int nonwrapsum=kadan(array,n);
    int totalsum=0;
    for(int i=0;i<n;i++){
        totalsum=totalsum+array[i];
        array[i]=-array[i];
    }
    wrapsum=totalsum+kadan(array,n);
    cout<<max(wrapsum,nonwrapsum)<<endl;
    return 0;
 }