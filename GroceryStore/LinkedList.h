#pragma once
class LinkedList
{
private:
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
public:
	LinkedList();

	void addElement(listType type);
	listType peek();
	void delElement();
	void printList();
	bool listIsEmpty();
	static int listCount();
};

