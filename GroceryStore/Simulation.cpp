#include "Simulation.h"
#include "LinkedList.h"
#include "Queue.h"
#include <vector>


int items() {
    int numItems = 0;
    srand(time(0));
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

    return numItems;
}

int timeremain(int items) {
    int timeRemaining = 0.0;
    for (int i = 1; i <= items; i++) {
        timeRemaining += (rand() % 6 + 5) / 10.0;
    }
    return timeRemaining;
}

bool ischeckoutempty(vector<Queue> checkoutlines) {
    for (int i = 0; i < checkoutlines.size(); i++) {
        if (!checkoutlines[i].queueEmpty()) {
            return false;
        }
    }
    return true;
}