#pragma once
#include <iostream>
using namespace std;
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

class LinkedList
{
private:
	Node* headPtr;
	Node* tailPtr;
	static int count;
public:
	LinkedList();
	LinkedList(int id, int count, int enterTime, int exitTime);

	void addElement(int id, int count, int enterTime, int exitTime);
	listType peekBack();
	listType peek(int id);
	void delLastElement();
	void delElement(int id);
	void printList();
	bool listIsEmpty();
	static int listCount();
};

