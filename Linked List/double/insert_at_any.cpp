#include<bits/stdc++.h>
using namespace std;

class Node{
     public:
     int val;
     Node* next;
     Node* prev;
     Node(int val){
          this->val=val;
          this->next=NULL;
          this->prev=NULL;
     }
};

void display_normal(Node* head){
     Node* tmp = head;
     while(tmp!=NULL){
          cout<<tmp->val<<" ";
          tmp=tmp->next;
     }
}


void insert_at_haed(Node* &head,int val){
     Node * newNode = new Node(val);
     if(head==NULL){
          return;
     }
 newNode->next=head;
 head->prev=newNode;
 head=newNode;

}


void insert_at_tail(Node* &tail,int val){


     Node* newNode = new Node(val);
     if (tail == nullptr) {
        tail = newNode;
        return;
    }

     tail->next=newNode;
     newNode->prev=tail;
     tail=newNode;
}





void insert_at_any(Node* head,int pos,int val){
     Node* tmp = head;
     Node* newNode = new Node(val);
     for(int i=1;i<=pos-1;i++){
          tmp=tmp->next;
     }
     newNode->next=tmp->next;
     tmp->next=newNode;
     newNode->next->prev=newNode;
     newNode->prev=tmp;
}

void display_reverse(Node* tail){
     Node* tmp = tail;
     while(tmp!=NULL){
          cout<<tmp->val<<" ";
          tmp=tmp->prev;
     }
}

int main(){
     Node* head = new Node(10);
     Node* a = new Node(20);
     Node* b = new Node(30);
     Node* tail = b;

     head->next=a;
     a->prev=head;
     a->next=b;
     b->prev=a;

     display_normal(head);
     display_reverse(tail);

}