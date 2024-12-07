#include <iostream>
using namespace std;
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};
ListNode* addOne(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* nextNode = nullptr;
    while (current) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev; 
    ListNode* temp = head;
    int carry = 1;
    while (temp) {
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;

        if (!temp->next && carry > 0) {
            temp->next = new ListNode(carry);
            break;
        }
        temp = temp->next;
    }
    prev = nullptr;
    current = head;
    while (current) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}
void printList(ListNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}
int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(6);
    cout << "Original List: ";
    printList(head);
    head = addOne(head);
    cout << "After Adding 1: ";
    printList(head);

    return 0;
}
