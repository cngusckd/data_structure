public class Stack_Java {
    private static final int MAX_STACK_SIZE = 3;        // 스택 최대 크기
    private int[] stack;                        // 배열이용
    private int top;

    public Stack_Java() {               // 생성자
        stack = new int[MAX_STACK_SIZE];
        top = -1;
    }

    public boolean isEmpty(){           // 비어있는지 확인
        return top == -1;
    }

    public boolean isFull(){            // 가득 차 있는지 확인
        return top == MAX_STACK_SIZE - 1;
    }

    public int peek(){                  // top의 data를 삭제하지않고 반환
        if (isEmpty()){
            System.out.println("Stack is Empty");
            System.exit(-1);
        }
        return stack[top];
    }
    
    public void push(int data){         // data 삽입
        if (isFull()){
            System.err.println("Stack is Full");
            System.exit(-1);
        }
        stack[++top] = data;
    }

    public int pop(){                   // top 의 data를 삭제하고 반환
        if (isEmpty()){
            System.err.println("Stack is Empty");
            System.exit(-1);
        }
        return stack[top--];
    }
    public static void main(String[] args) throws Exception {
        Stack_Java stack = new Stack_Java();

        stack.push(1);
        stack.push(2);
        stack.push(3);

        System.out.println(stack.isFull());
        System.out.println(stack.pop());
        System.out.println(stack.pop());
        System.out.println(stack.peek());
        System.out.println(stack.pop());
        System.out.println(stack.isEmpty());
    }
}
