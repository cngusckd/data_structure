#include <stdio.h>

float add(float a,float b){
    return a+b;
}

float subtract(float a, float b){
    return a-b;
}

float multiply(float a, float b){
    return a*b;
}

float divide(float a, float b){
    if(b==0){
        printf("0으로 나눌 수 없습니다.");
        return 0;
    }
    return a/b;
}

int main(){
    while(1){
        int user_order = 0;
        float num1 = 0 ,num2 = 0;

        printf("1.add    2.subtract  3.multiply  4.divide ( exit : -1 ) : ");
        scanf("%d", &user_order);
        if(user_order == -1){
            printf("종료\n");
            printf("C언어 / 201812671 / 추현창");
            break;
        }
        
        printf("두 수를 입력해주세요 : ");
        scanf("%f %f", &num1, &num2);
        
        
        if(user_order == 1){
            printf("%f\n",add(num1, num2));
        }else if(user_order == 2){
            printf("%f\n",subtract(num1, num2));
        }else if(user_order == 3){
            printf("%f\n",multiply(num1, num2));
        }else if(user_order == 4){
            printf("%f\n",divide(num1, num2));
        }else{
            continue;
        }

    }
}