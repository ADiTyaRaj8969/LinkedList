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

def print_list(h):
    cur=h; out=[]
    while cur:
        out.append(str(cur.data)); cur=cur.next
    print(' -> '.join(out))

if __name__=='__main__':
    a=Node(1); a.next=Node(3); a.next.next=Node(5)
    b=Node(2); b.next=Node(4); b.next.next=Node(6)
    m=merge(a,b)
    print_list(m)
