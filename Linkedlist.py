class Node:
    def __init__(self,value,next = None):
        self.value = value
        self.next = next


class Linkedlist:
    def __init__(self,head):
        self.head = None
    
    def tail_append(self,value):
        if self.head is None:
            self.head = Node(value)
        else:
            curr = self.head
            while(curr.next):
                curr = curr.next
            curr.next = Node(value)
    
    def head_append(self,value):
        if self.head is None:
            self.head = Node(value)
        else:
            self.head = Node(value, self.head)
