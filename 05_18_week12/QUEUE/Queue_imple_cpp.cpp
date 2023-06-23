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
    int size;
    int top;
}LinkedQueue;

bool is_full(LinkedQueue *queue){
    return queue->top == queue->size-1;
}

void init(LinkedQueue *queue, int size){
    queue->top = -1;
    queue->size = size;
}

void push(LinkedQueue *queue, int data){
    if(is_full(queue)){
        cout << "Stack is FULL\n";
        exit(-1);
    }
    queue->llist.addBack(data);
    queue->top += 1; 
}

void pop(LinkedQueue *queue){
    queue->llist.deleteNode(1);
}
bool Is_empty(LinkedQueue *queue){
    return queue->top == -1;
}

int peek(LinkedQueue *stack){
    return stack->llist.head->data;
}

int main(){
    LinkedQueue queue;
    init(&queue,4);

    push(&queue,1);
    push(&queue,2);
    push(&queue,3);
    push(&queue,4);

    cout << is_full(&queue) << "\n";
    pop(&queue);
    pop(&queue);
    cout << peek(&queue) << "\n";
    cout << Is_empty(&queue) << "\n";
}