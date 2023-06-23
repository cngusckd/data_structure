#include <iostream>

int evensum(int start, int end){
    int sum = 0;
    while(start<=end){
        if(start % 2 == 0) sum += start;
        start++;
    }
    return sum;
}

int main(){
    int start = 0;
    int end = 10;
    std::cout << "sum of even numbers between " << start << " and " << end << " = " << evensum(start, end);
}