#include <bits/stdc++.h>
using namespace std;
struct Node{int data; Node* next; Node* child; Node(int d):data(d),next(nullptr),child(nullptr){}
};
Node* flatten(Node* head){ if(!head) return head; Node* cur=head; while(cur){ if(cur->child){ Node* child=flatten(cur->child); Node* nxt=cur->next; cur->next=child; Node* t=child; while(t->next) t=t->next; t->next=nxt; cur->child=nullptr; } cur=cur->next; } return head; }
void print(Node* h){ while(h){ cout<<h->data<<" "; h=h->next; } cout<<endl; }
int main(){ Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->child=new Node(4); head->next->child->next=new Node(5); flatten(head); print(head); return 0; }
