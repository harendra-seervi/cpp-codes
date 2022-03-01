#include<iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int colstart=0,colend=m-1,rowstart=0,rowend=n-1;
    while(colstart<=colend && rowstart<=rowend ){
        for(int i=colstart;i<=colend;i++){
            cout<< arr[rowstart][i]<<" ";
        }
        rowstart++;
        for(int j=rowstart;j<=rowend;j++){
            cout<<arr[j][colend]<<" ";
        }
        colend--;
        for(int i=colend;i>=colstart;i--){
            cout<<arr[rowend][i]<<" ";
        }
        rowend--;
        for(int j=rowend;j>=rowstart;j--){
            cout<<arr[j][colstart]<<" ";
        }
        colstart++;
    }


return 0;
}