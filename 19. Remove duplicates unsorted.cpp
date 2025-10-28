#include <iostream>
#include <unordered_set>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
void removeDup(Node* head){ if(!head) return; unordered_set<int> s; Node* cur=head; Node* prev=nullptr; while(cur){ if(s.count(cur->data)){ prev->next=cur->next; delete cur; cur=prev->next; } else { s.insert(cur->data); prev=cur; cur=cur->next; } } }
void print(Node* h){ while(h){ cout<<h->data; if(h->next) cout<<" -> "; h=h->next;} cout<<endl; }
int main(){ Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(2); head->next->next->next=new Node(3); head->next->next->next->next=new Node(1); removeDup(head); print(head); return 0; }
