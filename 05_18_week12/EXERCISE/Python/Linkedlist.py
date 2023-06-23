class Node:                     # 각각의 Node
    def __init__(self, data):
        self.data = data
        self.next = None
        
class LinkedList:
    def __init__(self):             #초기화
        self.head = None
        self.size = 0
        
    def size(self):             # linked list 크기 반환
        return self.size
    
    def addAtHead(self, data):      # head에 data 추가
        node = Node(data)
        node.next = self.head
        self.head = node
        self.size += 1
        
    def addBack(self, data):        # tail에 data 추가
        node = Node(data)
        crnt_node = self.head
        # 현재 맨 뒤의 노드 탐색
        while crnt_node.next:
            crnt_node = crnt_node.next;
        crnt_node.next = node
        self.size += 1
        
    def findNode(self, data):       # data와 같은 Node탐색
        crnt_node = self.head
        while crnt_node is not None:
            if crnt_node.data == data:
                return crnt_node
            crnt_node = crnt_node.next
        raise RuntimeError("Node not found")
    
    def addAt(self, index, data):       # 특정 index에 data 삽입
        if(self.size < index):          # index 오버플로우 체크
            print("[!] Index Out of Range")
            return -1
        select_node = self.head
        i = 1
        
        if(index == 0):
            self.addAtHead(data)
            return
        
        while(i != index):
            select_node = select_node.next
            i += 1
        
        new_node = Node(data)
        new_node.next = select_node.next
        select_node.next = new_node
        self.size += 1
        
    def delete(self, index): # O(1), 특정 index의 data 삭제
        if(self.size < index):          # index 오버플로우 체크
            print("[!] Index Out of Range")
            return -1
        select_node = self.head
        i = 1
        if( index == 1 ):
            self.head = self.head.next
            return
        
        while( i < index - 1 ):
            select_node = select_node.next
            i += 1
        select_node.next = select_node.next.next
        self.size += 1
        
    def print(self):    # 모든 data 출력
        crnt_node = self.head
        while crnt_node is not None:
            print(crnt_node.data, end = " ")
            crnt_node = crnt_node.next
        print()
        
if __name__ == "__main__":
    ll = LinkedList()
    ll.addAtHead(5)
    ll.print()
    
    ll.addBack(12)
    ll.print()
    
    ll.addBack(12)
    ll.print()
    
    ll.addAt(2, 24)
    ll.print()
    
    ll.delete(2)
    ll.print()