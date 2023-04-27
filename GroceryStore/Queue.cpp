#include "Queue.h"

Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
	queueCount = 0; //current queue length (set to 0 initially)
	totalIdleTime = 0; //if queueCount == 0; this is incremented
	totalOverTime = 0; //increment if current time > 720 & there are people in line
	maxQueueLength = 0; //if current queueCount>maxQueueLength, reset
	currItems = 0; //update as customers are added/removed from queue
	totalItems = 0; //running count of items purchased
}

void Queue::enQueue(queueNodeData nodeData)
{
	queueNode* tempNode = new queueNode;
	tempNode->data = nodeData;
	tempNode->nextPtr = nullptr;
	if (front == nullptr) {
		front = tempNode;
		rear = tempNode;
	}
	else {
	//adds the new node onto the end of the queue
		rear->nextPtr = tempNode;
		rear = tempNode;
	}
	queueCount++;
	//currItems += data.itemCount (from linked list), waiting on team to finalize cart tracking
	//add cartID to cartList
}

Queue::queueNodeData Queue::deQueue()
{
	queueNodeData data;
	if (front == nullptr) {
		cout << "The Queue is empty" << endl;
		return data;
	}
	// Store the data of the front node
	data = front->data;

	// Move the front pointer to the next node
	queueNode* temp = front;
	front = front->nextPtr;

	// Check if the queue is now empty
	if (front == nullptr) {
		rear = nullptr;
	}

	// Delete the node that was removed
	delete temp;

	// Update the queue count and current item count
	queueCount--;
	//currItems -= data.itemCount (from linked list), waiting on team to finalize cart tracking
	return data;
}

Queue::queueNodeData Queue::peek()
{
	return front->data;
}

bool Queue::queueEmpty()
{
	if (front == nullptr)
		return true;
	else
		return false;
}

void Queue::printQueue()
{
	cout << "Queue Count: " << queueCount << endl;
	cout << "Idle Time: " << totalIdleTime << endl;
	cout << "Overtime: " << totalOverTime << endl;
	cout << "Max Queue Length: " << maxQueueLength << endl;
	cout << "Current Items: " << currItems << endl;
	cout << "Total Items: " << totalItems << endl;
	cout << "Exit Time: " << vector<int> cartList << endl;
}
