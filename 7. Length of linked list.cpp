#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};

int length(Node* head){ int cnt=0; while(head){ cnt++; head=head->next; } return cnt; }

void append(Node*& h,int v){ Node* n=new Node(v); if(!h){h=n;return;} Node* c=h; while(c->next) c=c->next; c->next=n; }
int main(){ Node* head=nullptr; append(head,10); append(head,20); append(head,30); cout<<"Length: "<<length(head)<<endl; return 0; }
