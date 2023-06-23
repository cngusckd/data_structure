import heapq        # min heap

class PriorityQueue:
    def __init__(self):
        self.queue = []
        self.index = 0
    
    def insert(self, item, priority):
        heapq.heappush(self.queue, (priority, self.index, item))
        self.index += 1
    
    def dequeue(self):
        return heapq.heappop(self.queue)[-1]
    
    def peek(self):
        return self.queue[0][-1]
    
    def find(self, item):
        index = 0
        while(True):
            if self.queue[index] == item:
                return index
            else:
                return None 
    
if  __name__ == "__main__":

    pq = PriorityQueue()

    array = [ 27, 15, 14, 6, 31, 45, 10, 42, 38, 17 ]

    for i in array:
        pq.insert(i, i)         # item, priority 순으로 입력
    
    #print(pq._queue.sort())    # priority, index, item순
    for priority, index, item in pq.queue:
        print(index, item, priority)
    print(pq.peek())