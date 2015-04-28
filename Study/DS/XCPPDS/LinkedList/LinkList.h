#pragma once
#include "Node.h"
#include "iostream"
class LinkList
{
public:
	LinkList(void);
	~LinkList(void);
	//const Node* getHead();
	void pushBack(int data);
	void insert(int pos,int data);
	int delete_(int pos);
	void recReverse(Node** head);
	void printList();
	void printList(Node* head);

	Node* _head;
};

