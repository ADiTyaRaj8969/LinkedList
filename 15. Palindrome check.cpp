#include <iostream>
#include <stack>
using namespace std; struct Node{int data; Node* next; Node(int d):data(d),next(nullptr){}
};
void append(Node*& h,int v){ Node* n=new Node(v); if(!h){h=n;return;} Node* c=h; while(c->next) c=c->next; c->next=n; }
bool isPalindrome(Node* head){ Node* slow=head; Node* fast=head; stack<int> st; while(fast && fast->next){ st.push(slow->data); slow=slow->next; fast=fast->next->next; }
    if(fast) slow=slow->next; while(slow){ if(st.top()!=slow->data) return false; st.pop(); slow=slow->next; } return true; }
int main(){ Node* head=nullptr; append(head,1); append(head,2); append(head,2); append(head,1); cout<<(isPalindrome(head)?"Palindrome":"Not Palindrome")<<endl; return 0; }
