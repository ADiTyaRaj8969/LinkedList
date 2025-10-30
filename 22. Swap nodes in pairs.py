class Node:
    def __init__(self,data): self.data=data; self.next=None

def swap_pairs(head):
    dummy=Node(0); dummy.next=head
    prev=dummy
    while prev.next and prev.next.next:
        a=prev.next; b=a.next
        prev.next=b; a.next=b.next; b.next=a
        prev=a
    return dummy.next

def print_list(h):
    cur=h; out=[]
    while cur:
        out.append(str(cur.data)); cur=cur.next
    print(' -> '.join(out))

if __name__=='__main__':
    head=Node(1); head.next=Node(2); head.next.next=Node(3); head.next.next.next=Node(4)
    head=swap_pairs(head)
    print_list(head)
