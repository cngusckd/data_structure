#include <iostream>

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
        std::cout << "0으로 나눌 수 없습니다." << "\n";
        return 0;
    }
    return a/b;
}

int main(){
    while(1){
        int user_order = 0;
        float num1 = 0 ,num2 = 0;

        std::cout << "1.add    2.subtract  3.multiply  4.divide ( exit : -1 ) : ";
        std::cin >> user_order;
        if(user_order == -1){
            std::cout << "종료\n";
            std::cout << "Cpp / 201812671 / 추현창";
            break;
        }
        
        std::cout << "두 수를 입력해주세요 : ";
        std::cin >> num1 >> num2;
        
        if(user_order == 1){
            std::cout << add(num1, num2) << "\n";
        }else if(user_order == 2){
            std::cout << subtract(num1, num2) << "\n";
        }else if(user_order == 3){
            std::cout << multiply(num1, num2) << "\n";
        }else if(user_order == 4){
            std::cout << divide(num1, num2) << "\n";
        }else{
            continue;
        }

    }
}