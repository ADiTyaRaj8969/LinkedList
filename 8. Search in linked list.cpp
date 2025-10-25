#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};

bool search(Node* head,int key){ while(head){ if(head->data==key) return true; head=head->next; } return false; }
void append(Node*& h,int v){ Node* n=new Node(v); if(!h){h=n;return;} Node* c=h; while(c->next) c=c->next; c->next=n; }
int main(){ Node* head=nullptr; append(head,10); append(head,20); append(head,30); cout<<"Search 20: "<<(search(head,20)?"Found":"Not Found")<<endl; cout<<"Search 40: "<<(search(head,40)?"Found":"Not Found")<<endl; return 0; }
