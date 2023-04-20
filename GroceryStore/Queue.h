#pragma once
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
	
public:
	Queue();
	void enQueue(queueNodeData nodeData);
	queueNodeData deQueue();
	queueNodeData peek();
	bool queueEmpty();
	void printQueue();
};

