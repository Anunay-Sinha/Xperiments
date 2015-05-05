#include "BinaryTree.h"
#include "iostream"

BinaryTree::BinaryTree(void)
{
	root=nullptr;
}


BinaryTree::~BinaryTree(void)
{
}

void BinaryTree::PushInStack(Stack& stack, BTNode* node)
{
	if(node==nullptr)
		return;
	while(node!=nullptr)
	{
		stack.push((long)node);
		node=node->left;
	}

}

void BinaryTree::inorderItr(BTNode* head)
{
	Stack stack(20);
	//stack.push((long)&head);
	long data;
	PushInStack(stack,head);
	while(stack.peek(data))
	{	
		if(stack.pop(data))
		{
			BTNode* temp=(BTNode*)data;
			std::cout<<" ["<<temp->data<<"] ";
			if(temp->right!=nullptr)
			{
				PushInStack(stack,temp->right);
			}
		}		
	}
	
}

void BinaryTree::inorderRec(BTNode* head)
{
	if(head==nullptr)
		return;
	inorderRec(head->left);
	std::cout<<" ["<<head->data<<"] ";
	inorderRec(head->right);
}

void 
BinaryTree::insert(int data)
{
	BTNode* temp=new BTNode(data);
	BTNode* current=root;
	BTNode* prev=nullptr;
	if(root==nullptr)
	{
		root=temp;
		return;
	}
	while(1)
	{
		
		if(data>current->data)
		{
			//prev=current;
			if(current->right==nullptr)
			{
				current->right=temp;
				break;
			}
			current=current->right;
		}
		else
		{
			if(current->left==nullptr)
			{
				current->left=temp;
				break;
			}
			current=current->left;
		}
	}
}

int main()
{
	BinaryTree bt;
	long data=(long)&bt;
	BinaryTree *bt2=(BinaryTree*)data;
	//std::cout<<"\n\n"<<data<<"\n";
	bt2->insert(20);
	bt.insert(10);
	bt.insert(5);
	bt.insert(15);
	bt.insert(2);
	bt.insert(7);
	bt.insert(12);
	bt.insert(16);
	bt.insert(25);
	bt.insert(22);
	bt.insert(29);
	//bt.inorderRec(bt.root);
	bt.inorderItr(bt.root);
	return -1;
}