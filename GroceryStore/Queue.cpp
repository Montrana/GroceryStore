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


void Queue::enQueue(queueNodeData nodeData, int cartId) //adds an assembled customer to the back of the queue, and adds the cart ID to the list of carts helped
{
	queueData.cartList.push_back(cartId);
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
	if (queueData.queueCount > queueData.maxQueueLength)
		queueData.maxQueueLength = queueData.queueCount;
	queueData.currItems += nodeData.itemCount;
	queueData.totalItems += nodeData.itemCount;
}

queueNodeData Queue::deQueue() //removes the front most customer from the queue
{
	queueNodeData data{};
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
	queueData.currItems -= data.itemCount;
	return data;
}

queueNodeData Queue::peek() //shows the front constomer's data
{
	return front->data;
}

void Queue::incrementIdleTime() //increases the queue's idle time
{
	queueData.totalIdleTime++;
}

void Queue::incrementOvertime() //increases the queue's overtime
{
	queueData.totalOverTime++;
}

bool Queue::queueEmpty() //checks if the queue is empty and returns true if so, otherwise false
{
	if (front == nullptr)
		return true;
	else
		return false;
}

void Queue::printQueue() //shows the queue's information
{
	cout << "Queue Count: " << queueData.queueCount << endl;
	cout << "Idle Time: " << queueData.totalIdleTime << endl;
	cout << "Overtime: " << queueData.totalOverTime << endl;
	cout << "Max Queue Length: " << queueData.maxQueueLength << endl;
	cout << "Current Items: " << queueData.currItems << endl;
	cout << "Total Items: " << queueData.totalItems << endl;
	cout << "Carts Helped: ";
	for (int id : queueData.cartList) {
		cout << id << " ";
	}
}
