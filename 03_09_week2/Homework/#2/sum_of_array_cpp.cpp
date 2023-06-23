#include <iostream>

int main(){
    int sum = 0;
    int array[10] = {0,};
    std::cout << "input 10 nums : ";
    for(int i=0; i<10; i++){
        std::cin >> array[i];
    }
    for(int i=0; i<10; i++){
        sum += array[i];
    }
    std::cout << "AMOUNT : " << sum << "\n";
    std::cout << "cpp / 201812671 / ÃßÇöÃ¢";
}