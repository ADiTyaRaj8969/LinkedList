/*
 Task: Reverse a singly linked list (iterative)
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

Node* reverse_iter(Node* head)
{
	Node* prev = nullptr;
	Node* cur = head;
	while (cur)
	{
		Node* nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}

	return prev;
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
	append(head, 30);

	cout << "Before: ";
	print(head);
	head = reverse_iter(head);
	cout << "After reverse iterative: ";
	print(head);
	return 0;
}

// sc tc
