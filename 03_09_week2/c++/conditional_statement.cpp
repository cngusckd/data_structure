#include <iostream>

int main(){
    int score = 70;

    if(score >= 90)std::cout << "grade A." << "\n";
    else if(score >= 80)std::cout << "grade B." << "\n";
    else if(score >= 70)std::cout << "grade C." << "\n";
    else if(score >= 60)std::cout << "grade D." << "\n";
    else std::cout << "grade F." << "\n";
    std::cout << "Thank you for your effort."<< "\n";

    return 0;
}