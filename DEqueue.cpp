#include<iostream>
#include<deque>
using namespace std;
int main(){
    //**********function***************
    //push_back() ,push_front() ,pop_back() ,pop_front() 
    //front() ,back();
    deque<int>d;
    d.push_front(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    while(d.empty()!=true){
        cout<<d.front()<<endl;
        d.pop_front();
    }   
    return 0;
}