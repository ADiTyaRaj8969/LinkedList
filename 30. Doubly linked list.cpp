#include <iostream>
using namespace std; struct Node{int data; Node* next; Node* prev; Node(int d):data(d),next(nullptr),prev(nullptr){}
};
void push_front(Node*& head,int val){ Node* n=new Node(val); n->next=head; if(head) head->prev=n; head=n; }
void insert_after(Node* prev,int val){ if(!prev) return; Node* n=new Node(val); n->next=prev->next; prev->next=n; n->prev=prev; if(n->next) n->next->prev=n; }
void delete_node(Node*& head, Node* del){ if(!head || !del) return; if(head==del) head=del->next; if(del->next) del->next->prev=del->prev; if(del->prev) del->prev->next=del->next; delete del; }
void print_forward(Node* head){ while(head){ cout<<head->data<<" "; head=head->next; } cout<<endl; }
int main(){ Node* head=nullptr; push_front(head,2); push_front(head,1); insert_after(head,3); print_forward(head); delete_node(head, head->next); print_forward(head); return 0; }
