class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        self.child=None

def flatten(head):
    if not head: return head
    cur=head
    while cur:
        if cur.child:
            child=flatten(cur.child)
            nxt=cur.next
            cur.next=child
            t=child
            while t.next:
                t=t.next
            t.next=nxt
            cur.child=None
        cur=cur.next
    return head

def print_list(h):
    cur=h
    while cur:
        print(cur.data, end=' ')
        cur=cur.next
    print()

if __name__=='__main__':
    head=Node(1); head.next=Node(2); head.next.next=Node(3)
    head.next.child=Node(4); head.next.child.next=Node(5)
    head=flatten(head)
    print_list(head)
