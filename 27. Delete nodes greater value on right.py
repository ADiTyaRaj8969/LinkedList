class Node:
    def __init__(self,data): self.data=data; self.next=None

def delete_greater_right(head):
    # reverse
    prev=None; cur=head
    while cur:
        nxt=cur.next; cur.next=prev; prev=cur; cur=nxt
    new_head=prev
    max_so_far=new_head.data
    t=new_head
    while t and t.next:
        if t.next.data<max_so_far:
            t.next=t.next.next
        else:
            t=t.next; max_so_far=t.data
    # reverse back
    prev=None; cur=new_head
    while cur:
        nxt=cur.next; cur.next=prev; prev=cur; cur=nxt
    return prev

def print_list(h):
    cur=h
    while cur:
        print(cur.data, end=' '); cur=cur.next
    print()

if __name__=='__main__':
    head=Node(12); head.next=Node(15); head.next.next=Node(10); head.next.next.next=Node(11); head.next.next.next.next=Node(5); head.next.next.next.next.next=Node(6)
    head=delete_greater_right(head)
    print_list(head)
