"""
Task: Insert nodes at end of a singly linked list
Time Complexity: O(n) per append (as implemented)
Space Complexity: O(n)
"""

class Node:
    def __init__(self,data): self.data=data; self.next=None

class LinkedList:
    def __init__(self): self.head=None
    def insert_end(self,val):
        n=Node(val)
        if not self.head:
            self.head=n; return
        cur=self.head
        while cur.next: cur=cur.next
        cur.next=n
    def print(self):
        cur=self.head; out=[]
        while cur: out.append(str(cur.data)); cur=cur.next
        print(' -> '.join(out))

if __name__=='__main__':
    ll=LinkedList(); ll.insert_end(10); ll.insert_end(20); ll.insert_end(30)
    print('After inserting at end: ', end=''); ll.print()
