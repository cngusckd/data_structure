#include <iostream>

using namespace std;

int *heap = NULL;
int heap_size = 1;

void push(int value){
    int index = heap_size;
    heap[heap_size++] = value;

    while(index > 1){
        int next = index / 2;
        if(heap[index] < heap[next]){
            int temp = heap[index];
            heap[index] = heap[next];
            heap[next] = temp;
            index /= 2;
        } else {
            break;
        }
    }
}

int pop(void){
    int value = heap[1];
    heap[1] = heap[--heap_size];
    int index = 1;

    while (index < heap_size){
        int left = index * 2;
        int right = index * 2 + 1;
        int next;

        if (right < heap_size){
            if (heap[left] < heap[right])
                next = left;
            else
                next = right;
        } else if (left < heap_size){
            next = left;
        } else {
            break;
        }

        if (heap[index] > heap[next]){
            int temp = heap[index];
            heap[index] = heap[next];
            heap[next] = temp;
            index = next;
        }
        else{
            break;
        }
    }
    return value;
}

int main(void){
    int N, data;

    cin >> N;

    heap = new int[N+1];

    for (int i=0; i< N;i++){
        cin >> data;
        push(data);
    }

    for (int i=0; i<N; i++){
        cout << i+1 << " node in : " << pop() << "\n";
    }
    
    delete[] heap;
    return 0;
}