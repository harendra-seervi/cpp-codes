#include<bits./stdc++.h>
using namespace std;

//  construction of node
class node{
    public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=NULL;
    }
};

//  insert at tail

void insertattail(node *&head,int val){
    node *temp=head;
    node *n=new node(val);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

// display

void display(node *&head){
    node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
}
//  reverselinkedlist

node* reverselinkedlist(node *&head){
    node *previous =NULL;
    node *current =head;
    node *next;
    while(current!=NULL){
        next=current->next;
        current ->next=previous;
        previous =current;
        current =next;
    }
    return previous;
}
// reverserecursivly

node* reverserecursivly(node *&head ){
    if(head->next==NULL) return head;
    node *newhead=reverserecursivly(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

// reverse k node of linked list
node *revk(node *&head,int k){
    node *previous =NULL;
    node *current =head;
    node *next;
    int count =0;
    while( count <k && current!=NULL){
        next=current->next;
        current->next =previous;
        previous = current;
        current=next;
        count++;
    }
    if(next!=NULL){
        head->next=revk(next,k);
    }
    return previous;
}

// make cycle 

void make_cycle (node*&head,int position){
    node *temp=head;
    node *starting_node;
    int count =1;
    while(temp->next!=NULL){
        if(count==position){
            starting_node=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=starting_node;
}

// detect cycle (Floyd's algorithm) or(hare and tortoise algoritham)

bool dectect_cycle(node *&head){
    node *slow =head;
    node *fast =head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)  return true;
    }
    return false;
}

// removel of cycle
 
void removel_of_cycle(node *&head){
    node *fast=head;
    node *slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow ->next;
        if(fast==slow)  break;
    }
    fast=head;
    while (fast->next!=slow ->next){
        fast=fast->next;
        slow =slow ->next;
    }
    slow ->next=NULL;
}

int main(){
    node *n=new node(1);
    node *head=n;
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    make_cycle(head,4);
    cout<<endl;
    cout<<"Before using removel cycle function"<<endl;
    if(dectect_cycle(head)==1)   cout<<"cycle is present "<<endl;
    else    cout<<" cycle is not present "<<endl;
    removel_of_cycle(head);
    cout<<endl;
    cout<<"After using removel function"<<endl;
    if(dectect_cycle(head)==1)   cout<<"cycle is present "<<endl;
    else    cout<<"cycle is not present "<<endl;
    return 0;
}