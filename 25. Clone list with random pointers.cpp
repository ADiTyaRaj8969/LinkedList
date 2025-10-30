/*
 Task: Clone a linked list with next and random pointers
 Time Complexity: O(n)
 Space Complexity: O(n) using a hash map
*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* random;

    Node(int d)
        : data(d)
        , next(nullptr)
        , random(nullptr)
    {
    }
};

Node* clone(Node* head)
{
    if (!head)
    {
        return nullptr;
    }

    unordered_map<Node*, Node*> m;
    Node* cur = head;
    while (cur)
    {
        m[cur] = new Node(cur->data);
        cur = cur->next;
    }

    cur = head;
    while (cur)
    {
        m[cur]->next = m[cur->next];
        m[cur]->random = m[cur->random];
        cur = cur->next;
    }

    return m[head];
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next;
    head->next->random = head;

    Node* c = clone(head);
    cout << c->data << " " << c->next->data << " " << c->random->data << endl;
    return 0;
}

// sc tc
