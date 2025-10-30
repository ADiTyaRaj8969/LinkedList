#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
Node* addLists(Node* a, Node* b){ Node* head=nullptr; Node* tail=nullptr; int carry=0; while(a||b||carry){ int s=carry; if(a){ s+=a->data; a=a->next;} if(b){ s+=b->data; b=b->next;} Node* n=new Node(s%10); carry=s/10; if(!head) head=tail=n; else { tail->next=n; tail=n; } } return head; }
void print(Node* h){ while(h){ cout<<h->data; if(h->next) cout<<" -> "; h=h->next;} cout<<endl; }
int main(){ Node* a=new Node(2); a->next=new Node(4); a->next->next=new Node(3); Node* b=new Node(5); b->next=new Node(6); b->next->next=new Node(4); Node* s=addLists(a,b); print(s); return 0; }
