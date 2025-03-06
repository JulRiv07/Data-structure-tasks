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
    
    // Insert function for the "Exercise 1"...
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
    //End of the function "insert"

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

    void print() {
        for (unsigned int i = 0; i < size_; i++) {
            cout << " " << storage_[i];
        }
        cout << endl;
    }

    void generateRandomVector(int n, T minValue, T maxValue) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<T> dist(minValue, maxValue);
    
        for (int i = 0; i < n; i++) {
            push_back(dist(gen));
        }
    }
};

#endif // VECTOR_H

