#include <iostream> // Include the library
#include "Vector.h"

using namespace std;

/* It works!!

    Vector<int> myVector;

    <//> Test push_back
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);
    
    cout << myVector.Size() << endl; // Expected: 3
    cout << myVector.Capacity() << endl; // Expected: Initial capacity, e.g., 4 or 8

    <//> Test pop_back

    myVector.pop_back();
    cout << myVector.size() << endl; // Expected: 2

    <//> Test at with valid and invalid indices

    cout << myVector.at(0) << endl; // Expected: 10
    cout << myVector.at(1) << endl; // Expected: 20

    <//> Border case: Accessing an out-of-bounds index

    cout << myVector.at(2) << endl; // Should crash!

    <//> Border case: pop_back on empty vector

    Vector<int> emptyVector;
    emptyVector.pop_back(); // Should crash!
*/

void testExercise1(){
    int option;

    Vector<int> testVector;
    testVector.generateRandomVector(10, 0, 200);

    cout << "Do you want to (1. insert or 2. erase): ";
    cin >> option; 

    if(option == 1){

        unsigned int position;
        int element;
        cout << "The vector we will work with is: ";
        testVector.print();

        cout << "Enter the element you want to add: ";
        cin >> element; 
        cout << "Enter the position where you want to add it: ";
        cin >> position;  
        
        testVector.insert(position, element);
        cout << "The modified vector is: ";
        testVector.print();

    } else if (option == 2) {

        unsigned int position;
        cout << "The vector we will work with is: ";
        testVector.print();

        cout << "Enter the position where you want to erase element: ";
        cin >> position;  
        
        testVector.erase(position);
        cout << "The modified vector is: ";
        testVector.print();
        
    } else cout << "Incorrect option!";

}

