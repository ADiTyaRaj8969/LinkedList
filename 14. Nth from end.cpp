#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
int nthFromEnd(Node* head,int n){ Node* first=head; Node* second=head; for(int i=0;i<n;i++){ if(!first) return -1; first=first->next; } while(first){ first=first->next; second=second->next; } return second?second->data:-1; }
void append(Node*& h,int v){ Node* n=new Node(v); if(!h){h=n;return;} Node* c=h; while(c->next) c=c->next; c->next=n; }
int main(){ Node* head=nullptr; append(head,10); append(head,20); append(head,30); append(head,40); cout<<"2nd from end: "<<nthFromEnd(head,2)<<endl; return 0; }
