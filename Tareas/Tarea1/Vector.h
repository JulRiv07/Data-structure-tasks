#ifndef VECTOR_H
#define VECTOR_H

#include <iostream> // Include the standard input/output stream library for console operations.
#include <random>   // Include the random number generation library.
#include <cassert>  // Include the assertion library for runtime checks.

using namespace std;

template <typename T>
class Vector { // Start of the Vector class

    private:

        T* storage_;          // Pointer to the array we will handle as a vector (of type T)
        unsigned int capacity_; // Vector capacity
        unsigned int size_;     // Current vector size

         /* 
        Resizes policies  :
            P1: capacity_ + 1;
            P2: capacity_ + 2;
            P3: capacity_ * 1.5;
            P4: capacity_ * 2;
    
        */
    
        void resizeP1() { // Resize function (private!)

            unsigned int capacity2 = capacity_ + 1; // Modifies the capacity by adding half of the previous capacity
            T* storage2 = new T[capacity2]; // Allocates storage2 with the same memory space as capacity2
    
            // Copies the vector elements
            for (unsigned int i = 0; i < size_; i++) {
                storage2[i] = storage_[i];
            }
    
            // Releasing old memory
            delete[] storage_; // Deletes storage_
            storage_ = storage2; // Re-creates storage_ with the same value as storage2
            capacity_ = capacity2; // Recovers capacity_
        }
        
        // The same practically...

        void resizeP2() {

            unsigned int newCapacity = capacity_ + 2;
            T* newStorage = new T[newCapacity];

            for (unsigned int i = 0; i < size_; i++) {
                newStorage[i] = storage_[i];
            }

            delete[] storage_;
            storage_ = newStorage;
            capacity_ = newCapacity;
        }

        void resizeP3() {
            unsigned int newCapacity = capacity_ * 1.5;
            T* newStorage = new T[newCapacity];

            for (unsigned int i = 0; i < size_; i++) {
                newStorage[i] = storage_[i];
            }

            delete[] storage_;
            storage_ = newStorage;
            capacity_ = newCapacity;
        }

        void resizeP4() {
            unsigned int newCapacity = capacity_ * 2;
            T* newStorage = new T[newCapacity];

            for (unsigned int i = 0; i < size_; i++) {
                newStorage[i] = storage_[i];
            }

            delete[] storage_;
            storage_ = newStorage;
            capacity_ = newCapacity;
        }


    public:

        Vector() { // Vector constructor
            capacity_ = 4; // Capacity of 4
            storage_ = new T[capacity_]; // Storage_ stores dynamic memory space of size capacity_ and type T
            size_ = 0; // Current size 0
        }
    
        Vector(unsigned int c, T element) { // Vector constructor with two parameters
            capacity_ = c; // Capacity given by c
            storage_ = new T[capacity_]; // Storage_ stores dynamic memory space of size capacity_ and type T
            for (unsigned int i = 0; i < capacity_; i++) { // Adds the element of type T
                storage_[i] = element;
            }
            size_ = capacity_; // The vector is filled
        }
    
        T back() {
            if (!empty_()) {
                return storage_[size_ - 1];
            } else {
                throw out_of_range("Error: The stack is empty!");
            }
        }
    

        ~Vector() { // Destructor
            delete[] storage_; // Memory is freed
        }
    
        unsigned int size() const { // const makes sure the object's state is not modified
            return size_; // Returns the current size
        }
    
        unsigned int capacity() const { // const makes sure the object's state is not modified
            return capacity_; // Returns the allowed size
        }
    
        T& at(unsigned int pos) {
            assert(pos < size_); // Checks that pos is within the valid range, otherwise stops the program
            return storage_[pos]; // Returns a reference to the element at position pos
        }
    
        const T& at(unsigned int pos) const {
            /* Part by part analysis:
                const T& at: Says that a constant reference to the element is returned
                If it were inside, for example: (unsigned int pos), it means the value will not be modified throughout the function
                const after the parentheses: means that the function does not modify the object's state
            */
            assert(pos < size_); // Checks that pos is within the valid range, otherwise stops the program
            return storage_[pos]; // Returns a reference to the element at position pos
        }
    
        const T& operator[](unsigned int index) const {
            /* Part by part analysis:
                const T& at: Says that a constant reference to the element is returned
                operator[]: allows access to the element, as in an array
                const after the parentheses: means that the function does not modify the object's state
            */
            assert(index < size_); // Checks that the index is valid
            return storage_[index]; // Returns the element at position index
        }
    
        void push_back1(const T& elem) { // Places an element at the end
            // The value elem will not be modified throughout the function due to const
            if (size_ == capacity_) { // If the maximum capacity is reached, a resize is performed first
                resizeP1();
            }
            storage_[size_] = elem; // The element is added at position size, knowing that it is always one position ahead
            size_++; // Advances in the vector
        }

        void push_back2(const T& elem) {
            if (size_ == capacity_) {
                resizeP2(); // Resize if the vector is full, using a different resize method
            }
            storage_[size_] = elem; // Add the element at the end
            size_++; // Increment the size
        }
        
        void push_back3(const T& elem) {
            if (size_ == capacity_) {
                resizeP3(); // Resize if the vector is full, using a different resize method
            }
            storage_[size_] = elem; // Add the element at the end
            size_++; // Increment the size
        }
        
        void push_back4(const T& elem) {
            if (size_ == capacity_) {
                resizeP4(); // Resize if the vector is full, using a different resize method
            }
            storage_[size_] = elem; // Add the element at the end
            size_++; // Increment the size
        }
        
        void pop_back() {
            if (size_ > 0) {
                size_--; // Decrement the size, effectively removing the last element
            }
        }
        
        bool empty_() {
            return size_ == 0; // Return true if the vector is empty, false otherwise
        }
        
        

        void print() { // Function that prints a vector
            for (unsigned int i = 0; i < size_; i++) { // Iterates through the entire vector
                cout << " " << storage_[i]; // Prints each element separated by spaces
            }
        }
    
        unsigned int Size() const { return size_; }       // Method to get the size
        unsigned int Capacity() const { return capacity_; } // Method to get the capacity

        void generateRandomVector(int n, T minValue, T maxValue) {
            random_device rd; // Initialize a random number device for seeding
            mt19937 gen(rd()); // Initialize Mersenne Twister random number generator with the seed
            uniform_int_distribution<T> dist(minValue, maxValue); // Create a uniform distribution within the given range
        
            for (int i = 0; i < n; i++) {
                push_back1(dist(gen)); // Add a random number to the vector
            }
        }
        
        void generateRandomVectorWithDuplicates(int n, T minValue, T maxValue) {
            generateRandomVector(n, minValue, maxValue); // Generate a random vector first
        
            random_device rd; // Initialize a random number device for seeding
            mt19937 gen(rd()); // Initialize Mersenne Twister random number generator with the seed
            uniform_int_distribution<int> indexDist(0, size_ - 1); // Create a uniform distribution for indices within the vector
        
            int numDuplicates = n / 3; // Calculate the number of duplicates to introduce (approximately 1/3 of the size)
            for (int i = 0; i < numDuplicates; i++) {
                int sourceIndex = indexDist(gen); // Generate a random source index
                int targetIndex = indexDist(gen); // Generate a random target index
                storage_[targetIndex] = storage_[sourceIndex]; // Copy the element from the source index to the target index, creating a duplicate
            }
        }
                

        public:

        // Functions of task

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

    };

#endif 

