#include <iostream>

#define MAX_QUEUE_SIZE 3        // queue의 최대 크기

typedef int element;            // 데이터 변수 정의
typedef struct {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
}Queue;                         // Queue 구조체

void init(Queue *q){            // Queue 초기화
    q->front = q->rear = -1;
}

bool is_full(Queue *q){         // Queue가 꽉 차 있는지 확인
    return q->rear == MAX_QUEUE_SIZE - 1;
}

bool is_empty(Queue *q){        // Queue가 비어있는지 확인
    return q->front == q->rear;
}

void push(Queue *q, element e){            // Queue 삽입
    if(is_full(q)){
        std::cerr << "Queue is full\n";
        exit(-1);
    }
    q->queue[++q->rear] = e;
}

element pop(Queue *q){          // Queue pop, (원소 삭제됨)
    if(is_empty(q)){
        std::cerr << "Queue is empty\n";
        exit(-1);
    }
    return q->queue[++q->front];
}

element peek(Queue *q){         // Queue peek, (원소 삭제되지않음)
    if(is_empty(q)){
        std::cerr << "Queue is empty\n";
        exit(-1);
    }
    return q->queue[q->front + 1];
}

int main(){
    Queue q;        // Queue 선언

    init(&q);       // queue초기화
    push(&q, 1);
    push(&q, 2);
    push(&q, 3);

    std::cout << std::boolalpha << is_full(&q) << "\n";     // true
    std::cout << pop(&q) << "\n";                           // 1
    std::cout << pop(&q) << "\n";                           // 2        
    std::cout << peek(&q) << "\n";                          // 3
    std::cout << pop(&q) << "\n";                           // 3
    std::cout << std::boolalpha << is_empty(&q) << "\n";    // true
}
