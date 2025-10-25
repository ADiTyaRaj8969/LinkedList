"""
Task: Reverse a singly linked list (iterative)
Time Complexity: O(n)
Space Complexity: O(1)
"""

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, val):
        n = Node(val)
        if not self.head:
            self.head = n
            return
        cur = self.head
        while cur.next:
            cur = cur.next
        cur.next = n

    def reverse_iter(self):
        prev = None
        cur = self.head
        while cur:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        self.head = prev

    def print_list(self):
        cur = self.head
        out = []
        while cur:
            out.append(str(cur.data))
            cur = cur.next
        print(' -> '.join(out))


if __name__ == '__main__':
    ll = LinkedList()
    ll.append(10)
    ll.append(20)
    ll.append(30)
    print('Before: ', end='')
    ll.print_list()
    ll.reverse_iter()
    print('After reverse iterative: ', end='')
    ll.print_list()

# Task: Reverse a singly linked list (iterative)
