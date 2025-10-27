#include <iostream>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
void removeLoop(Node* head){ if(!head) return; Node* slow=head; Node* fast=head; bool found=false; while(fast && fast->next){ slow=slow->next; fast=fast->next->next; if(slow==fast){ found=true; break; } }
    if(!found) return; slow=head; if(slow==fast){ // loop at head
        while(fast->next!=slow) fast=fast->next;
        fast->next=nullptr; return;
    }
    while(slow->next!=fast->next){ slow=slow->next; fast=fast->next; }
    fast->next=nullptr;
}
int main(){ Node* head=new Node(1); head->next=new Node(2); head->next->next=new Node(3); head->next->next->next=new Node(4); head->next->next->next->next=head->next; removeLoop(head); Node* cur=head; while(cur){ cout<<cur->data<<" "; cur=cur->next; } cout<<endl; return 0; }
