/*
 ---------------------------------------------------------------Removing Duplicates:---------------------------------------------------------------
    
    > Write a function that takes a vector of integers and removes all duplicate elements, 
      preserving the original order of the remaining elements.
    > Analyze the time complexity of your solution.
    > Consider the following non-extensive program to test your implementation:

*/

#include <iostream> // Include the library
#include "Vector.h" 

using namespace std;


void Exercise2(){

        /* 
            The algorithm for delate duplicates elements:

            void removeDuplicates(){

                T* newStorage = new T[capacity_];
                unsigned int newSize = 0; 
                bool duplicate;

                for (unsigned int i = 0; i < size_; i++){
                    duplicate = false;
                    for (unsigned int j = 0; j < newSize; j++){
                        if (storage_[i] == storage_[j]){
                            duplicate = true;
                        }
                    }

                    if(!duplicate){
                        newStorage[newSize++] = storage_[i];
                    }
                }

                delete[] storage_;
                storage_ = newStorage;
                size_ = newSize;

            }
            
            Observations:  
                The outer loop O(n) contains an inner loop O(n), 
                resulting in a complexity of O(n * n) = O(n^2).
                
                The memory allocation O(n) is less significant than O(n^2) in the worst case.
                so the algorithm have a Time Complexity of: O(n^2)
        */

    Vector<int> testVector;
    testVector.generateRandomVectorWithDuplicates(10, 0, 200);

    cout << "The vector we will work with is: { " ;
    testVector.print();
    cout << " }" << endl;

    cout << "The modified vector is: {";
    testVector.removeDuplicates();
    testVector.print();
    cout << " }";
    cout << endl;

}