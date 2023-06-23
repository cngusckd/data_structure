MAX_QUEUE_SIZE = 3          # Queue의 최대 크기

class Queue:
    def __init__(self):
        self.queue = [0] * MAX_QUEUE_SIZE
        self.front = -1
        self.rear = -1
        
    def is_empty(self):         # Queue가 비어있는지 확인
        return self.front == self.rear
    
    def is_full(self):          # Queue가 꽉 차 있는지 확인
        return self.rear == MAX_QUEUE_SIZE - 1
    
    def push(self, data):       # Queue에 data 삽입
        if self.is_full():
            print("Queue is full")
            exit(-1)
        self.rear += 1
        self.queue[self.rear] = data
        
    def pop(self):               # Queue에서 data를 반환하고 삭제
        if self.is_empty():
            print("Queue is empty")
            exit(-1)
        return self.queue[self.front]
    
    def peek(self):              # Queue에서 data를 반환하고 삭제 X
        if self.is_empty():
            print("Queue is empty")
            exit(-1)
        return self.queue[self.front + 1]
    
if __name__ == "__main__":
    q = Queue()
    q.push(1)
    q.push(2)
    q.push(3)
    
    print(q.is_full())      # True
    print(q.pop())          # 1
    print(q.pop())          # 2
    print(q.peek())         # 3
    print(q.pop())          # 3
    print(q.is_empty())     # True