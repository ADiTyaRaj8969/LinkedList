/*
 Task: Create and print a singly linked list
 Time Complexity: append O(n) (as implemented)
 Space Complexity: O(n)
*/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int d)
        : data(d)
        , next(nullptr)
    {
    }
};

void append(Node*& head, int val)
{
    Node* n = new Node(val);
    if (!head)
    {
        head = n;
        return;
    }

    Node* cur = head;
    while (cur->next)
    {
        cur = cur->next;
    }

    cur->next = n;
}

void printList(Node* head)
{
    while (head)
    {
        cout << head->data;
        if (head->next)
        {
            cout << " -> ";
        }
        head = head->next;
    }

    cout << endl;
}

int main()
{
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);

    cout << "Singly linked list: ";
    printList(head);
    return 0;
}

// sc tc
