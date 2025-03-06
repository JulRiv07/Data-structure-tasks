#include <iostream> // Include the library
#include "Vector.h"

using namespace std;

void Exercise1(){
    int option;

    Vector<int> testVector;
    testVector.generateRandomVector(10, 0, 200);

    cout << "Do you want to (1. insert or 2. erase): ";
    cin >> option; 

    if(option == 1){

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
        cout << endl;

    } else if (option == 2) {

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

        unsigned int position;
        cout << "The vector we will work with is: ";
        testVector.print();
        cout << endl;

        cout << "Enter the position where you want to erase element: ";
        cin >> position;  
        
        testVector.erase(position);
        cout << "The modified vector is: ";
        testVector.print();
        cout << endl;

    } else cout << "Incorrect option!";

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

