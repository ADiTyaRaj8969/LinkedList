#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
Node* swapPairs(Node* head){ if(!head||!head->next) return head; Node* newHead=head->next; Node* prev=nullptr; Node* cur=head; while(cur && cur->next){ Node* nxt=cur->next; Node* nextpair=nxt->next; nxt->next=cur; cur->next=nextpair; if(prev) prev->next=nxt; prev=cur; cur=nextpair; } return newHead; }
void print(Node* h){ while(h){ cout<<h->data; if(h->next) cout<<" -> "; h=h->next;} cout<<endl; }
int main(){ Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=new Node(4); head=swapPairs(head); print(head); return 0; }
