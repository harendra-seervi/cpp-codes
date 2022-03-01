#include<iostream>
using namespace std;
void swap(int arr[],int i,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partation(int arr[],int l,int r){
    int pi=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pi){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,r,i+1);
    return i+1;
}

void quicksort(int arr[],int l,int r){
    if(l<r){
        int pi=partation(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}