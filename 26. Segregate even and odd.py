class Node:
    def __init__(self,data): self.data=data; self.next=None

def segregate(head):
    oddStart=oddEnd=evenStart=evenEnd=None
    cur=head
    while cur:
        if cur.data%2==0:
            if not evenStart:
                evenStart=evenEnd=cur
            else:
                evenEnd.next=cur; evenEnd=evenEnd.next
        else:
            if not oddStart:
                oddStart=oddEnd=cur
            else:
                oddEnd.next=cur; oddEnd=oddEnd.next
        cur=cur.next
    if not evenStart: return oddStart
    evenEnd.next=oddStart
    if oddEnd: oddEnd.next=None
    return evenStart

def print_list(h):
    cur=h
    while cur:
        print(cur.data, end=' '); cur=cur.next
    print()

if __name__=='__main__':
    head=Node(17); head.next=Node(15); head.next.next=Node(8); head.next.next.next=Node(12); head.next.next.next.next=Node(10); head.next.next.next.next.next=Node(5)
    head=segregate(head)
    print_list(head)
