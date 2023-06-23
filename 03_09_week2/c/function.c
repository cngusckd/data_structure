#include <stdio.h>

void evensum(int a, int b){
    int start;
    start = a>b?b:a;
    int end;
    end = a>b?a:b;
    int sum = 0;
    for(int i=start; i<=end; i++){
        if(i%2==0){
            sum += i;
        }
    }
    printf("sum of even numbers between %d and %d = %d \n", start, end, sum);
}

int main(){
    int num1 = 10;
    int num2 = 0;
    evensum(num1, num2);
}