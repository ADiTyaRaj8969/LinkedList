#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
Node* rotate(Node* head,int k){ if(!head||k==0) return head; Node* cur=head; int len=1; while(cur->next){ cur=cur->next; len++; } k%=len; if(k==0) return head; cur->next=head; // make circle
    int steps=len-k; Node* tail=cur; while(steps--) tail=tail->next; Node* newHead=tail->next; tail->next=nullptr; return newHead; }
void print(Node* h){ while(h){ cout<<h->data; if(h->next) cout<<" -> "; h=h->next;} cout<<endl; }
int main(){ Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=new Node(4); head->next->next->next->next=new Node(5); head=rotate(head,2); print(head); return 0; }
