"""
Task: Clone a linked list with next and random pointers
Time Complexity: O(n)
Space Complexity: O(n) using a hash map
"""


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.random = None


def clone(head):
    if not head:
        return None

    old_to_new = {}
    cur = head
    while cur:
        old_to_new[cur] = Node(cur.data)
        cur = cur.next

    cur = head
    while cur:
        old_to_new[cur].next = old_to_new.get(cur.next)
        old_to_new[cur].random = old_to_new.get(cur.random)
        cur = cur.next

    return old_to_new[head]


if __name__ == '__main__':
    head = Node(1)
    head.next = Node(2)
    head.next.next = Node(3)
    head.random = head.next.next
    head.next.random = head
    c = clone(head)
    print(c.data, c.next.data, c.random.data)

# Task: Clone a linked list with next and random pointers
