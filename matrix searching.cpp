#include<iostream>                                                  
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int key;
    cin>>key;
    int flag=false;
    int r=0,c=m-1;
    while(r<m&&c>=0){
        if(arr[r][c]==key){
            cout<<" element is found"<<endl;
            break;
        }
        else if(arr[r][c]<key){
            r++;
        }
        else{
            c--;
        }
    }
    return 0;
}

