"""
Task: Delete nodes by value from a singly linked list
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
        node = Node(val)
        if not self.head:
            self.head = node
            return
        cur = self.head
        while cur.next:
            cur = cur.next
        cur.next = node

    def delete_value(self, val):
        # Remove matching nodes at the head
        while self.head and self.head.data == val:
            self.head = self.head.next

        cur = self.head
        while cur and cur.next:
            if cur.next.data == val:
                cur.next = cur.next.next
            else:
                cur = cur.next

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
    ll.append(20)
    ll.append(30)
    print('Before delete: ', end='')
    ll.print_list()
    ll.delete_value(20)
    print('After deleting 20s: ', end='')
    ll.print_list()

# Task: Delete nodes by value from a singly linked list
