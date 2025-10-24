"""
Task: Insert nodes at the beginning of a singly linked list
Time Complexity: O(1) per insert at front
Space Complexity: O(n)
"""


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def push_front(self, val):
        n = Node(val)
        n.next = self.head
        self.head = n

    def print_list(self):
        cur = self.head
        out = []
        while cur:
            out.append(str(cur.data))
            cur = cur.next
        print(' -> '.join(out))


if __name__ == '__main__':
    ll = LinkedList()
    ll.push_front(30)
    ll.push_front(20)
    ll.push_front(10)
    print('After inserting at beginning: ', end='')
    ll.print_list()

# Task: Insert nodes at the beginning of a singly linked list
