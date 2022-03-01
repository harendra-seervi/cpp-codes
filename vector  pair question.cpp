#include<bits/stdc++.h>
using namespace std;
bool mycompair(pair<int,int>p1,pair<int,int>p2){
	return p1.first<p2.first;
}
int main(){
	vector<pair<int,int>>v;
	int arr[8]={10,16,7,14,5,3,12,9};
	for(int i=0;i<8;i++){
		v.push_back(make_pair(arr[i],i));
	}
	sort(v.begin(),v.end(),mycompair);
	for(int i=0;i<v.size();i++){
		arr[v[i].second]=i;
	}
	for(int i=0;i<8;i++){
		cout<<arr[i]; 
	}

	return 0;
}