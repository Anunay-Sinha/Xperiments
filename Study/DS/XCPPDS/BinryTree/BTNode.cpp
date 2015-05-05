#include "BTNode.h"


BTNode::BTNode(void)
{
	this->data=0;
	left=nullptr;
	right=nullptr;
}

BTNode::BTNode(int data)
{
	this->data=data;
	left=nullptr;
	right=nullptr;
}


BTNode::~BTNode(void)
{
}
