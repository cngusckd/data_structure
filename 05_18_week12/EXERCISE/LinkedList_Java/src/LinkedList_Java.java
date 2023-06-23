public class LinkedList_Java {
    public class Node{              // Node 객체 생성 ( 데이터 객체)
        int data;
        Node next;

        public Node(int data){      // 생성자
            this.data = data;
            this.next = null;
        }
    }

    public class MyLinkedList{
        private Node head;
        private int size;

        public MyLinkedList(){      // 생성자
            this.head = null;
            this.size= 0;
        }

        public int size(){          // linkedlist 크기 반환
            return this.size;
        }

        public void addAtHead(int data){       // O(1), head에 추가
            Node node = new Node(data);
            node.next = this.head;
            this.head = node;
            this.size++;
        }

        public void addBack(int data){ // O(n), tail에 추가
            Node node = new Node(data);
            Node current = this.head;
            // 현재 맨 뒤의 노드 탐색
            while( current.next != null){
                current = current.next;
            }
            current.next = node;
            this.size++;
        }

        public Node findNode(int data) { // O(n) , 노드탐색
            Node current = this.head;
            while(current != null){
                if (current.data == data){
                    return current;
                }
                current = current.next;
            }
            throw new RuntimeException("Node not found");
        }

        public void addAt(int index, int data){ // O(n), index위치에 추가
            if (index > this.size){ // index 범위 체크
                System.out.println("[!] Index Out of Range");
                return;
            }
            Node selectedNode = this.head;
            int i = 1; // index가 0인경우 head에 추가하는 것과 동일
            if (index == 0){
                this.addAtHead(data);
                return;
            }
            while(i != index){
                selectedNode = selectedNode.next;
                i++;
            }
            Node newNode = new Node(data);
            newNode.next = selectedNode.next;
            selectedNode.next = newNode;
            this.size++;
        }

        public void delete(int index){ // O(n), index위치의 node삭제 
            if (index > this.size || this.size == 0){
                System.out.println("[!] Index Out of Range");
                return;
            }
            Node selectedNode = this.head;
            int i = 1; // 첫번째 노드 삭제 == head 삭제
            if (index == 1){
                this.head = this.head.next;
                return;
            }
            while( i < index - 1){
                selectedNode = selectedNode.next;
                i++;
            }
            selectedNode.next = selectedNode.next.next;
            this.size--;
        }

        public void print(){                // linkedlist 전체출력
            Node current = this.head;
            while(current != null){
                System.out.print(current.data + " ");
                current = current.next;
            }
            System.out.println();
        }
    }

    public static void main(String args[]){
        LinkedList_Java llj = new LinkedList_Java();        // llj 객체 선언
        LinkedList_Java.MyLinkedList ll = llj.new MyLinkedList(); // my linked list 객체 선언

        ll.addAtHead(5);
        ll.print();

        ll.addBack(12);
        ll.print();

        ll.addBack(16);
        ll.print();

        ll.addAt(2, 24);
        ll.print();
        
        ll.delete(2);
        ll.print();
    }
}
