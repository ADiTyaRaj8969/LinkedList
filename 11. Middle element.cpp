#include <iostream>
using namespace std;
struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
void append(Node*& h,int v){ Node* n=new Node(v); if(!h){h=n;return;} Node* c=h; while(c->next) c=c->next; c->next=n; }
Node* middle(Node* head){ if(!head) return nullptr; Node* slow=head; Node* fast=head; while(fast && fast->next){ slow=slow->next; fast=fast->next->next; } return slow; }
void print(Node* h){ while(h){ cout<<h->data; if(h->next) cout<<" -> "; h=h->next;} cout<<endl; }
int main(){ Node* head=nullptr; append(head,10); append(head,20); append(head,30); append(head,40); append(head,50); print(head); Node* mid=middle(head); if(mid) cout<<"Middle: "<<mid->data<<endl; return 0; }
