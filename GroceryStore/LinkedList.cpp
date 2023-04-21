#include "LinkedList.h"
/// <summary>
/// Linked list constructor
/// </summary>
LinkedList::LinkedList()
{
	headPtr = nullptr;
	tailPtr = nullptr;
	count = 0;
}

/// <summary>
/// Linked list contstructor override, sets first node to node T
/// </summary>
/// <param name="t">The data that is used to initialize the list</param>
LinkedList::LinkedList(listType t)
{
	Node* tempPtr = new Node;
	tempPtr->data = t;
	tempPtr->nextPtr = nullptr;
	headPtr = tempPtr;
	tailPtr = tempPtr;
	count = 1;
}

/// <summary>
/// Adds an element to the end of the list, would probably want to sort this by exit time
/// </summary>
/// <param name="type">the data that is added</param>
void LinkedList::addElement(listType type)
{
	Node* tempNode = new Node;
	tempNode->data = type;
	tempNode->nextPtr = nullptr;
	if (headPtr == nullptr)
	{
		headPtr = tempNode;
		tailPtr = tempNode;
	}
	else {
		tailPtr->nextPtr = tempNode;
		tailPtr = tempNode;
	}
	count++;
}

/// <summary>
/// Looks at the last element of the list and returns it's data
/// </summary>
/// <returns>the data of the last item</returns>
LinkedList::listType LinkedList::peekBack()
{
	return tailPtr->data;
}
/// <summary>
/// looks at the element with the given id
/// </summary>
/// <param name="id">the ID that will be compared with each cart ID</param>
/// <returns>the data of the node</returns>
LinkedList::listType LinkedList::peek(int id)
{
	Node* tempNode = headPtr;
	while (tempNode != nullptr && tempNode->nextPtr != nullptr) {
		if (tempNode->nextPtr->data.cartId == id) {
			Node* returnNode = tempNode->nextPtr;
			return returnNode->data;
			break;
		}
		tempNode = tempNode->nextPtr;
	}
	throw runtime_error("Could not find ID: " + id);
}
/// <summary>
/// Deletes the last element of the list
/// </summary>
void LinkedList::delLastElement()
{
	Node* tempNode = headPtr;
	while (tempNode != nullptr && tempNode->nextPtr != nullptr) {
		if (tempNode->nextPtr->data.cartId == tailPtr->data.cartId) {
			Node* delNode = tempNode->nextPtr;
			tempNode->nextPtr = tempNode->nextPtr->nextPtr;
			delete delNode;
			delNode = nullptr;
			count--;
			if (headPtr == tempNode)
			{
				delete headPtr;
				headPtr = nullptr;
				tailPtr = nullptr;
			}
			break;
		}
		tempNode = tempNode->nextPtr;
	}
}
/// <summary>
/// deletes last element with the specified ID
/// </summary>
/// <param name="id">the id to delete</param>
void LinkedList::delElement(int id)
{
	Node* tempNode = headPtr;
	while (tempNode != nullptr && tempNode->nextPtr != nullptr) {
		if (tempNode->nextPtr->data.cartId == id) {
			if (tempNode == headPtr)
			{
				headPtr = tempNode->nextPtr;
			}
			if (tempNode->nextPtr == tailPtr)
			{
				tailPtr = tempNode;
			}
			Node* delNode = tempNode->nextPtr;
			tempNode->nextPtr = tempNode->nextPtr->nextPtr;
			delete delNode;
			delNode = nullptr;
			count--;
			break;
		}
		tempNode = tempNode->nextPtr;
	}
	throw runtime_error("Could not find ID: " + id);
}

/// <summary>
/// prints the list
/// </summary>
void LinkedList::printList()
{
	Node* tempNode = headPtr;
	while (tempNode != nullptr) {
		cout << "ID: " << tempNode->data.cartId << endl;
		cout << "Item Count: " << tempNode->data.itemCount << endl;
		cout << "Enter Time: " << tempNode->data.enterQTime << endl;
		cout << "Exit Time: " << tempNode->data.exitQTime << endl;
		cout << endl;
		tempNode = tempNode->nextPtr;
	}
}
/// <summary>
/// returns if the list is empty
/// </summary>
/// <returns>if the list is empty or not</returns>
bool LinkedList::listIsEmpty()
{
	if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/// <summary>
/// returns the number of items in the list
/// </summary>
/// <returns>the number of items in the list</returns>
int LinkedList::listCount()
{
	return count;
}
