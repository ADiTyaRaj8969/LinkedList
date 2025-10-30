class Node:
    def __init__(self,data): self.data=data; self.next=None

def get_count(head):
    c=0
    while head:
        c+=1; head=head.next
    return c

def get_intersection(a,b):
    c1=get_count(a); c2=get_count(b)
    d=abs(c1-c2)
    if c1>c2:
        for _ in range(d): a=a.next
    else:
        for _ in range(d): b=b.next
    while a and b:
        if a is b: return a
        a=a.next; b=b.next
    return None

if __name__=='__main__':
    common=Node(8); common.next=Node(10)
    a=Node(3); a.next=Node(6); a.next.next=common
    b=Node(4); b.next=common
    inter=get_intersection(a,b)
    print('Intersection at:', inter.data if inter else None)
