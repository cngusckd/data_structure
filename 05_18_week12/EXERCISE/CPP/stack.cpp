#include <iostream>

#define MAX_STACK_SIZE 3

typedef int element;
typedef struct{
    element stack[MAX_STACK_SIZE];
    int top;
}Stack;

void init(Stack *stack){
    stack->top = -1;
}

bool is_empty(Stack *stack){
    return stack->top == -1;
}

bool is_full(Stack *stack){
    return stack->top == MAX_STACK_SIZE-1;
}

void push(Stack *stack, element data){
    if(is_full(stack)){
        std::cerr << "Stack is FULL\n";
        exit(-1);
    }
    stack->stack[++stack->top] = data;
}

element pop(Stack *stack){
    if (is_empty(stack)){
        std::cerr << "Stack is Empty\n";
        exit(-1);
    }
    return stack->stack[stack->top--];
}

element peek(Stack *stack){
    if (is_empty(stack)){
        std::cerr << "Stack is Empty\n";
        exit(-1);
    }
    return stack->stack[stack->top];
}

int main(){
    Stack stack;    // 스택 객체 선언

    init(&stack);    // 초기화
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);    // 스택 삽입

    std::cout << is_full(&stack) << "\n";
    std::cout << pop(&stack) << "\n";
    std::cout << pop(&stack) << "\n";
    std::cout << peek(&stack) << "\n";
    std::cout << pop(&stack) << "\n";
    std::cout << is_empty(&stack) << "\n";
}