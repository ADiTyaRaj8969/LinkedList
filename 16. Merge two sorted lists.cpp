#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
Node* merge(Node* a, Node* b){ if(!a) return b; if(!b) return a; if(a->data<=b->data){ a->next=merge(a->next,b); return a; } else { b->next=merge(a,b->next); return b; } }
void print(Node* h){ while(h){ cout<<h->data; if(h->next) cout<<" -> "; h=h->next;} cout<<endl; }
int main(){ Node* a=new Node(1); a->next=new Node(3); a->next->next=new Node(5); Node* b=new Node(2); b->next=new Node(4); b->next->next=new Node(6); Node* m=merge(a,b); print(m); return 0; }
