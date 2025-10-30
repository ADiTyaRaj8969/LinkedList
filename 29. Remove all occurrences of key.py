class Node:
    def __init__(self,data): self.data=data; self.next=None

def remove_all(head,key):
    while head and head.data==key:
        head=head.next
    cur=head
    while cur and cur.next:
        if cur.next.data==key:
            cur.next=cur.next.next
        else:
            cur=cur.next
    return head

def print_list(h):
    cur=h
    while cur:
        print(cur.data, end=' '); cur=cur.next
    print()

if __name__=='__main__':
    head=Node(1); head.next=Node(2); head.next.next=Node(1); head.next.next.next=Node(3)
    head=remove_all(head,1)
    print_list(head)
