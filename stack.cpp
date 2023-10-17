#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 100; 

int stack[MAX_SIZE]; 
int top = -1; 


void push(int value) {
    if (top == MAX_SIZE - 1) {
        cerr << "Stack is full. Cannot push." <<endl;
        return;
    }
    stack[++top] = value;
}


int pop() {
    if (top == -1) {
        cerr << "Stack is empty. Cannot pop." << std::endl;
        return -1;  
    }
    return stack[top--];
}


bool isEmpty() {
    return top == -1;
}


void show() {
    if (isEmpty()) {
        cout << "Stack is empty." << std::endl;
        return;
    }
    cout << "Stack contents: ";
    for (int i = 0; i <= top; ++i) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main() {
    
    push(1);
    push(2);
    push(3);

   
    show();

   
    int popped = pop();
    cout << "Popped: " << popped << std::endl;

  
    show();

    return 0;
}