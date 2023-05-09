// GroceryStore.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Partners: Montana Nicholson, Alyssa McMurry, Haley Nilsen
// Date: April 18th 2023
// Github link: https://github.com/Montrana/GroceryStore
// Summary: This project simulates a grocery store using linked lists and queues
// Primary Roles:
//      Haley: Main code
//      Montana: Linked Lists and some of main
//      Alyssa: Queues and some of main
//

#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"
#include "Queue.h"
#include "Simulation.h"
using namespace std;

int main()
{
    srand(time(0));
    int checkoutLines, customerCount = 0;
    cout << "Enter the amount of checkout lines (amount 1-10): " << endl;
    cin >> checkoutLines;
    vector<Queue> allCheckoutLines;
    for (int i = 1; i <= checkoutLines; i++) {
        //string tempName = "queue" + to_string(i);
        //queueNodeData tempName;
        Queue tempqueue = Queue();
        allCheckoutLines.push_back(tempqueue);//trying to add the queues to one big vector so I can access them?
    }
    LinkedList totalCustomersInStore;
    vector<int> cartIdsInStore;
    int minutes = 0;
    while (minutes < 720 || !ischeckoutempty(allCheckoutLines)) {
        if (minutes < 720) {
            int customers;
            
            customers = (rand() % 3) + 1; //randomizing number of customers that enter in the store;
            int i = 0;
            while (i < customers) {
                int itemCount = items();
                int timeremaining = timeremain(itemCount);
                int enterQ = minutes + timeremaining;
                int exitQTime = enterQ + ((itemCount * 15) / 60);
                totalCustomersInStore.addElement(customerCount + 1, itemCount, enterQ, exitQTime);
                cartIdsInStore.push_back(customerCount + 1);
                customerCount++;
                //cartId's start at 1. This should allow us to increment peek() using cartId's. 
                listType tempInfo; //this is so we can access the information from the linkedlist elements, and use them to check enterQ times
                //while (linkedcount <= totalCustomersInStore.listCount()) 
                for(int j = 0; j < cartIdsInStore.size(); j++){
                    if (totalCustomersInStore.has(cartIdsInStore[j]))
                    {
                        tempInfo = totalCustomersInStore.peek(cartIdsInStore[j]); //storing info from certain element in linked list starting with 1,2,..etc.
                        if (tempInfo.enterQTime <= minutes) { //checking if customer needs to be moved to checkout line
                            int tempCardId = tempInfo.cartId;
                            int smallestLine = 0;
                            for (int k = 0; k < allCheckoutLines.size(); k++)
                            {
                                if (allCheckoutLines[smallestLine].peek().itemCount > allCheckoutLines[k].peek().itemCount) {
                                    smallestLine = k;
                                }
                            }
                            queueNodeData tempqueuedata; //creating a temp variable for the customer that needs to be added to a checkout line
                            tempqueuedata.timeAvailable = tempInfo.exitQTime;
                            tempqueuedata.itemCount = tempInfo.itemCount;
                            allCheckoutLines[smallestLine].enQueue(tempqueuedata, tempCardId); //adding them to the predetermined shortest line.
                            totalCustomersInStore.delElement(cartIdsInStore[j]);
                            cartIdsInStore.erase(cartIdsInStore.begin() + j);
                        }
                    } 
                    
                    //for loop through the main vector to check exitQTimes, making sure to hold data in a tempVar using peek to access info
                    queueNodeData tempVar; //holding data from checkoutlines
                    for (int i = 0; i < allCheckoutLines.size(); i++) {
                        if (!allCheckoutLines[i].queueEmpty())
                        {
                            tempVar = allCheckoutLines[i].peek();
                            if (tempVar.timeAvailable <= minutes) {
                                allCheckoutLines[i].deQueue();
                            }
                        }
                    }
                }
                i++;
            }
            for (int c = 0; c < allCheckoutLines.size(); c++)
            {
                if (allCheckoutLines[c].queueEmpty()) {
                    allCheckoutLines[c].incrementIdleTime();
                }
            }
        }
        else {
            listType tempInfo; //this is so we can access the information from the linkedlist elements, and use them to check enterQ times
            //while (linkedcount <= totalCustomersInStore.listCount()) 
            for (int j = 0; j < cartIdsInStore.size(); j++) {
                if (totalCustomersInStore.has(cartIdsInStore[j]))
                {
                    tempInfo = totalCustomersInStore.peek(cartIdsInStore[j]); //storing info from certain element in linked list starting with 1,2,..etc.
                    if (tempInfo.enterQTime <= minutes) { //checking if customer needs to be moved to checkout line
                        int tempCardId = tempInfo.cartId;
                        int smallestLine = 0;
                        for (int k = 0; k < allCheckoutLines.size(); k++)
                        {
                            if (allCheckoutLines[smallestLine].peek().itemCount > allCheckoutLines[k].peek().itemCount) {
                                smallestLine = k;
                            }
                        }
                        queueNodeData tempqueuedata; //creating a temp variable for the customer that needs to be added to a checkout line
                        tempqueuedata.timeAvailable = tempInfo.exitQTime;
                        tempqueuedata.itemCount = tempInfo.itemCount;
                        allCheckoutLines[smallestLine].enQueue(tempqueuedata, tempCardId); //adding them to the predetermined shortest line.
                        totalCustomersInStore.delElement(cartIdsInStore[j]);
                        cartIdsInStore.erase(cartIdsInStore.begin() + j);
                    }
                }

                //for loop through the main vector to check exitQTimes, making sure to hold data in a tempVar using peek to access info
                queueNodeData tempVar; //holding data from checkoutlines
                for (int i = 0; i < allCheckoutLines.size(); i++) {
                    if (!allCheckoutLines[i].queueEmpty())
                    {
                        tempVar = allCheckoutLines[i].peek();
                        if (tempVar.timeAvailable <= minutes) {
                            allCheckoutLines[i].deQueue();
                        }
                    }
                }
            }
            for (int i = 0; i < allCheckoutLines.size(); i++) {
                if (!allCheckoutLines[i].queueEmpty()) {
                    allCheckoutLines[i].incrementOvertime();
                }
            }
        }
        minutes ++;
    }
    for (int i = 0; i < allCheckoutLines.size(); i++) {
        allCheckoutLines[i].printQueue();
        cout << endl;
    }
}