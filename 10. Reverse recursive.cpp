#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};

Node* reverse_rec(Node* head){ if(!head||!head->next) return head; Node* rest=reverse_rec(head->next); head->next->next=head; head->next=nullptr; return rest; }
void append(Node*& h,int v){ Node* n=new Node(v); if(!h){h=n;return;} Node* c=h; while(c->next) c=c->next; c->next=n; }
void print(Node* h){ while(h){ cout<<h->data; if(h->next) cout<<" -> "; h=h->next;} cout<<endl; }
int main(){ Node* head=nullptr; append(head,10); append(head,20); append(head,30); cout<<"Before: "; print(head); head=reverse_rec(head); cout<<"After reverse recursive: "; print(head); return 0; }
