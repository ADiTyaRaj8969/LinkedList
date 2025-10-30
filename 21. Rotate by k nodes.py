class Node:
    def __init__(self,data): self.data=data; self.next=None

def rotate(head,k):
    if not head or k==0: return head
    cur=head; length=1
    while cur.next:
        cur=cur.next; length+=1
    k%=length
    if k==0: return head
    cur.next=head
    steps=length-k
    tail=cur
    while steps:
        tail=tail.next; steps-=1
    new_head=tail.next
    tail.next=None
    return new_head

def print_list(h):
    cur=h; out=[]
    while cur:
        out.append(str(cur.data)); cur=cur.next
    print(' -> '.join(out))

if __name__=='__main__':
    head=Node(1); head.next=Node(2); head.next.next=Node(3); head.next.next.next=Node(4); head.next.next.next.next=Node(5)
    head=rotate(head,2)
    print_list(head)
