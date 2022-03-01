#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	string b;
	cin>>a>>b;
	int n=a.size()+1;
	int arr[n]={0};
	int j=b.size()-1;
	int i=a.size()-1;
	int carr=0;
	int k=n-1;
	while(j>=0 && i>=0){
		int temp=a[i]-'0'+b[j]-'0';
		int ld=temp%10;
		temp=temp/10;
		arr[k]=ld+carr;
		carr=temp;
		i--;
		j--;
		k--;
	}
	while(i>=0){
		int temp=a[i]-'0'+carr;
		int ld=temp%10;
		arr[k]=ld;
		carr=temp/10;
		k--;
		i--;
	}
	while(j>=0){
		int temp=b[j]-'0'+carr;
		int ld=temp%10;
		arr[k]=ld;
		carr=temp/10;
		k--;
		j--;
	}
	arr[k]=carr;
	for(int f=0;f<n;f++){
		cout<<arr[f];
	}
return 0;
}