#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};

void insert_pos(Node*& head,int val,int pos){ // pos: 0-based
    Node* n=new Node(val);
    if(pos<=0 || !head){ n->next=head; head=n; return; }
    Node* cur=head; for(int i=0;i<pos-1 && cur->next;i++) cur=cur->next;
    n->next=cur->next; cur->next=n;
}
void print(Node* h){ while(h){ cout<<h->data; if(h->next) cout<<" -> "; h=h->next; } cout<<endl; }
int main(){ Node* head=nullptr; insert_pos(head,10,0); insert_pos(head,30,1); insert_pos(head,20,1); cout<<"After inserts at positions: "; print(head); return 0; }
