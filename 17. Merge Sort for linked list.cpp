#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
Node* merge(Node* a,Node* b){ if(!a) return b; if(!b) return a; if(a->data<=b->data){ a->next=merge(a->next,b); return a; } else { b->next=merge(a,b->next); return b; } }
Node* getMid(Node* head){ if(!head) return head; Node* slow=head; Node* fast=head->next; while(fast && fast->next){ slow=slow->next; fast=fast->next->next; } Node* mid=slow->next; slow->next=nullptr; return mid; }
Node* mergeSort(Node* head){ if(!head||!head->next) return head; Node* mid=getMid(head); Node* left=head; Node* right=mid; left=mergeSort(left); right=mergeSort(right); return merge(left,right); }
void print(Node* h){ while(h){ cout<<h->data; if(h->next) cout<<" -> "; h=h->next;} cout<<endl; }
int main(){ Node* head=new Node(4); head->next=new Node(2); head->next->next=new Node(1); head->next->next->next=new Node(3); head=mergeSort(head); print(head); return 0; }
