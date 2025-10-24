"""
Task: Insert a node at a given position in a singly linked list
Time Complexity: O(n) to reach position
Space Complexity: O(n)
"""


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def insert_pos(self, val, pos):
        n = Node(val)
        if pos <= 0 or not self.head:
            n.next = self.head
            self.head = n
            return

        cur = self.head
        for _ in range(pos - 1):
            if not cur.next:
                break
            cur = cur.next

        n.next = cur.next
        cur.next = n

    def print_list(self):
        cur = self.head
        out = []
        while cur:
            out.append(str(cur.data))
            cur = cur.next
        print(' -> '.join(out))


if __name__ == '__main__':
    ll = LinkedList()
    ll.insert_pos(10, 0)
    ll.insert_pos(30, 1)
    ll.insert_pos(20, 1)
    print('After inserts at positions: ', end='')
    ll.print_list()

# Task: Insert a node at a given position in a singly linked list
