#include <stdio.h>

int main(){
    int score = 70;
    if(score >= 90){
        printf("grade A.\n");
    }else if(score >= 80){
        printf("grade B.\n");
    }else if(score >= 70){
        printf("grade C.\n");
    }else if(score >= 60){
        printf("grade D.\n");
    }else{
        printf("grade F.\n");
    }
    printf("Thank you for your effort.");

    return 0;
}