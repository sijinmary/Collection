#pragma once
class Collection
{
public:
    int current_size_;
    int capacity_;
    double* collectionArray_ = NULL;

    //default constructor
    Collection() :capacity_(10), current_size_(0) { collectionArray_ = new double[10]; }
    //constructor
    Collection(int size);;

    //getters
    int getSize();
    int getCapacity();

    //other methods
    void add(double value);
    void addFront(double value);
    double get(int ndx);
    double getFront();
    double getEnd();
    int find(double needle);
    friend std::ostream& operator<<(std::ostream& out, const Collection& c);
};

