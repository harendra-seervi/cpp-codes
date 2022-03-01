#include<bits/stdc++.h>
using namespace std;
//4
// 8 11 3 13
//output
// 10
// 12.5
// 15
// 18
// 18
// 18.5
priority_queue<int,vector<int>>maxheap;
priority_queue<int,vector<int>,greater<int>> minheap;
void insert(int x){
    if(maxheap.size()==minheap.size()){
        if(maxheap.size()==0){
            maxheap.push(x);
            return;
        }
        else{
            if(x>maxheap.top()){
                minheap.push(x);
                return;
            }
            else{
                maxheap.push(x);
                return;
            }
        }
    }
    if(maxheap.size()>minheap.size()){
        if(x>maxheap.top()){
            minheap.push(x);
            return;
        }
        else{
            maxheap.push(x);
            int temp=maxheap.top();
            maxheap.pop();
            minheap.push(x);
            return;
        }
    }
    else if(maxheap.size()<minheap.size()){
        if(x>minheap.top()){
            minheap.push(x);
            int temp=minheap.top();
            minheap.pop();
            maxheap.push(temp);
            return;
        }
        else{
            maxheap.push(x);
            return;
        }
    }
}
double findMedian(){
    if(minheap.size()>maxheap.size()){
        return minheap.top();
    }
    
    if(minheap.size()<maxheap.size()){
        return maxheap.top();
    }

    else{
        return (maxheap.top()+minheap.top())/2.0;
    }

}

int main(){
    insert(10);
    cout<<findMedian()<<endl;
    insert(15);
    cout<<findMedian()<<endl;
    insert(21);
    cout<<findMedian()<<endl;
    insert(30);
    cout<<findMedian()<<endl;
    insert(18);
    cout<<findMedian()<<endl;
    insert(19);
    cout<<findMedian()<<endl;
return 0;
}