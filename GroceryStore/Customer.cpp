#include "Customer.h"

using namespace std;

Customer::Customer() {
    numItems = 0;
    timeRemaining = 0;
}

Customer::Customer(int i, double t) {
    numItems = i;
    timeRemaining = t;
}

void Customer::start() { // randomly generates the number of items based on our observations
    int randNum = rand() % 100 + 1;
    if (randNum <= 40) {
        numItems = rand() % 11;
    }
    else if (randNum <= 70) {
        numItems = rand() % 10 + 11;
    }
    else if (randNum <= 90) {
        numItems = rand() % 10 + 21;
    }
    else {
        numItems = rand() % 30 + 31;
    }
    // initializes the time remaining based on the # of items (0.5-1 minute per item)
    timeRemaining = 0.0;
    for (int i = 1; i <= numItems; i++) {
        timeRemaining += (rand() % 6 + 5) / 10.0;
    }
}

void Customer::tick() {
    timeRemaining -= 1;
}