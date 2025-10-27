class Node:
    def __init__(self,data):
        self.data=data; self.next=None

def nth_from_end(head,n):
    first=head; second=head
    for _ in range(n):
        if not first: return None
        first=first.next
    while first:
        first=first.next; second=second.next
    return second

if __name__=='__main__':
    head=Node(10); head.next=Node(20); head.next.next=Node(30); head.next.next.next=Node(40)
    node=nth_from_end(head,2)
    print('2nd from end:', node.data if node else None)
