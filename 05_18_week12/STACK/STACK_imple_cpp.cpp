#include <iostream>

using namespace std;

// NODE 구현
class NODE {
    public:
        int data;
        NODE* next;
        NODE(int data){
            this->data = data;
            this->next = NULL;
        }
};

// NODE를 이용한 LINKEDLIST 구현

class LinkedList{
    public:
        NODE* head;
        int size;

        LinkedList(){   
            this->head = NULL;
            this->size = 0;
        }

        int getSize(){
            return this->size;
        }

        void addAtHead(int data) {
            NODE* node = new NODE(data);
            node->next = this->head;
            this->head = node;
            this->size++;
        }

        void addBack(int data){
            NODE* node = new NODE(data);
            NODE* current_node = this->head;
            if(current_node == NULL){
                this->head = node;
            }else{
                while(current_node->next != NULL){
                    current_node = current_node->next;
                }
                current_node->next = node;
            }
            this->size++;
        }

        NODE* findNode(int data){
            NODE* current_node = this->head;
            while(current_node != NULL){
                if(current_node->data == data){
                    return current_node;
                }
                current_node = current_node->next;
            }
            throw runtime_error("NODE not found");
        }

        void deleteNode(int index){
            if(this->size < index || this->size == 0){
                cout << "[!] Index Out of Range" << endl;
                return;
            }
            NODE* selected_node = this->head;
            int i = 1;
            if(index == 1){
                NODE* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            while(i < index - 1){
                selected_node = selected_node->next;
                i++;
            }
            NODE* temp = selected_node->next;
            selected_node->next = temp->next;
            delete temp;
            this->size--;
        }
        void print(){
            NODE* current_node = this->head;
            while(current_node != NULL){
                cout << current_node->data << " ";
                current_node = current_node->next;
            }
        }
};

typedef struct{
    LinkedList llist;
    int size;               // 할당된 stack의 크기
    int top;                // top의 index
}LinkedStack;

bool is_full(LinkedStack *stack){
    return stack->top == stack->size-1;
}

void init(LinkedStack *stack, int size){
    stack->top = -1;
    stack->size = size;
}

void push(LinkedStack *stack, int data){
    if(is_full(stack)){
        cout << "Stack is FULL\n";
        exit(-1);
    }
    stack->llist.addAtHead(data);
    stack->top += 1; 
}

void pop(LinkedStack *stack){
    stack->llist.deleteNode(1);
}
bool Is_empty(LinkedStack *stack){
    return stack->top == -1;
}

int peek(LinkedStack *stack){
    return stack->llist.head->data;
}

int main(){
    LinkedStack stack;
    init(&stack,4);

    push(&stack,1);
    push(&stack,2);
    push(&stack,3);
    push(&stack,4);

    cout << is_full(&stack) << "\n";
    pop(&stack);
    pop(&stack);
    cout << peek(&stack) << "\n";
    cout << Is_empty(&stack) << "\n";
}