#pragma once
#include <iostream>
using namespace std;
class LinkedList
{
	struct listType {
		int cartId; //unique id assigned
		int itemCount; //amount of items generated
		int enterQTime; //current ‘time’ + shopping time
		int exitQTime; //enterQTime + checkout time
	};
	struct Node {
		listType data;
		Node* nextPtr;
	};
private:
	Node* headPtr;
	Node* tailPtr;
	int count;
public:
	LinkedList();
	LinkedList(listType t);

	void addElement(listType type);
	listType peekBack();
	listType peek(int id);
	void delLastElement();
	void delElement(int id);
	void printList();
	bool listIsEmpty();
	int listCount();
};

