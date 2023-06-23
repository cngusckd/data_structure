import java.util.Scanner;

public class PriorityQueue_Java {
    static int[] heap;
    static int size = 1;

    static void push(int value){        // 데이터삽입
        int index = size;
        heap[size++] = value;

        while( index > 1){
            int next = index / 2;       // heap 자료구조 특성에 맞게 ( index = next * 2)

            if(heap[index] < heap[next]){
                int temp = heap[index];
                heap[index] = heap[next];
                heap[next] = temp;
                index = next;
            }else{
                break;
            }
        }
    }

    static int pop() {              // 데이터 삭제
        int value = heap[1];
        heap[1] = heap[--size];
        int index = 1;

        while(index < size){                // childeren check
            int left = index * 2;
            int right = index * 2 + 1;
            int next;

            if(right < size){
                if(heap[left] < heap[right]){
                    next = left;
                }else{
                    next = right;
                }
            }else if(left < size){
                next = left;
            }else{
                break;
            }

            if( heap[index] > heap[next]){
                int temp = heap[index];
                heap[index] = heap[next];
                heap[next] = temp;
                index = next;
            }else {
                break;
            }
        }
        return value;
    }
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        heap = new int[N+1];

        for(int i=0; i<N ; i++){
            int data = sc.nextInt();
            push(data);
        }

        for(int i=0; i<N; i++){
            System.out.println(i+1+" node in "+pop());
        }

        sc.close();
    }
}
