#pragma once
#include "BTNode.h"
#include "Stack.h"
class BinaryTree
{
public:
	BTNode* root;
	BinaryTree(void);
	~BinaryTree(void);
	void insert(int data);
	void PushInStack(Stack& stack, BTNode* node);
	void inorderRec(BTNode* root);
	void inorderItr(BTNode* root);
};

