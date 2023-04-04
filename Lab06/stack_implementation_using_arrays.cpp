// Online C++ compiler to run C++ program online
#include <iostream>
#include <chrono>
#define noOfElements 8

using namespace std::chrono;

int arrayStack[noOfElements];
int top = -1;

bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
    
}

bool isFull(){
    if(top==(noOfElements-1)){
        return true;
    }
    else{
        return false;
    }
}
void push(int num){
    if(not isFull()){
        top+=1;
        arrayStack[top] = num;
    }
    else{
        std::cout<<"Overflow"<<std::endl;
    }
}
void pop(){
    if(not isEmpty()){
        top-=1;
    }
    else{
        std::cout<<"stack is empty"<<std::endl;
    }
}
int stackTop(){
    return arrayStack[top];
}
void display(){
    for(int i=0;i<=top; i++){
        std::cout<<arrayStack[i]<<" ";
    }
    std::cout<<std::endl;
}


int main() {
    auto start = steady_clock::now();

    
    
    push(20);
    display();
    push(10);
    display();
    push(4);
    display();
    push(13);
    display();
    push(98);
    display();
    push(7);
    display();
    push(26);
    display();
    push(33);
    display();
    push(48);
    display();
    push(51);
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    
    auto stop = steady_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
