#include<bits./stdc++.h>
using namespace std;

//       CONSTRUCTION OF NODE

class node{
    public:
    int  data;
    node *next;
    node(int val){
        data =val;
        next=NULL;
    }
};

//        INSERT AT TAIL

void InsertAtTail(node *&head,int val){
    node *n=new node (val);
    node *temp=head ;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

//       DISPLAY

void display(node *&head){
    node *temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
    cout<<"NULL";
}

//     INSERT AT HEAD

void InsertAtHead(node *&head,int val){
    node *n=new node (val);
    n->next=head;
    head =n;
}

//   SEARCHING 

bool searching (node *&head,int key ){
    node *temp=head;
    while(temp->next!=NULL){
        if(temp->data== key){
            return true;
        }
        temp=temp->next;
    }
    if(temp->data==key){
        return true;
    }
    return false;
}

//  delete at head

void deleteAtHead(node *&head){
    node *temp =head;
    head =head->next;
    delete temp;
}

// deletion in node 

void deletenode(node *&head,int val){
    if(head==NULL){
        return;
    }
    if(val==head->data){
        deleteAtHead(head);
        return;
    }
    node *temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node *todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

int main(){
    node *n=new node(64);
    node *head=n;
    InsertAtTail(head,88);
    InsertAtTail(head,34);
    InsertAtTail(head,65);
    InsertAtTail(head,98);
    display(head);
    cout<<endl;
    // deletenode(head,65);
    InsertAtHead(head,5);
    display(head);
    cout<<endl;
    if(searching(head,65)==1){ 
        cout<<"Element is found in linkedlist"<<endl;
    }
    else{
        cout<<"Element is not found in linkedlist"<<endl;
    }
    return 0;
}