class PriorityQueueBase:
    class Item:
        slots = '_key' , '_value'
        def __init__(self, k, v):
            self.key = k
            self.value = v

        def lt(self, other):
            return self.key < other.key # compare items based on their keys

    def is_empty(self): # concrete method assuming abstract len
        return len(self.data) == 0
    
class HeapPriorityQueue(PriorityQueueBase): # base class defines Item
    
    def __init__(self):
        self.data = []

    def len(self):
        return len(self.data)
    
    def parent(self, j):
        return (j-1) // 2
    
    def left(self, j):
        return 2*j+1
    
    def right(self, j):
        return 2*j+2

    def has_left(self, j):
        return self.left(j) < len(self.data) # index beyond end of list?

    def has_right(self, j):
        return self.right(j) < len(self.data) # index beyond end of list?

    def swap(self, i, j):
        self.data[i], self.data[j] = self.data[j], self.data[i]

    def upheap(self, j):
        parent = self.parent(j)
        if j > 0 and self.data[j].value < self.data[parent].value:
            self.swap(j, parent)
            self.upheap(parent) # recur at position of parent

    def downheap(self, j):
        if self.has_left(j):
            left = self.left(j)
            small_child = left # although right may be smaller
            if self.has_right(j):
                right = self.right(j)
                if self.data[right].value < self.data[left].value:
                    small_child = right
            if self.data[small_child].value < self.data[j].value:
                self.swap(j, small_child)
                self.downheap(small_child) # recur at position of small child

    def insert(self, key, value):
        self.data.append(self.Item(key, value))
        self.upheap(len(self.data) - 1) # upheap newly added position

    def min(self):
        if self.is_empty():
            assert 'Priority queue is empty.'
        item = self. data[0]
        return (item.key, item.value)


    def remove_min(self):
        if self.is_empty():
            assert 'Priority queue is empty.'
        self.swap(0, len(self.data) - 1) # put minimum item at the end
        item = self.data.pop( ) # and remove it from the list;
        self.downheap(0) # then fix new root
        return (item.key, item.value)
    
    def print(self):
        for i in range(len(self.data)):
            print(HPQ.data[i].key, end=" ")

if __name__ == '__main__':
    HPQ = HeapPriorityQueue()   # Min Heap을 이용한 PriorityQueue 구현.
    
    suggested_array = [ 27, 15, 14, 6, 31, 45, 10, 42, 38, 17 ]
    for i in suggested_array:
        HPQ.insert(i, i)
    
    print("37 삽입 전")
    HPQ.print()
    HPQ.insert(37, 37)
    print()
    print("37삽입후")
    HPQ.print()
    print()
    print()
    print()
    
    for i in [6, 45]:
        
        remove_target = i
        
        if remove_target == 6:
            print('removing 6 mean remove minimum')
            HPQ.remove_min()
            HPQ.print()
            print()
