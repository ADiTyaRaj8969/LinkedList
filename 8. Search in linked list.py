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

    def search(self, key):
        cur = self.head
        while cur:
            if cur.data == key:
                return True
            cur = cur.next
        return False

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
    print('Search 20:', 'Found' if ll.search(20) else 'Not Found')
    print('Search 40:', 'Found' if ll.search(40) else 'Not Found')
