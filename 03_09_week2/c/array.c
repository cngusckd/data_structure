#include <stdio.h>

int main(){
    int arr[10] = {0,};
    for(int i=0; i<10; i++){
        arr[i] = i+1;
        printf("%d ",arr[i]);
        arr[i] = arr[i]*10;
    }
    printf("\n");
    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
}
