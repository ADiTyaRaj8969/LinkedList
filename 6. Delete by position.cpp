#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};

void append(Node*& h,int v){ Node* n=new Node(v); if(!h){h=n;return;} Node* c=h; while(c->next) c=c->next; c->next=n; }

void delete_pos(Node*& head,int pos){ if(!head) return; if(pos<=0){ Node* t=head; head=head->next; delete t; return; } Node* cur=head; for(int i=0;i<pos-1 && cur->next;i++) cur=cur->next; if(cur->next){ Node* t=cur->next; cur->next=t->next; delete t; } }
void print(Node* h){ while(h){ cout<<h->data; if(h->next) cout<<" -> "; h=h->next;} cout<<endl; }
int main(){ Node* head=nullptr; append(head,10); append(head,20); append(head,30); append(head,40); cout<<"Before: "; print(head); delete_pos(head,2); cout<<"After deleting position 2: "; print(head); return 0; }
