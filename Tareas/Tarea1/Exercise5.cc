/*
-----------------------------------------------------Merge sorted vectors-----------------------------------------------------

> Given two sorted vectors, write the method merge to merge them into a single sorted vector.
> Consider the following non extensive program to test your implementation.

*/

#include <iostream> // Include the standard input/output stream library for console operations.
#include "Vector.h" // Include the custom Vector class definition from the "Vector.h" header file.

using namespace std; 

Vector<int> mergeSortedVectors(const vector<int>& vector1, const vector<int>& vector2){ // Function that order the vectors

    size_t i = 0; // i is initialized at 0
    size_t j = 0; // j is initialized at 0
    Vector<int> testVector; // Create a testVector 

    while(i < vector1.size() && j < vector2.size()) { // The loop will work until both vectors are traversed

        if(vector1[i] < vector2[j]){ // Condition that evaluate which is the greatest
            testVector.push_back1(vector1[i]); // push_back the element int the testVector
            i++; // Increment i in one 
        } else {
            testVector.push_back1(vector2[j]); // push_back the element int the testVector
            j++; // Increment i in one 
        }
    }

    // if there were elements left then...

    while(i < vector1.size()){ 
        testVector.push_back1(vector1[i]);
        i++;
    }

    while(j < vector2.size()){
        testVector.push_back2(vector2[j]);
        j++;
    }

    return testVector; // Return testVector already ordered


}


void Exercise5(){ 
    vector<int> vector1 = {3, 7, 11, 15, 19, 22, 25, 29, 33, 37, 41, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96}; // initialize the vector1 with lots of numbers
    vector<int> vector2 = {2, 6, 10, 14, 18, 21, 24, 28, 32, 36, 40, 43, 47, 51, 55, 59, 63, 67, 71, 75, 79, 83, 87, 91, 95, 99, 103, 107, 111, 115}; // initialize the vector2 with lots of numbers
    Vector<int> mergedVector = mergeSortedVectors(vector1, vector2); // mergedVector is equal to the return of the function mergeSortedVectors
    mergedVector.print(); // Print the vector ordered
    
} // end
