#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
int getCount(Node* head){ int c=0; while(head){ c++; head=head->next; } return c; }
Node* getIntersection(Node* a, Node* b){ int c1=getCount(a); int c2=getCount(b); int d=abs(c1-c2); if(c1>c2){ for(int i=0;i<d;i++) a=a->next; } else { for(int i=0;i<d;i++) b=b->next; } while(a && b){ if(a==b) return a; a=a->next; b=b->next; } return nullptr; }
int main(){ Node* common=new Node(8); common->next=new Node(10);
    Node* a=new Node(3); a->next=new Node(6); a->next->next=common;
    Node* b=new Node(4); b->next=common;
    Node* inter=getIntersection(a,b);
    if(inter) cout<<"Intersection at: "<<inter->data<<endl; else cout<<"No intersection"<<endl;
    return 0; }
