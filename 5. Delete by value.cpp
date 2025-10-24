/*
 Task: Delete nodes by value from a singly linked list
 Time Complexity: O(n)
 Space Complexity: O(1)
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

void delete_value(Node*& head, int val)
{
    if (!head)
    {
        return;
    }

    while (head && head->data == val)
    {
        Node* t = head;
        head = head->next;
        delete t;
    }

    Node* cur = head;
    while (cur && cur->next)
    {
        if (cur->next->data == val)
        {
            Node* t = cur->next;
            cur->next = t->next;
            delete t;
        }
        else
        {
            cur = cur->next;
        }
    }
}

void append(Node*& h, int v)
{
    Node* n = new Node(v);
    if (!h)
    {
        h = n;
        return;
    }

    Node* c = h;
    while (c->next)
    {
        c = c->next;
    }

    c->next = n;
}

void print(Node* h)
{
    while (h)
    {
        cout << h->data;
        if (h->next)
        {
            cout << " -> ";
        }
        h = h->next;
    }

    cout << endl;
}

int main()
{
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 20);
    append(head, 30);

    cout << "Before delete: ";
    print(head);
    delete_value(head, 20);
    cout << "After deleting 20s: ";
    print(head);
    return 0;
}

// sc tc
