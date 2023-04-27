#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Queue
{
private:
	struct queueNodeData {
		int timeAvailable; //clock time when current
		//customer is dequeued
		int itemCount; //the number of items for
		//current customer
	};
	struct queueNode {
		queueNodeData data;
		queueNode* nextPtr;
	};

	queueNode* front;
	queueNode* rear;
	int queueCount; //current queue length (set to 0 initially)
	int totalIdleTime; //if queueCount == 0; this is incremented
	int totalOverTime; //increment if current time > 720 & there are people in line
	int maxQueueLength; //if current queueCount>maxQueueLength, reset
	int currItems; //update as customers are added/removed from queue
	int totalItems; //running count of items purchased
	vector<int> cartList; //running list of carts helped
	
public:
	Queue();
	void enQueue(queueNodeData nodeData);
	queueNodeData deQueue();
	queueNodeData peek();
	bool queueEmpty();
	void printQueue();
};

