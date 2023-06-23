class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0
        
    def size(self):
        return self.size
    
    def addAtHead(self, data):
        node = Node(data)
        node.next = self.head
        self.head = node
        self.size += 1
        
    def addBack(self, data):
        if self.size == 0:
            self.addAtHead(data)
            return;
        else:
            node = Node(data)
            crntnode = self.head
            while crntnode.next:
                crntnode = crntnode.next
            crntnode.next = node
            self.size += 1
        
    def findNode(self, data):
        crntnode = self.head
        while crntnode is not None:
            if crntnode.data == data:
                return crntnode
            crntnode = crntnode.next
        raise RuntimeError("Node not Found")

    def addAt(self, index, data):
        if self.size < index:
            print("[!] Index Out of Range")
            return -1
        selected_node = self.head
        i = 1
        
        if index == 1:
            self.addAtHead(data)
            return
        while(i != index):
            selected_node = selected_node.next
            i += 1
        new_node = Node(data)
        new_node.next = selected_node.next
        selected_node.next = new_node
        self.size += 1
        
    def delete(self, index):
        if self.size < index or self.size == 0:
            print("[!] Index Out of Range")
            return -1
        selected_node = self.head
        i = 1
        if(index == 1):
            self.head = self.head.next
            return
        
        while(i < index - 1):
            selected_node = selected_node.next
            i += 1
        selected_node.next = selected_node.next.next
        self.size -= 1
        
    def print(self):
        crntnode = self.head
        while crntnode != None:
            print(crntnode.data, end =" ")
            crntnode = crntnode.next
        print()
        
class LinkedQueue:
    def __init__(self, size):
        self.llist = LinkedList()
        self.size = size
        self.top = -1
        
    def is_empty(self):
        if self.top == -1:
            return True
        else:
            return False
    
    def is_full(self):
        if self.top == self.size - 1:
            return True
        else:
            return False
        
    def push(self, data):
        self.llist.addBack(data)
        self.top += 1
        
    def pop(self):
        data = self.llist.head.data
        if self.top == -1:
            print("[!] stack is empty")
        self.llist.delete(1)
        self.top -= 1
        return data
        
    def peek(self):
        return self.llist.head.data
    
if __name__ == "__main__":
    queue = LinkedQueue(4)
    
    queue.push(1)
    queue.push(2)
    queue.push(3)
    queue.push(4)
    
    print(queue.is_full())
    queue.pop()
    queue.pop()
    print(queue.peek())
    print(queue.is_empty())