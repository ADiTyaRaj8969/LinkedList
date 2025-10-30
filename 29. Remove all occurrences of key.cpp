#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
Node* removeAll(Node* head,int key){ while(head && head->data==key){ Node* t=head; head=head->next; delete t; } Node* cur=head; while(cur && cur->next){ if(cur->next->data==key){ Node* t=cur->next; cur->next=t->next; delete t; } else cur=cur->next; } return head; }
void print(Node* h){ while(h){ cout<<h->data<<" "; h=h->next; } cout<<endl; }
int main(){ Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(1); head->next->next->next=new Node(3); head=removeAll(head,1); print(head); return 0; }
