// time complexity   Nlog(N)
#include<bits./stdc++.h>
using namespace std;

int nextGap(int gap)
{
	if (gap <= 1) return 0;
	return (gap / 2) + (gap % 2);
}
void solve(int arr1[],int arr2[],int n,int m){
    int gap=(n+m);
    int i=1;
    int j=i+gap;
    while(gap!=0 ){
        while(j<n && i<n){
            if(arr1[i]>arr1[j]){
                int temp=arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=temp;
            }
            j++;
            i++;            
        }
        j=0;
        while(j<m && i<n){
            if(arr1[i]>arr2[j]){
                int temp=arr1[i];
                arr1[i]=arr2[j];
                arr2[j]=temp;
            }
            j++;i++;
        }
        i=0;
        while(i<m && j<m){
            if(arr2[i]>arr2[j]){
                int temp=arr2[i];
                arr2[i]=arr2[j];
                arr2[j]=temp;
            }
            j++;i++;
        }
        gap=nextGap(gap);
        i=0;j=i+gap;
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int arr1[n/2];
    int arr2[n/2];
    for(int i=0;i<n/2;i++){
        arr1[i]=arr[i];
    }
    int k=0;
    for(int i=n/2;i<n;i++){
        arr2[k]=arr[i];
        k++;
    }
    solve(arr1,arr2,n/2,n/2);
    for(int i=0;i<n/2;i++) cout<<arr1[i]<<" ";
    for(int i=n/2;i<n;i++) cout<<arr2[i]<<" ";
    return 0;
}