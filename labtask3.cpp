#include <iostream>
using namespace std;


const int MAX_SIZE = 100;

class MyStack {
public:
    MyStack() : top(-1) {}

    void push(int val) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack is full. Cannot push " << val << endl;
        } else {
            stack[++top] = val;
        }
    }

    void pop() {
        if (top < 0) {
            cout << "Stack is empty. Cannot pop." << endl;
        } else {
            --top;
        }
    }

    int getLowestElement() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
            return -1; // Assuming -1 is not a valid element in the stack
        }

        int lowest = stack[0];
        for (int i = 1; i <= top; i++) {
            if (stack[i] < lowest) {
                lowest = stack[i];
            }
        }

        return lowest;
    }

    void removeLowestElement() {
        int lowest = getLowestElement();

        if (lowest == -1) {
            return;
        }

        int temp[MAX_SIZE];
        int tempTop = -1;

        while (top >= 0) {
            int val = stack[top--];
            if (val != lowest) {
                temp[++tempTop] = val;
            }
        }

        while (tempTop >= 0) {
            stack[++top] = temp[tempTop--];
        }
    }

    void printStack() {
        cout << "Stack elements are: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

private:
    int stack[MAX_SIZE];
    int top;
};

int main() {
    MyStack myStack;

    
    myStack.push(5);
    myStack.push(2);
    myStack.push(4);
    myStack.push(7);

    myStack.printStack();

    int lowest = myStack.getLowestElement();
    cout << "Find and remove the lowest element " << lowest << " from the stack." << endl;
    myStack.removeLowestElement();
    myStack.printStack();

    
    myStack.push(2);
    myStack.push(-1);
    myStack.push(5);
    myStack.push(4);
    myStack.push(7);

    myStack.printStack();

    lowest = myStack.getLowestElement();
    cout << "Find and remove the lowest element " << lowest << " from the stack." << endl;
    myStack.removeLowestElement();
    myStack.printStack();

    return 0;
}
