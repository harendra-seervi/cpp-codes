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

// insert two linked linked list

node *insert_two_linkedlist(node *&head,int val){
    node*temp=head;
    node*newhead;
    while(temp->data!=val){
        temp=temp->next;
    }
    insertAtHead(temp,10);
    insertAtHead(temp,9);
    newhead=temp;
    return newhead;
}

  

int intersection_point(node *&head,node*newhead){
    int l1=0;
    int l2=0;
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        l1++;
    }
    node*temp2=newhead;
    while(temp2->next!=NULL){
        temp2=temp2->next;
        l2++;
    }
    if(l1>l2){
        int d=l1-l2;
        int c=0;
        node*ptr1=head;
        node*ptr2=newhead;
        while(c!=d){
            ptr1=ptr1->next;
            c++;
        }
        while(ptr1->next!=ptr2->next && ptr2!=NULL){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        return ptr1->next->data;
    }
    else{
        int newd=l2-l1;
        int cc=0;
        node*ptr11=head;
        node*ptr22=newhead;
        while(cc!=newd){
            ptr22=ptr22->next;
            cc++;
        }
        while(ptr22->next->data!= ptr11->next->data){
            ptr22=ptr22->next;
            ptr11=ptr11->next;
        }
        return ptr11->next->data;
    }
    return -1;
}

// merge two sorted arrays

node* merge_two_sorted_arrays(node*&head,node*&newhead){
    node*dummy =new node(-1);
    node*st=dummy;
    node*ptr1=head;
    node*ptr2=newhead;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data<ptr2->data){
            dummy->next=ptr1;
            ptr1=ptr1->next;
            dummy=dummy->next;
        }
        else{
            dummy->next=ptr2;
            ptr2=ptr2->next;
            dummy=dummy->next;
        }
    }
    while(ptr1!=NULL){
        dummy->next=ptr1;
        dummy=dummy->next;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        dummy->next=ptr2;
        dummy=dummy->next;
        ptr2=ptr2->next;
    }
    dummy->next=NULL;
    return st->next;
}

// merge linked list (recursivily way)

node* merge_recursily(node*&head,node*&newhead){
    if(head==NULL){
        return newhead;
    }
    if(newhead==NULL){
        return head;
    }
    node*final;
    if(head->data<newhead->data){
        final=head;
        final->next=merge_recursily(head->next,newhead);
    }
    else{
        final=newhead;
        final->next=merge_recursily(head,newhead->next);
    }
}

int main() {    
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,7);
    node*newhead=NULL;
    insertAtTail(newhead,2);
    insertAtTail(newhead,3);
    insertAtTail(newhead,6);
    display(head);
    cout<<endl;
    display(newhead);
    cout<<endl;
    node*finalnode=merge_recursily(head,newhead);
    display(finalnode);
return 0;
}