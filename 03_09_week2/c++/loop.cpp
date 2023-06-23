#include <iostream>

void loop_for(){
    for(int i = 1; i<=100; i++){
        if(i%20==0 || i%30==0)std::cout << i<<" ";
    }
}

void loop_while(){
    int i=1;
    while(i<=100){
        if(i%20==0 || i%30==0)std::cout << i<<" ";
        i++;
    }
}

int main(){
    loop_for();
    std::cout<<std::endl;
    loop_while();

}