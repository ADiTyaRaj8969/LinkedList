#include <iostream>
using namespace std;
struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};

void insert_end(Node*& head,int val){ Node* n=new Node(val); if(!head){head=n;return;} Node* cur=head; while(cur->next) cur=cur->next; cur->next=n; }
void print(Node* head){ while(head){ cout<<head->data; if(head->next) cout<<" -> "; head=head->next;} cout<<endl; }
int main(){ Node* head=nullptr; insert_end(head,10); insert_end(head,20); insert_end(head,30); cout<<"After inserting at end: "; print(head); return 0; }
