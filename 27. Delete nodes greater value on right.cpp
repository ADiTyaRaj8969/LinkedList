#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
Node* deleteGreaterRight(Node* head){ // reverse, remove nodes with smaller value
    Node* prev=nullptr; Node* cur=head; while(cur){ Node* nxt=cur->next; cur->next=prev; prev=cur; cur=nxt; }
    Node* newHead=prev; int maxSoFar=newHead->data; Node* t=newHead; while(t && t->next){ if(t->next->data<maxSoFar){ Node* del=t->next; t->next=del->next; delete del; } else { t=t->next; maxSoFar=t->data; } }
    // reverse back
    prev=nullptr; cur=newHead; while(cur){ Node* nxt=cur->next; cur->next=prev; prev=cur; cur=nxt; }
    return prev;
}
void print(Node* h){ while(h){ cout<<h->data<<" "; h=h->next; } cout<<endl; }
int main(){ Node* head=new Node(12); head->next=new Node(15); head->next->next=new Node(10); head->next->next->next=new Node(11); head->next->next->next->next=new Node(5); head->next->next->next->next->next=new Node(6); head=deleteGreaterRight(head); print(head); return 0; }
