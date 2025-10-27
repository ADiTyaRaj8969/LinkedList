class Node:
    def __init__(self,data): self.data=data; self.next=None

def is_palindrome(head):
    slow=head; fast=head; stack=[]
    while fast and fast.next:
        stack.append(slow.data)
        slow=slow.next; fast=fast.next.next
    if fast:
        slow=slow.next
    while slow:
        if stack.pop()!=slow.data:
            return False
        slow=slow.next
    return True

if __name__=='__main__':
    head=Node(1); head.next=Node(2); head.next.next=Node(2); head.next.next.next=Node(1)
    print('Palindrome' if is_palindrome(head) else 'Not Palindrome')
