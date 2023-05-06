#include "Queue.h"
#include "LinkedList.h"

Queue::Queue()
{
	front = nullptr;
	rear = nullptr;
	queueData.queueCount = 0; //current queue length (set to 0 initially)
	queueData.totalIdleTime = 0; //if queueCount == 0; this is incremented
	queueData.totalOverTime = 0; //increment if current time > 720 & there are people in line
	queueData.maxQueueLength = 0; //if current queueCount>maxQueueLength, reset
	queueData.currItems = 0; //update as customers are added/removed from queue
	queueData.totalItems = 0; //running count of items purchased
	vector<int> cartList; //running list of carts helped
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
	queueData.queueCount++;
	//currItems += data.itemCount //(from linked list), waiting on team to finalize cart tracking
	//add cartID to cartList
}

queueNodeData Queue::deQueue()
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
	queueData.queueCount--;
	//currItems -= data.itemCount (from linked list), waiting on team to finalize cart tracking
	return data;
}

queueNodeData Queue::peek()
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
	cout << "Queue Count: " << queueData.queueCount << endl;
	cout << "Idle Time: " << queueData.totalIdleTime << endl;
	cout << "Overtime: " << queueData.totalOverTime << endl;
	cout << "Max Queue Length: " << queueData.maxQueueLength << endl;
	cout << "Current Items: " << queueData.currItems << endl;
	cout << "Total Items: " << queueData.totalItems << endl;
	cout << "Exit Time: " << vector<int> cartList << endl;
}
