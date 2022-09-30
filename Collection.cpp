// Collection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Collection.h"

//constructor
Collection::Collection(int size) :current_size_(0), capacity_(size) { collectionArray_ = new double[size]; }

//returns the number of elements in the array
int Collection::getSize() {
    return current_size_;
}
//returns the maximum number of elements allowed in 
//the current array
int Collection::getCapacity() {
    return capacity_;
}
//add the value to the back of the array
void Collection::add(double value) {
    try {
        if (current_size_ < capacity_) {
            collectionArray_[current_size_] = value;
            current_size_++;
        }
        else {
            throw std::runtime_error("List Full");
        }
    }
    catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }
}
// add an item to the front of the list
void Collection::addFront(double value) {
    try {
        if (current_size_ < capacity_) {
            for (int i = current_size_; i > 0; i--) {
                collectionArray_[i] = collectionArray_[i - 1];
            }
            collectionArray_[0] = value;
            current_size_++;
        }
        else {
            throw std::runtime_error("List Full");
        }
    }
    catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

}
//Gets the value stored at the specified position
double Collection::get(int ndx) {
    try {
        if (ndx >= current_size_ || ndx < 0) {
            throw std::out_of_range("The index is outside the bounds of the array");
        }
        else {
            return collectionArray_[ndx];
        }
    }
    catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }
}// Returns the first value in the array
double Collection::getFront() {
    try {
        if (current_size_ == 0) {
            throw std::out_of_range(" Array is Empty");
        }
        else {
            return collectionArray_[0];
        }
    }
    catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }
}
//Returns the last value in the array
double Collection::getEnd() {
    try {
        if (current_size_ == 0) {
            throw std::out_of_range(" Array is Empty");
        }
        else {
            return collectionArray_[current_size_ - 1];
        }
    }
    catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }
}
//returns the position of needle in the list
int Collection::find(double needle) {
    for (int i = 0; i < current_size_; i++) {
        if (collectionArray_[i] == needle) {
            return i;
        }
    }
    return -1;
}
// : overload the extraction operator to display the list.
std::ostream& operator<<(std::ostream& out, const Collection& c) {
    for (int i = 0; i < c.current_size_; i++) {
        out << c.collectionArray_[i];
        if (i < c.current_size_-1) {
            out << " ";
        }
    }
    return out;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
