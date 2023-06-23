MAX_STACK_SIZE = 3                  # stack의 최대 크기

class Stack:
    def __init__(self):             # stack 초기화
        self.stack = [0] * MAX_STACK_SIZE
        self.top = -1
        
    def is_empty(self):             # stack이 비어있는지 확인
        return self.top == -1
    
    def is_full(self):              # stack이 꽉 차 있는지 확인
        return self.top == MAX_STACK_SIZE - 1
    
    def push(self, data):           # stack에 data 삽입
        if self.is_full():
            print("Stack is Full")
            exit(-1)
        self.top += 1
        self.stack[self.top] = data
        
    def pop(self):                  # stack에서 data 반환하고 삭제
        if self.is_empty():
            print("Stack is Empty")
            exit(-1)
        return self.stack[self.top]
    
    def peek(self):                 # stack에서 data 반환하고 삭제 X
        if self.is_empty():
            print("Stack is Empty")
            exit(-1)
        return self.stack[self.top]
    
if __name__ == "__main__":
    stack = Stack()
    
    stack.push(1)
    stack.push(2)
    stack.push(3)

    print(stack.is_full())      # True
    print(stack.pop())          # 3
    print(stack.pop())          # 2
    print(stack.peek())         # 1
    print(stack.pop())          # 1
    print(stack.is_empty())     # True