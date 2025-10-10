#include<bits/stdc++.h>
using namespace std;

class Node{
     public:
     int val;
     Node* next;
     Node(int val){
          this->val=val;
          this->next=NULL;
     }
};

void insert_at_tail(Node*& head,int v){
     Node * newNode = new Node(v);
     if(head==NULL){
          head=newNode;
          return;
     }
     Node *tmp = head;
     while(tmp->next!=NULL){
          tmp=tmp->next;
     }
     tmp->next=newNode;
}


void insert_at_head(Node* &head,int v){
     Node* newNode = new Node(v);
     newNode->next = head;
     head=newNode;
}








void insert_at_any_pos(Node* & head,int v,int pos){
      
     Node* newNode = new Node(v);    
     if (pos == 1 || head == nullptr) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
     Node* tmp = head;
     int cnt=0;
     for(int i=1;i<=pos-1;i++){
          tmp=tmp->next;
          if(tmp==NULL){
               cout<<"Invalid index"<<endl;
               return;
          }
     }
     newNode->next=tmp->next;
     tmp->next = newNode;
}


void delete_from_pos(Node* & head,int pos){
   
     Node* tmp = head;
     for(int i=1;i<=pos-1;i++){
          tmp=tmp->next;
           if(tmp==NULL){
               cout<<"Invalid index"<<endl;
               return;
          }
     }
     Node *deleteNode  = tmp->next;
     tmp->next = tmp->next->next;
     delete deleteNode;
}


void delete_from_head(Node* & head){
   
     if(head==NULL){
          cout<<"head is not available"<<endl;
          
          return;
     }

     Node *deleteNode  = head;
     head = head->next;
     delete deleteNode;

}









void print_linked_list(Node *head){
     Node*tmp = head;
     while(tmp!=NULL){
        cout<<tmp->val<<endl;
        tmp=tmp->next;
     }
}





int main(){
    Node* head = NULL;
    int v,pos,newvalue;
    int n;
    cin>>n;
    while(n--){
    cin>>v;
    insert_at_tail(head,v);
    }   
    cin>>newvalue>>pos;
    insert_at_any_pos(head,newvalue,pos);
    print_linked_list(head);
    insert_at_head(head,v);

}