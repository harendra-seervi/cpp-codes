#include<iostream>
#include<climits>
using namespace std;
void countsort(int arr[],int exp,int n){
    int count [10]={0};
    for(int i=0;i<n;i++){
      count[arr[i]/exp %10]++;
    }
    for(int i=1;i<10;i++){
      count[i]=count[i-1]+count[i];
    }
    int ind[n];
    for(int i=n-1;i>=0;i--){
      count[arr[i]/exp%10]--;
      ind[count[arr[i]/exp %10]]=arr[i];
    }
    for(int i=0;i<n;i++){
      arr[i]=ind[i];
    }
}

void radixsort(int arr[],int n){
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>maxi) maxi=arr[i];
    }
    int exp=1;
    while(exp<maxi){
        countsort(arr,exp,n);
        exp=exp*10;
    }
}
    
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    radixsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}