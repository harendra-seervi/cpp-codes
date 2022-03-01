#include<bits/stdc++.h>
using namespace std;

//  doubley linked list node structure

class node {
    public:
    int data;
    node *prev;
    node *next;
    node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};

//insertion at tail

void insert_at_tail(node *&head,int val){
    node *n=new node (val);
    if(head==NULL){
        head=n;
        return ;
    }
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

// insert at head
void insert_at_head(node *&head,int val){
    node *n=new node (val);
    if(head==NULL){
        head=n; 
        return;
    }
    head->prev=n;
    n->next=head;
    head=n;
}

// insert at any given value 

void insert_at_any_given_value(node *&head,int val,int c){
    node *temp=head;
    node *n=new node (c);
    while(temp->data!=val && temp!=NULL){
        temp=temp->next;
    }
    if(temp==NULL) {
        cout<<"value is not preset "<<endl;
    }
    else{
        n->next=temp->next;
        temp->next->prev=n;
        temp->next=n;
        n->prev=temp;
    }

}

// deletion at any point 

void deletion_at_any_point(node *&head,int val){
    node *temp=head;
    if(head->data==val){
        head=head->next;
        head->prev=NULL;
        delete(temp);
        return;
    }
    while(temp->next->data!=val && temp!=NULL){
        temp=temp->next;
    }
    if(temp-> next->next==NULL){
        delete temp->next;
        temp->next=NULL;
        return ;
    }
    node *todelete=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    delete (todelete);
}

// display

void display(node *&head){
    node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
    cout<<endl;
    cout<<"reverse traverse"<<endl;
    
    while(temp->prev!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
    cout<<temp->data<<" ";
    cout<<endl;
}
int main() {
    node *n=new node (1);
    node *head=n;
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_head(head,0);
    insert_at_any_given_value(head,4,100);
    deletion_at_any_point(head,5);
    display(head);
return 0;
}