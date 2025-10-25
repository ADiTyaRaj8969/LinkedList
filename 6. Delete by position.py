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

    def delete_pos(self, pos):
        if not self.head:
            return
        if pos <= 0:
            self.head = self.head.next
            return
        cur = self.head
        for _ in range(pos - 1):
            if not cur.next:
                return
            cur = cur.next
        if cur.next:
            cur.next = cur.next.next

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
    ll.append(40)
    print('Before: ', end='')
    ll.print_list()
    ll.delete_pos(2)
    print('After deleting position 2: ', end='')
    ll.print_list()
