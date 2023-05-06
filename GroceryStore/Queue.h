#pragma once
#include <iostream>
#include <vector>
using namespace std;


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

struct queueData {
	int queueCount = 0; //current queue length (set to 0 initially)
	int totalIdleTime = 0; //if queueCount == 0; this is incremented
	int totalOverTime = 0; //increment if current time > 720 & there are people in line
	int maxQueueLength = 0; //if current queueCount>maxQueueLength, reset
	int currItems = 0; //update as customers are added/removed from queue
	int totalItems = 0; //running count of items purchased
	vector<int> cartList; //running list of carts helped
};

class Queue
{
private:
	queueNode* front;
	queueNode* rear;
	queueData queueData;
public:
	Queue();
	void enQueue(queueNodeData nodeData, int cartId);
	queueNodeData deQueue();
	queueNodeData peek();
	void incrementIdleTime();
	void incrementOvertime();
	bool queueEmpty();
	void printQueue();
};


