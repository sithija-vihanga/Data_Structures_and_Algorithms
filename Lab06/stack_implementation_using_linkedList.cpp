#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

bool isEmpty() {
    if(top == NULL){
    return true; 
    }
    else{
        return false;
    }
}

void push(int num) {
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return -1;
    }

    Node* temp = top;
    int popItem = top->data;
    top = top->next;
    delete temp;
    return popItem;
}


void display() {
    Node* current = top;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
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
    cout << "Execution time: " << duration.count() << " microseconds" << endl;

    return 0;
}
