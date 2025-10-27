class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

class LinkedList:
    def __init__(self):
        self.head=None
    def append(self,val):
        n=Node(val)
        if not self.head:
            self.head=n
            return
        cur=self.head
        while cur.next:
            cur=cur.next
        cur.next=n
    def middle(self):
        slow=self.head
        fast=self.head
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
        return slow
    def print(self):
        cur=self.head; out=[]
        while cur:
            out.append(str(cur.data)); cur=cur.next
        print(' -> '.join(out))

if __name__=='__main__':
    ll=LinkedList(); ll.append(10); ll.append(20); ll.append(30); ll.append(40); ll.append(50)
    ll.print()
    mid=ll.middle()
    if mid: print('Middle:', mid.data)
