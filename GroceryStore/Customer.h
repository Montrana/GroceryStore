#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Customer {
private:
    int numItems;
    double timeRemaining;
public:
    Customer();
    Customer(int numItems, double timeRemaining);

    int getNumItems() { return numItems; }
    double getTimeRemaining() { return timeRemaining; }

    void getNumItems(int i) { numItems = i; }
    void getTimeRemaining(double t) { timeRemaining = t; }

    void start();
    void tick();
};