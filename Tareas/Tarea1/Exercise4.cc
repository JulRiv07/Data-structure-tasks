/*  
    -----------------------------------------------------Implementing a Stack Using a Vector:-----------------------------------------------------
    
    > We have not discussed the Stack data structure. However, 
    you are very curious and have a lot of resources at your disposal to study it. After you have done that present an implementation of it using a vector.

*/

#include <iostream>
#include "Vector.h"

using namespace std;


/*
    What is the stack?
    A stack is an ordered data structure that follows the LIFO (Last In, First Out) principle... 
    So it can only make, push and pop, for one end, called the "cima"
    ¡¡Imagine a stack of dishes!!

    The ususal operations are: 
        push(element) → Inserts an element into the top of the stack.
        pop() → Deletes the item at the top of the stack.
        top() or peek() → Returns the element at the top without deleting it.
        isEmpty() → Returns true if the stack is empty.

        Example:

        | h  |            | m  |
        | o  | push(m)    | h  | top (m)
        | l  | ------>    | o  | -------> m
        | a  |            | l  | 
        -----             | a  |
                          ------

*/

template <typename T>
class createStack {
private:
    Vector<T> Stack;

public:
    createStack() {}

    void push(T element) {
        Stack.push_back1(element);
    }

    void pop() {
        if (!Stack.empty_()) {
            Stack.pop_back();
        } else {
            cout << "The stack is empty!" << endl;
        }
    }

    T top() {
        if (!Stack.empty_()) {
            return Stack.back();
        } else {
            throw out_of_range("Error: The stack is empty!");
        }
    }

    bool isEmpty() {
        return Stack.empty_();
    }

    void printStack() {
        if (Stack.empty_()) {
            cout << "The stack is empty!" << endl;
            return;
        }

        cout << "Stack elements: ";
        Vector<T> tempStack = Stack;
        while (!tempStack.empty_()) {
            cout << tempStack.back() << " ";
            tempStack.pop_back();
        }
        cout << endl;
    }
};

void Exercise4() {

    createStack<int> stack;
    stack.push(35);
    stack.push(22);
    stack.push(18);
    stack.push(47);

    stack.printStack();

    cout << "Now will use the pop function: ";
    stack.pop();
    stack.printStack();

    cout << "Now will use the top function: ";
    cout << stack.top() << endl;

    // Erase all elements
    stack.pop();
    stack.pop();
    stack.pop();

    cout << "Is the stack empty?: ";
    cout << (stack.isEmpty() ? "Yes" : "No") << endl;
}