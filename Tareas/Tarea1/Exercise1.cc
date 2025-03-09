/*
    ---------------------------------------------------------------Insert and Erase:---------------------------------------------------------------
    
    >Extend your vector implementation to include:
        > insert(index, element): Insert an element at a specific index.
        > erase(index): Remove the element at a specific index.
    > Analyze the time complexity of these operations.
    > Consider the following program to test your implementations. 
      Be careful, it just tests some functionalities and is not intended to be extensive.

*/


#include <iostream> // Include the standard input/output stream library for console operations.
#include "Vector.h"      // Include the custom Vector class definition from the "Vector.h" header file.

using namespace std; 

void Exercise1(){ // Function to execute 
    int option; // Variable for the user option

    Vector<int> testVector; // Make the test vector
    testVector.generateRandomVector(10, 0, 200); // Generate the random vector with 10 elements 

    cout << "Do you want to (1. insert or 2. erase): "; // options of the exercise
    cin >> option;  // Read the option of the user 

    if(option == 1){ // if user selection one option

        /*
            The algorithm for insert:

            void insert(unsigned int index, T element){
                unsigned int newCapacity = capacity_ + 1;
                T* newStorage = new T[newCapacity];

                unsigned int j = 0;
                for(unsigned int i = 0; i < capacity_; i++){

                if (j == index){
                        newStorage[j] = element;
                        j++;
                }

                newStorage[j] = storage_[i];
                j++;
                }

                delete[] storage_;
                storage_ = newStorage;
                capacity_ = newCapacity;
            }

            Observations: 
                The dominant operation is the loop and the memory allocation, 
                both of which take O(n) time
                so the algorithm have a Time Complexity of: O(n)
        */

        unsigned int position; // Variable for the position where to insert
        int element; // Variable for lement to insert
        cout << "The vector we will work with is: ";
        testVector.print(); // print the vector generate

        cout << endl << "Enter the element you want to add: "; 
        cin >> element;  // Read the element for the insert in the vector 
        cout << "Enter the position where you want to add it: ";
        cin >> position;  // Read the position for the insert in the vector 
        
        testVector.insert(position, element); // Use function insert in testvector 
        cout << "The modified vector is: ";
        testVector.print(); // Print the modified vector 
        cout << endl; 

    } else if (option == 2) { // If the option is 2
 
        /*
            The algorithm for erase:

            void erase(unsigned int index){  
                T* newStorage = new T[capacity_]; 
                unsigned int j = 0;
                for (unsigned int i = 0; i < size_; i++) 
                {
                    if(i == index){  
                        i++;
                        newStorage[j] = storage_[i]; 
                        j++;
                    } else { 
                        newStorage[j] = storage_[i]; 
                        j++; 
                    }
                } 

                size_--; 
                delete[] storage_;
                storage_ = newStorage;
            }

            Observations:
                The dominant operations are the memory allocation and the loop, 
                both of which take O(n) time.
                so the algorithm have a Time Complexity of: O(n)
            
        */

        unsigned int position; // Variable for the position where to insert
        cout << "The vector we will work with is: ";
        testVector.print(); // print the vector generate
        cout << endl;

        cout << "Enter the position where you want to erase element: "; 
        cin >> position; // Read the position for erase in the vector 
        
        testVector.erase(position); // Use function erase in testvector 
        cout << "The modified vector is: "; 
        testVector.print(); // Print the modified vector 
        cout << endl;

    } else cout << "Incorrect option!"; // Say to the user that the option isn't correct

}

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

