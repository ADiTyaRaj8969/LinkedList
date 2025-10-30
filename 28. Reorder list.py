class Node:
    def __init__(self,data): self.data=data; self.next=None

def reorder(head):
    if not head: return
    vals=[]; cur=head
    while cur:
        vals.append(cur)
        cur=cur.next
    i=0; j=len(vals)-1
    while i<j:
        vals[i].next=vals[j]; i+=1
        if i==j: break
        vals[j].next=vals[i]; j-=1
    vals[i].next=None

def print_list(h):
    cur=h
    while cur:
        print(cur.data, end=' '); cur=cur.next
    print()

if __name__=='__main__':
    head=Node(1); head.next=Node(2); head.next.next=Node(3); head.next.next.next=Node(4); head.next.next.next.next=Node(5)
    reorder(head)
    print_list(head)
