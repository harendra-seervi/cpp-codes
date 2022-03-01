#include<bits/stdc++.h>
using namespace std;
int merge(int arr[],int l,int mid,int h){
    int n1=mid-l+1;
    int n2=h-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[i+l];
    }
    for(int i=0;i<n2 ;i++){
        b[i]=arr[i+mid+1];
    }
    int final=0;
    int i=0,j=0,k=l;
    while(i<n1  && j<n2 ){
        if(a[i]<=b[j]){
            arr[k]=a[i];
            i++; k++;
        }
        else{
            final+=n1-i;
            arr[k]=b[j];
            j++; k++;
        }
    }
    while(i<n1 ){
        arr[k]=a[i];
        i++;k++;
    }
    while(j<n2 ){
        arr[k]=b[j];
        j++;
        k++;
    }
    return final;
}
int mergesort(int arr[],int l,int h){
    int in=0;
    if(l<h){
        int mid=(l+h)/2;
        in+=mergesort(arr,l,mid);
        in+=mergesort(arr,mid+1,h);
        in+=merge(arr,l,mid,h);
    }
    return in;
}
int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int r=mergesort(arr,0,n);
    cout<<r<<endl;
return 0;
}