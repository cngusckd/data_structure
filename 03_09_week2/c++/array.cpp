#include <iostream>

int main(){
    int array[10];

    std::cout << "Array : ";
    for(int i=0; i<10; i++){
        array[i] = i+1;
        std::cout << array[i] << " ";
        array[i] = array[i] * 10;
    }
    std::cout << "\n";
    std::cout << "array multiplied by 10: ";
    for(int i=0; i<10; i++){
        std::cout<< array[i] << " ";
    }
}