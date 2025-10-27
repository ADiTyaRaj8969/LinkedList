class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

def remove_loop(head):
    if not head: return
    slow=head; fast=head; found=False
    while fast and fast.next:
        slow=slow.next
        fast=fast.next.next
        if slow==fast:
            found=True
            break
    if not found: return
    slow=head
    if slow==fast:
        while fast.next!=slow:
            fast=fast.next
        fast.next=None
        return
    while slow.next!=fast.next:
        slow=slow.next
        fast=fast.next
    fast.next=None

if __name__=='__main__':
    head=Node(1); head.next=Node(2); head.next.next=Node(3); head.next.next.next=Node(4); head.next.next.next.next=head.next
    remove_loop(head)
    cur=head
    while cur:
        print(cur.data, end=' ')
        cur=cur.next
    print()
