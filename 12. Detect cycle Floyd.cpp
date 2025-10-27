/*
 Task: Detect cycle in linked list (Floyd's algorithm)
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

bool hasCycle(Node* head)
{
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = head->next; // introduce cycle

	cout << "Has cycle: " << (hasCycle(head) ? "Yes" : "No") << endl;
	return 0;
}

// sc tc
