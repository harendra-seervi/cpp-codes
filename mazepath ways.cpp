#include<bits/stdc++.h>
using namespace std;
int totalpath=0;
void mazepath(int i,int j,int n,int m,string osf){
	if(i==n-1&& j==m-1){
		totalpath++;
		cout<<osf<<endl;
		return;
	}

	if(i>n-1||j>m-1){
		return;
	}
	mazepath(i,j+1,n,m,osf+"R");
	mazepath(i+1,j,n,m,osf+"D");
	// mazepath(i+1,j+1,n,m,osf+"C");
}
int main() {
	mazepath(0,0,3,3,"");
	cout<<"The total mazepath is "<<totalpath<<endl;
return 0;
}