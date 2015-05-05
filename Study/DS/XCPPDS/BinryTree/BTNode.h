#pragma once
class BTNode
{
public:
	BTNode* left;
	BTNode* right;
	int data;
	BTNode(void);
	BTNode(int);
	~BTNode(void);
};

