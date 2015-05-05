#include "Stack.h"


Stack::Stack(void)
{
	arr=new long[10];
	top=-1;
	size=10;
}

Stack::Stack(int size):size(size)
{
	arr=new long[size];
	top =-1;
}

Stack::~Stack(void)
{
	delete []arr;
}

bool Stack::push(long data)
{
	if(top==size)
		return false;
	arr[++top]=data;
	return true;
}

bool Stack::peek(long &data)
{
	if(top==-1)
	{
		return false;
	}
	data=arr[top];
	return true;
}

bool Stack::pop(long &data)
{
	if(top==-1)
	{
		return false;
	}
	data=arr[top--];
	return true;
}