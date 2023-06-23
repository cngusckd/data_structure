public class LinkedStack {
    public class Node{
        int data;
        Node next;

        public Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    public class MyLinkedList{
        private Node head;
        private int size;

        MyLinkedList(){
            this.head = null;
            this.size = 0;
        }

        public int size(){
            return this.size;
        }

        public void addAtHead(int data){
            Node node = new Node(data);
            node.next = this.head;
            this.head = node;
            this.size++;
        }

        public void addBack(int data){
            Node node = new Node(data);
            Node current = this.head;
            while (current.next != null){
                current = current.next;
            }
            current.next = node;
            this.size++;
        }

        public Node findNode(int data){
            Node current = this.head;
            while(current != null){
                if( current.data == data){
                    return current;
                }
                current = current.next;
            }
            throw new RuntimeException("Node not found");
        }

        public void addAt(int index, int data){
            if( index > this.size ){
                System.out.println("[!] Index Out of Range");
                return;
            }
            Node selectedNode = this.head;
            int i = 1;
            if ( index == 0 ){
                this.addAtHead((data));
                return;
            }
            while ( i != index ){
                selectedNode = selectedNode.next;
                i++;
            }
            Node newNode = new Node(data);
            newNode.next = selectedNode.next;
            selectedNode.next = newNode;
            this.size++;
        }

        public void delete(int index){
            if(this.size < index || this.size == 0 ){
                System.out.println("[!] Index Out of Range");
                return;
            }
            Node selectedNode = this.head;
            int i = 1;              // 첫번째 노드를 삭제할경우 head 값 변경
            if(index == 1){
                this.head = this.head.next;
                return;
            }
            while ( i < index - 1){
                selectedNode = selectedNode.next;
                this.size--;
            }
        }
    }

    public MyLinkedList stack = new MyLinkedList();
    public int size;
    public int top;
    
    public void init(int size){
        this.size = size;
        this.top = -1;
    }

    public void push(int data){
        this.stack.addAtHead(data);
        this.top += 1;
    }

    public void pop(){
        this.stack.delete(1);
    }

    public boolean is_empty(){
        return this.top == -1;
    }

    public boolean is_full(){
        return this.top == this.size-1;
    }

    public int peek(){
        return this.stack.head.data;
    }

    public static void main(String[] args){
        LinkedStack stack = new LinkedStack();

        stack.init(4);

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);

        System.out.println(stack.is_full());

        stack.pop();
        stack.pop();

        System.out.println(stack.peek());
        System.out.println(stack.is_empty());
    }
}
