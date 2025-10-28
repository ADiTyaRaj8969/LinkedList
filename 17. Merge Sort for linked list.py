class Node:
    def __init__(self,data): self.data=data; self.next=None

def merge(a,b):
    if not a: return b
    if not b: return a
    if a.data<=b.data:
        a.next=merge(a.next,b)
        return a
    else:
        b.next=merge(a,b.next)
        return b

def get_mid(head):
    if not head: return head
    slow=head; fast=head.next
    while fast and fast.next:
        slow=slow.next; fast=fast.next.next
    mid=slow.next; slow.next=None
    return mid

def merge_sort(head):
    if not head or not head.next: return head
    mid=get_mid(head)
    left=head; right=mid
    left=merge_sort(left); right=merge_sort(right)
    return merge(left,right)

def print_list(h):
    cur=h; out=[]
    while cur:
        out.append(str(cur.data)); cur=cur.next
    print(' -> '.join(out))

if __name__=='__main__':
    head=Node(4); head.next=Node(2); head.next.next=Node(1); head.next.next.next=Node(3)
    head=merge_sort(head)
    print_list(head)
