//
// Created by sijin on 9/29/2022.
//
#include <iostream>
#include <sstream>
#include "Collection.h"
using namespace std;
void TestCollection();
void TestExceedSize();
void TestAddBeginning();
void TestExtractionOperator();
bool checkCase(std::string name, bool condition);
int main()
{
    TestCollection();
    TestExceedSize();
    TestAddBeginning();
    TestExtractionOperator();

    //Testing Collection Class
    cout << "\nChecking add method: " << endl;
    Collection two(5);
    two.add(34);
    two.add(12);
    two.add(2.4);
    cout <<"Capacity = "<< two.getCapacity() << endl;
    two.add(12);
    two.add(2.3);
    two.add(7.4);

    cout << "Checking addFront method: " << endl;
    Collection three(5);
    three.addFront(34);
    three.addFront(12);
    three.addFront(2.4);
    cout << "Capacity = " << three.getCapacity() << endl;
    three.addFront(12);
    three.addFront(2.3);
    three.addFront(7.4);

    cout << "Checking get method: " << endl;
    cout << "Capacity = " << three.getCapacity() << endl;
    three.get(1);
    three.get(23);
    

    cout << "Checking getFront and getEnd method: " << endl;
    Collection four(5);
    cout << "first element = " << four.getFront() << endl;
    cout << "Last element = " << four.getEnd() << endl;
    four.add(34);
    four.add(12);
    four.add(12.5);
    cout << "first element = " << four.getFront() << endl; 
    cout << "Last element = " << four.getEnd() << endl;
    

    cout << "Checking find method: \n ";
    cout << "find the element 12.5 index: " << four.find(12.5) << endl;
    cout << "find the element 100.5 index: " << four.find(100.5) << endl;

    cout << "Checking operator<< method: \n ";
    cout << four << endl;

    return 0;
}

void TestCollection() {
    Collection one;
    one.add(2.2);
    //one.add(2.5);
    checkCase("Adding 1", one.get(0) == 2.2);
    checkCase("Adding 2", one.get(1) == 2.5);
    checkCase("Check Size", one.getSize() == 2);
    
}
void TestExceedSize() {
    Collection one;
    for (int i = 0; i < one.getCapacity(); i++) {
        one.add(i);
    }
    checkCase("Exceed Size 1", one.get(0) == 0);
    checkCase("Exceed Size 2", one.get(one.getCapacity() - 1) == one.getCapacity() -1); 
}
void TestAddBeginning() {
    Collection one;
    for (double i = 0; i < 5; i += 1) {
        one.add(i);
    }
    one.addFront(2);
    checkCase("Add to Front Check 1", one.get(0) == 2);
    checkCase("Add to Front Check 2", one.get(5) == 4);
    checkCase("Add to Front Check 3", one.getSize() == 6);
}
void TestExtractionOperator() {
    Collection one;
    one.add(1);
    one.add(2);
    stringstream sout;
    sout << one;
    checkCase("Overloaded Extraction Operator", sout.str() == "1 2");
}
bool checkCase(string name, bool condition) {
    if (!condition) {
        cout << "Failed: " << name << endl;
    }
    else {
        cout << name << ": passed" << endl;
    }
    return condition;
}