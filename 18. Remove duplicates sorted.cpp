#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
void removeDup(Node* head){ if(!head) return; Node* cur=head; while(cur->next){ if(cur->data==cur->next->data){ Node* t=cur->next; cur->next=t->next; delete t; } else cur=cur->next; } }
void print(Node* h){ while(h){ cout<<h->data; if(h->next) cout<<" -> "; h=h->next;} cout<<endl; }
int main(){ Node* head=new Node(1); head->next=new Node(1); head->next->next=new Node(2); head->next->next->next=new Node(3); head->next->next->next->next=new Node(3); removeDup(head); print(head); return 0; }
