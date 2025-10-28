class Node:
    def __init__(self,data): self.data=data; self.next=None

def remove_dup(head):
    cur=head
    while cur and cur.next:
        if cur.data==cur.next.data:
            cur.next=cur.next.next
        else:
            cur=cur.next
    return head

def print_list(h):
    cur=h; out=[]
    while cur:
        out.append(str(cur.data)); cur=cur.next
    print(' -> '.join(out))

if __name__=='__main__':
    head=Node(1); head.next=Node(1); head.next.next=Node(2); head.next.next.next=Node(3); head.next.next.next.next=Node(3)
    head=remove_dup(head)
    print_list(head)
