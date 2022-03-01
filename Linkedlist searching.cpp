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

//***********************SEARCHING IN LINKEDLIST**************************

void searching(node* head,int key){
    node* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            cout<<key<<" is found in linkedlist"<<endl;
            break; 
        }
        temp=temp->next;    
    }
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
int main() {
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);  
    insertAtHead(head,4);
    display(head);
    searching(head,4);
return 0;
}