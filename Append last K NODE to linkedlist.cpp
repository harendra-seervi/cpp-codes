#include<bits/stdc++.h>
using namespace std;
//********************NODE STRUCTOR**************************************

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

//**********************INSERT AT TAIL***********************************

void insertAtTail(node* &head,int val){
    node* n =new node(val);
    if(head==NULL){
        head=n;
        return;
    }   
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;    
    }
    temp->next=n;
}

//**********************INSERT AT HEAD************************************

void insertAtHead(node* &head,int val ){
    node *n =new node(val);
    n->next=head;
    head=n;
}

//***********************DISPLAY FUNCTION**********************************

void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

// append k nodes from end of the linked list

node *kappend(node *&head,int k){
    k++;
    int length=0;
    node *temp=head;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    int final=length -k;
    int count =0;
    temp=head;
    while(count !=final){
        temp=temp->next;
        count++;
    }
    node *tailnext=temp->next;
    node *tailnextc=temp->next;
    temp->next=NULL;
    while(tailnext->next!=NULL){
        tailnext=tailnext->next;
    }
    tailnext->next=head;
    return tailnextc;
    
}
int main() {
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    node *newhead=kappend(head,3); 
    display(newhead);
return 0;
}