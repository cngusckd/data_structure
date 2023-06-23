import java.util.NoSuchElementException;

public class Queue {
    private static final int MAX_QUEUE_SIZE = 3;
    private int[] queue = new int[MAX_QUEUE_SIZE]; // queue의 최대 크기
    private int front = -1;             // Queue의 출력구
    private int rear = -1;              // Queue의 입력구

    public void init() {        // 초기화
        front = rear = -1;
    }

    public boolean isFull(){            // queue가 꽉 차 있는지 확인
        return rear == MAX_QUEUE_SIZE - 1;
    }

    public boolean isEmpty() {          // queue가 비어있는지 확인
        return front == rear;
    }

    public void push(int e) {
        if (isFull()) {         // queue가 꽉 차 있는지 확인
            throw new IndexOutOfBoundsException("Queue is full");
        }
        queue[++rear] = e;
    }

    public int pop(){           // 맨 앞의 원소를 반환하고 삭제
        if (isEmpty()){
            throw new NoSuchElementException("Queue is empty");
        }
        return queue[++front];
    }

    public int peek(){          // 맨 앞의 원소를 반환하고 삭제하지 않음
        if(isEmpty()){
            throw new NoSuchElementException("Queue is empty");
        }
        return queue[front + 1];
    }
    public static void main(String[] args) throws Exception {
        Queue q = new Queue();

        q.init();
        q.push(1);
        q.push(2);
        q.push(3);

        System.out.println(q.isFull());         // true
        System.out.println(q.pop());            // 1
        System.out.println(q.pop());            // 2
        System.out.println(q.peek());           // 3
        System.out.println(q.pop());            // 3
        System.out.println(q.isEmpty());        // true
    }
}
