#include <iostream>

using namespace std;

class Node{         // 노드를 포현
public:
    int data;           // 데이터값
    Node* next;         // 다음노드 주소 지정
    Node(int data){     // 생성자
        this->data = data;      // 데이터값 초기화
        this->next = NULL;      // 다음 노드 주솟값 초기화 (가리키는 것 X)
    }
};

class LinkedList{       // LinkedList 클래스
public:
    Node* head;         // linkedlist 헤드
    int size;           // linkedlist 크기
    LinkedList(){       // 생성자 (초기화)
        this->head = NULL;
        this->size = 0;
    }

    int getSize(){      // linkedlist 크기 반환
        return this->size;
    }

    void addAtHead(int data){       // head에 node 추가
        Node* node = new Node(data);        // 새로운 노드 생성
        node->next = this->head;            // 기존의 head를 새로운 노드의 다음 노드로
        this->head = node;                  // 새로운 노드가 head로 변경
        this->size++;                       // size++
    }

    void addBack(int data){                     // 제일 뒤에 추가
        Node* node = new Node(data);            // 새로운 노드 생성
        Node* current_node = this->head;
        if (current_node == NULL){              // node가 없을경우 그냥 추가
            this->head = node;
        }else{
            while(current_node->next != NULL){          // node가 있을경우 끝 노트까지 이동
                current_node = current_node->next;      
            }
            current_node->next = node;                  // node 추가
        }
        this->size++;                                   // size++
    }

    Node* findNode(int data){       // Node 탐색           
        Node* current_node = this->head;        //head
        while (current_node->data == data){
            if ( current_node->data == data){
                return current_node;         // 같다면 노드 반환
            }
            current_node = current_node->next;
        }
        throw runtime_error("Node not found");      // 예외처리
    }

    void addAt(int index, int data){        // 특정 index에 노드 추가
        if (this->size < index){            // index 오버플로우
            cout << "[!] Index Out of Range" << endl;
            return;
        }
        Node* selected_node = this->head;
        int i = 1;
        if (index == 0){            // index == 1 , head에 추가
            addAtHead(data);
            return;
        }
        while(i != index){          // index 까지 node 이동
            selected_node = selected_node->next;
            i++;
        }
        Node* node = new Node(data);            // 새로운 노드생성
        node->next = selected_node->next;       // 그후 삽입하기
        selected_node->next = node;
        this->size++;
    }

    void deleteNode(int index){             // 특정 index의 노드 삭제
        if (this->size < index){            // index 오버플로우
            cout << "[!] Index Out of Range" << endl;
            return;
        }
        Node* selected_node = this->head;
        int i = 1;
        if (index == 1){                    // index == 1, head삭제
            this->head = selected_node->next;
            delete selected_node;
        }
        while (i < index - 1){
            selected_node = selected_node->next;
            i++;
        }
        this->head = selected_node->next;
        delete selected_node;
    }

    void print(){
        Node* current_node = this->head;
        while ( current_node != NULL){
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
};