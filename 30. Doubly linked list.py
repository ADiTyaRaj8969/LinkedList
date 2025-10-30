class Node:
    def __init__(self,data):
        self.data=data; self.next=None; self.prev=None

class DoublyLinkedList:
    def __init__(self): self.head=None
    def push_front(self,val):
        n=Node(val); n.next=self.head
        if self.head: self.head.prev=n
        self.head=n
    def insert_after(self,prev,val):
        if not prev: return
        n=Node(val); n.next=prev.next; prev.next=n; n.prev=prev
        if n.next: n.next.prev=n
    def delete_node(self,del_node):
        if not self.head or not del_node: return
        if self.head==del_node: self.head=del_node.next
        if del_node.next: del_node.next.prev=del_node.prev
        if del_node.prev: del_node.prev.next=del_node.next
    def print_forward(self):
        cur=self.head
        while cur:
            print(cur.data, end=' '); cur=cur.next
        print()

if __name__=='__main__':
    dll=DoublyLinkedList(); dll.push_front(2); dll.push_front(1); dll.insert_after(dll.head,3); dll.print_forward(); dll.delete_node(dll.head.next); dll.print_forward()
