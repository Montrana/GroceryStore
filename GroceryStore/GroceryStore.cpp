// GroceryStore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "LinkedList.h"
#include "Queue.h"
#include "Simulation.h"
#include "Customer.h"
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
    while (!(minutes > 720 && ischeckoutempty(allCheckoutLines))) {
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
                    try
                    {
                        tempInfo = totalCustomersInStore.peek(cartIdsInStore[j]); //storing info from certain element in linked list starting with 1,2,..etc.
                    }
                    catch(exception err)
                    {
                        cout << err.what();
                    }
                    if (tempInfo.enterQTime == minutes) { //checking if customer needs to be moved to checkout line
                        int tempCardId = tempInfo.cartId;
                        int k = 0;
                        queueNodeData tempQueueInfo, smallestLine = allCheckoutLines[k].peek(); //holding the current element of the queue's data and holding the data of the smallest checkout line
                        int smallestLineIndex = 0; //holding the value of k at which the smallest line is
                        while (k < allCheckoutLines.size()) {
                            
                            tempQueueInfo = allCheckoutLines[k].peek();
                            if (tempQueueInfo.itemCount < smallestLine.itemCount) {
                                smallestLine = tempQueueInfo;
                                smallestLineIndex = k;
                            }
                            queueNodeData tempqueuedata; //creating a temp variable for the customer that needs to be added to a checkout line
                            tempqueuedata.timeAvailable = tempInfo.exitQTime;
                            tempqueuedata.itemCount = tempInfo.itemCount;
                            allCheckoutLines[smallestLineIndex].enQueue(tempqueuedata, tempCardId); //adding them to the predetermined shortest line.

                            k++;
                        }
                    }
                    //for loop through the main vector to check exitQTimes, making sure to hold data in a tempVar using peek to access info
                    queueNodeData tempVar; //holding data from checkoutlines
                    for (int i = 0; i < allCheckoutLines.size(); i++) {
                        tempVar = allCheckoutLines[i].peek();
                        if (tempVar.timeAvailable == 0 && !allCheckoutLines[i].queueEmpty()) {
                            try {
                                allCheckoutLines[i].deQueue();
                            }
                            catch(exception err)
                            {
                                cout << err.what();
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
            for (int j = 0; j < cartIdsInStore.size(); j++) {
                try
                {
                    tempInfo = totalCustomersInStore.peek(cartIdsInStore[j]); //storing info from certain element in linked list starting with 1,2,..etc.
                }
                catch (exception err)
                {
                    cout << err.what();
                }
                if (tempInfo.enterQTime == minutes) { //checking if customer needs to be moved to checkout line
                    int tempCardId = tempInfo.cartId;
                    int k = 0;
                    queueNodeData tempQueueInfo, smallestLine = allCheckoutLines[k].peek(); //holding the current element of the queue's data and holding the data of the smallest checkout line
                    int smallestLineIndex = 0; //holding the value of k at which the smallest line is
                    while (k < allCheckoutLines.size()) {

                        tempQueueInfo = allCheckoutLines[k].peek();
                        if (tempQueueInfo.itemCount < smallestLine.itemCount) {
                            smallestLine = tempQueueInfo;
                            smallestLineIndex = k;
                        }
                        queueNodeData tempqueuedata; //creating a temp variable for the customer that needs to be added to a checkout line
                        tempqueuedata.timeAvailable = tempInfo.exitQTime;
                        tempqueuedata.itemCount = tempInfo.itemCount;
                        allCheckoutLines[smallestLineIndex].enQueue(tempqueuedata, tempCardId); //adding them to the predetermined shortest line.

                        k++;
                    }
                }
                //for loop through the main vector to check exitQTimes, making sure to hold data in a tempVar using peek to access info
                queueNodeData tempVar; //holding data from checkoutlines
                for (int i = 0; i < allCheckoutLines.size(); i++) {
                    tempVar = allCheckoutLines[i].peek();
                    if (tempVar.timeAvailable == 0 && !allCheckoutLines[i].queueEmpty()) {
                        try {
                            allCheckoutLines[i].deQueue();
                        }
                        catch (exception err)
                        {
                            cout << err.what();
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
    }
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
