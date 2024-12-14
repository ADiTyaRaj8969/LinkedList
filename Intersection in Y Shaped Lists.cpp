#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(nullptr) {}
};

// Function to find the intersection of two sorted linked lists
ListNode* findIntersection(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0); // Dummy node for the result list
    ListNode* current = dummy;

    while (l1 && l2) {
        if (l1->data == l2->data) {
            current->next = new ListNode(l1->data); // Add the intersection element
            current = current->next;
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1->data < l2->data) {
            l1 = l1->next; // Move l1 forward
        } else {
            l2 = l2->next; // Move l2 forward
        }
    }

    return dummy->next; // Return the intersection list (skip dummy node)
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from input array
ListNode* createList(int arr[], int size) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < size; i++) {
        ListNode* newNode = new ListNode(arr[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Main function to test the code
int main() {
    // Input LinkedList1 = 1->2->3->4->6, LinkedList2 = 2->4->6->8
    int arr1[] = {1, 2, 3, 4, 6};
    int arr2[] = {2, 4, 6, 8};

    ListNode* l1 = createList(arr1, 5);
    ListNode* l2 = createList(arr2, 4);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    // Find intersection
    ListNode* intersection = findIntersection(l1, l2);

    cout << "Intersection: ";
    printList(intersection);

    return 0;
}
