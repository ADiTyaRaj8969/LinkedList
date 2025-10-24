#include <iostream>
using namespace std;

struct Node { int data; Node* next; Node(int d):data(d),next(nullptr){} };

void push_front(Node*& head, int val){ Node* n=new Node(val); n->next=head; head=n; }
void print(Node* head){ while(head){ cout<<head->data; if(head->next) cout<<" -> "; head=head->next;} cout<<endl; }

int main(){ Node* head=nullptr; push_front(head,30); push_front(head,20); push_front(head,10); cout<<"After inserting at beginning: "; print(head); return 0; }
