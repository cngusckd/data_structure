#include <stdio.h>

int main(){
    int sum = 0;
    int array[10] = {0,};
    printf("input 10 nums : ");
    for(int i=0; i<10; i++){
        scanf("%d",&array[i]);
    }
    for(int i=0; i<10; i++){
        sum += array[i];
    }
    printf("AMOUNT : %d\n",sum);
    printf("c / 201812671 / ÃßÇöÃ¢");
}