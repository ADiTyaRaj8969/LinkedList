class Node:
    def __init__(self,data): self.data=data; self.next=None

def add_lists(a,b):
    head=None; tail=None; carry=0
    while a or b or carry:
        s=carry
        if a:
            s+=a.data; a=a.next
        if b:
            s+=b.data; b=b.next
        node=Node(s%10)
        carry=s//10
        if not head:
            head=tail=node
        else:
            tail.next=node; tail=node
    return head

def print_list(h):
    cur=h; out=[]
    while cur:
        out.append(str(cur.data)); cur=cur.next
    print(' -> '.join(out))

if __name__=='__main__':
    a=Node(2); a.next=Node(4); a.next.next=Node(3)
    b=Node(5); b.next=Node(6); b.next.next=Node(4)
    s=add_lists(a,b)
    print_list(s)
