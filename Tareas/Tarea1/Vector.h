#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <random>

using namespace std;

template <typename T>
class Vector {
private:
    T* storage_;
    unsigned int capacity_;
    unsigned int size_;

    void resize() {
        cout << "Resize" << endl;
        unsigned int newCapacity = capacity_ * 1.5;
        T* newStorage = new T[newCapacity];

        for (unsigned int i = 0; i < size_; i++) {
            newStorage[i] = storage_[i];
        }

        delete[] storage_;
        storage_ = newStorage;
        capacity_ = newCapacity;
    }

public:
    Vector() {
        capacity_ = 10;
        storage_ = new T[capacity_];
        size_ = 0;
    }

    Vector(unsigned int c, T element) {
        capacity_ = c;
        storage_ = new T[capacity_];
        for (unsigned int i = 0; i < capacity_; i++) {
            storage_[i] = element;
        }
        size_ = capacity_;
    }

    void push_back(const T& elem) {
        if (size_ == capacity_) {
            resize();
        }
        storage_[size_] = elem;
        size_++;
    }
    
    // Task 1...

    // Insert: function for the "Exercise 1"...
    void insert(unsigned int index, T element){ // create the insert function
        unsigned int newCapacity = capacity_ + 1; //change capacity for avoid problems for the avoid problems with it later
        // +1 because will only be added one element to the vector
        T* newStorage = new T[newCapacity]; //Allocating memory for a new Vector of size newCapacity

        unsigned int j = 0; // Create a new variable for use in the loop later
        for(unsigned int i = 0; i < capacity_; i++){ // loop running through the vector

           if (j == index){ // If j is equal to index so in this position add the element here
                newStorage[j] = element; // add the element to new Vector
                j++; // j increment in 1, because this position in j it's a ahead of i
           }

           newStorage[j] = storage_[i]; // Else newStorage in the j position is equal to the element in storage_ in i position
           j++; // Increment j in 1
        } 

        delete[] storage_; // Deallocating memory of storage_
        storage_ = newStorage; // change so storage_ is equal to newStorage
        capacity_ = newCapacity; // change so capacity_ is equal to newCapacity
    } //End of the function "insert"

    // Erase: function for the "Exercise 1"...
    void erase(unsigned int index){  // create the erase function
        T* newStorage = new T[capacity_]; //Allocating memory for a new Vector of size capacity_
        unsigned int j = 0; // Create a new variable for use in the loop later
        for (unsigned int i = 0; i < size_; i++) // loop running through the vector
        {
            if(i == index){  // If i is equal to index so erase the element in this position
                i++; // Increment i in 1
                newStorage[j] = storage_[i]; //Add the next element in newStorage and jump the previous element
                j++; // Increment j in 1
            } else { 
                newStorage[j] = storage_[i]; // Else newStorage in the j position is equal to the element in storage_ in i position
                j++; // Increment j in 1
            }
        } 

        size_--; // Subtract one to size
        delete[] storage_; // Deallocating memory of storage_
        storage_ = newStorage; // change so storage_ is equal to newStorage
    } //End of the function "erase"


    // removeDuplicates: function for the "Exercise 2"...
    void removeDuplicates(){ // create the remove duplicates function

        T* newStorage = new T[capacity_]; //Allocating memory for a new Vector of size newCapacity
        unsigned int newSize = 0;  // Create a variable that save the new size because this will change in the process
        bool duplicate; // Variable type boolean for the comprobations

        for (unsigned int i = 0; i < size_; i++){  // Loop running through the vector
            duplicate = false; // The variable is initialized in false
            for (unsigned int j = 0; j < newSize; j++){ // Loop for comnprobations of duplicates in the vector
                if (storage_[i] == storage_[j]){ // If the element in storage_[i] is the same of storage[j]so is duplicate
                    duplicate = true; // Since the element is duplicated, the variable must be changed to true
                }
            }

            if(!duplicate){ 
                newStorage[newSize++] = storage_[i]; // If duplicate is false, add the element to newStorage
            }

        } 

        delete[] storage_; // Deallocating memory of storage_
        storage_ = newStorage; // change so storage_ is equal to newStorage
        size_ = newSize; // change so size_ is equal to newSize

    } // End of the function "removeDuplicates"


    // End of task 
    
    void print() {
        for (unsigned int i = 0; i < size_; i++) {
            cout << " " << storage_[i];
        }
    }

    void generateRandomVector(int n, T minValue, T maxValue) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<T> dist(minValue, maxValue);
    
        for (int i = 0; i < n; i++) {
            push_back(dist(gen));
        }
    }

    void generateRandomVectorWithDuplicates(int n, T minValue, T maxValue) {

        generateRandomVector(n, minValue, maxValue); 

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> indexDist(0, size_ - 1); 

        int numDuplicates = n / 3;
        for (int i = 0; i < numDuplicates; i++) {
            int sourceIndex = indexDist(gen);
            int targetIndex = indexDist(gen);
            storage_[targetIndex] = storage_[sourceIndex];
        }

    }
};

#endif // VECTOR_H

