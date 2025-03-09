/*  
    -----------------------------------------------------Implementing a Stack Using a Vector:-----------------------------------------------------
    
    > We have not discussed the Stack data structure. However, 
    you are very curious and have a lot of resources at your disposal to study it. After you have done that present an implementation of it using a vector.

*/

#include <iostream> // Include the standard input/output stream library for console operations.
#include "Vector.h" // Include the custom Vector class definition from the "Vector.h" header file.
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
        | o  | push(m)    | h  | top ()
        | l  | ------>    | o  | -------> m
        | a  |            | l  | 
        -----             | a  |
                          ------

*/

template <typename T> //Type of data that wila hsve the stack
class createStack { //Class stack 
private: 
    Vector<T> Stack; // Create stack using the Vector class

public:
    createStack() {} //Constructor of stack 

    void push(T element) { // push function: Inserts an element into the top of the stack.
        Stack.push_back1(element); // Using push_back this function is implemented on the stack
    }

    void pop() { // pop function: Deletes the item at the top of the stack.
        if (!Stack.empty_()) { //Verify that the stack is not empty
            Stack.pop_back(); // Using pop_back this function is implemented on the stack 
        } else {
            cout << "The stack is empty!" << endl; // Say to the user that the stack is empty 
        }
    }

    T top() { //Top function: Returns the element at the top without deleting it.
        if (!Stack.empty_()) { //Verify that the stack is not empty
            return Stack.back(); // The function return the valor in the top using the back function
        } else {
            cout << "Error: The stack is empty!" << endl; // Say to the user that the stack is empty
            return 0;
        }
    }

    bool isEmpty() { // function isEmpty: return true if the stack is empty.
        return Stack.empty_(); // Test the stack for review if is empty
    }

    void printStack() { // printStack function: Print the stack 
        if (Stack.empty_()) { 
            cout << "The stack is empty!" << endl; // Mensagge of error
            return;
        }
        cout << "Stack elements: ";
        for (unsigned int i = 0; i < Stack.Size(); i++) {
            cout << Stack.at(i) << " ";
        }
        cout << endl;
    }
};

void Exercise4() { 
    /*
        Testintg the code with some valors
    
    */
    createStack<int> stack; // Create a stack using the cecct
    stack.push(35); // Uso de la función de empuje para un rasgo
    stack.push(22); // " "
    stack.push(18); // " "
    stack.push(47) ;// " "

    stack.printStack(); // Print actually stack

    cout << "Now will use the pop function:  " << endl;
    stack.pop();   // Delete using pop 
    stack.printStack();; // Print actually stack
    cout << "Now will use the top function:  " << endl;
    cout << stack.top();   // Return first element using pop 

}