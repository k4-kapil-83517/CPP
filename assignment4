/*Q1. Stack is a Last-In-First-Out data structure. Write a Stack class. It implements stack using
Dynamically allocated array. Stack size should be passed in parameterized constructor. If size is not
given, allocate stack of size 5.
Provide member functions like push(), pop(), peek(), isEmpty(), isFull(), and print().*/

#include <iostream>
using namespace std;
class Stack {
private:
    int* arr;
    int top;
    int size;

public:
    // Parameterized constructor to initialize the stack size
    Stack(int s = 5) {
        size = s;
        arr = new int[size];
        top = -1; // Initialize top to -1, indicating an empty stack
    }

    // Destructor to free dynamically allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full, Cannot push value." <<endl;
            return;
        }
        else
        arr[++top] = value;
        cout << "Value " << value << " pushed onto the stack." <<endl;
    }

    // Function to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty, Cannot pop value." << endl;
            return;
        }
        cout << "Value " << arr[top--] << " popped from the stack." << endl;
    }

    // Function to return the top value of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Peek operation failed." << endl;
            return -1; // Assuming -1 is not a valid value in the stack
        }
        return arr[top];
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Function to check if the stack is full
    bool isFull() {
        return top == size - 1;
    }

    // Function to print the elements of the stack
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty." <<endl;
            return;
        }
        cout << "Stack values: ";
        for (int i = 0; i <= top; ++i) {
            cout << arr[i] << " ";
        }
        cout <<endl;
    }
};

int main() {
    int choice, values;
    int size;
    cout << "Enter size of stack (default is 5): ";
    cin >> size;

    Stack stack(size);

    do {
        cout << "\nStack Menu\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Print Stack\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> values;
                stack.push(values);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                cout << "Top value: " << stack.peek() <<endl;
                break;
            case 4:
                if (stack.isEmpty())
                    cout << "Stack is empty." <<endl;
                else
                    cout << "Stack is not empty." <<endl;
                break;
            case 5:
                if (stack.isFull())
                    cout << "Stack is full." <<endl;
                else
                    cout << "Stack is not full." <<endl;
                break;
            case 6:
                stack.print();
                break;
            case 7:
                cout << "Thank you for using this app.." <<endl;
                break;
            default:
                cout << "Invalid choice." <<endl;
        }
    } while (choice != 7);

    return 0;
}
