#include <iostream>
#include <vector>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
void reorder(Node* head){ if(!head) return; vector<Node*> v; Node* cur=head; while(cur){ v.push_back(cur); cur=cur->next; } int i=0,j=v.size()-1; while(i<j){ v[i]->next=v[j]; i++; if(i==j) break; v[j]->next=v[i]; j--; } v[i]->next=nullptr; }
void print(Node* h){ while(h){ cout<<h->data<<" "; h=h->next; } cout<<endl; }
int main(){ Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=new Node(4); head->next->next->next->next=new Node(5); reorder(head); print(head); return 0; }
