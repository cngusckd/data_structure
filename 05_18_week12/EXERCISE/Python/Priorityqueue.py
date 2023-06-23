def push(value):                # heap에 데이터 삽입
    global size, heap
    
    heap[size] = value
    index = size
    size += 1
    
    while index > 1:            # heap의 index 특성 이용, next = index // 2
        next = index // 2
        
        if heap[index] < heap[next]:
            heap[index], heap[next] = heap[next], heap[index]
            index = next
        else:
            break
        
def pop():                  # data pop 연산,
    global size, heap
    
    value = heap[1]
    size -= 1
    heap[1] = heap[size]
    index = 1
    
    while index < size:
        left = index * 2
        right = index * 2 + 1
        
        if right < size:
            if heap[left] < heap[right]:
                next = left
            else:
                next = right
        elif left < size:
            next = left
        else:
            break
        
        if heap[index] > heap[next]:
            heap[index], heap[next] = heap[next], heap[index]
            index = next
        else:
            break
    
    return value

if __name__ == "__main__":
    N = int(input())
    size = 1
    heap = [-1] * (N+1)
    
    for i in range(N):
        data = int(input())
        push(data)
        
    for i in range(N):
        print(i+1, "번째 데이터: ",pop())   #우선순위에 따른 data pop