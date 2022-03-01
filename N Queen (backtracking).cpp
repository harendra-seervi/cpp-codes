#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<bool>>&grid,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]){
                cout<<"Q"<<" ";
            }
            else{ 
                cout<<"_"<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;  
    cout<<endl;
}

int totalways=0;
bool issafe(vector<vector<bool>>&grid,int n,int row,int col){
    //col
    for(int i=row-1;i>=0;i--){
        if(grid[i][col]) return false;
    }
    //diganally left
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if(grid[i][j]) return false;
    }
    //diganlly right
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(grid[i][j]) return false;
    }
    return true;
}
void NQueencount(vector<vector<bool>>&grid ,int n,int row){
    if(row==n ){
        totalways++;
        display(grid,n);
        return ;
    }
    for(int j=0;j<n;j++){
        if(issafe(grid,n,row,j)){
            grid[row][j]=true;
            NQueencount(grid,n,row+1);
            grid[row][j]=false;
        }
    }
}
int main() {
    int n;
    cin>>n;
    vector<vector<bool>>grid(n,vector<bool>(n,false));
    NQueencount(grid,n,0);
    cout<<totalways<<endl;
return 0;
}