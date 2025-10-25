"""
Task: Reverse a singly linked list (recursive)
Time Complexity: O(n)
Space Complexity: O(n) recursion stack
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

    def reverse_rec_util(self, node):
        if not node or not node.next:
            return node
        rest = self.reverse_rec_util(node.next)
        node.next.next = node
        node.next = None
        return rest

    def reverse_rec(self):
        self.head = self.reverse_rec_util(self.head)

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
    ll.reverse_rec()
    print('After reverse recursive: ', end='')
    ll.print_list()

# Task: Reverse a singly linked list (recursive)
