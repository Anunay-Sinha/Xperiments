#include "LinkList.h"


LinkList::LinkList(void)
{
	_head=nullptr;
}
void LinkList::printList(Node* head)
{
	if(head==nullptr)
		return;
	Node* itr=head;
	while(itr->next!=nullptr)
	{
		std::cout<<" ["<<itr->data<<"], ";
		itr=itr->next;
	}
	std::cout<<" ["<<itr->data<<"]\n";


}
void LinkList::printList()
{
	if(_head==nullptr)
		return;
	Node* itr=_head;
	while(itr->next!=nullptr)
	{
		std::cout<<" ["<<itr->data<<"], ";
		itr=itr->next;
	}
	std::cout<<" ["<<itr->data<<"]\n";
}

int LinkList::delete_(int pos)
{
	if(_head==nullptr)
	{
		std::cout<<"Throw Exception";
		return -1;
	}
	if(pos==1)
	{
		Node* temp=_head;
		int data=temp->data;
		_head=_head->next;
		free(temp);
		return data;
	}
	Node* itr=_head;
	int cntr=1;
	Node* prev=_head;
	while(itr->next!=nullptr && cntr<pos)
	{
		prev=itr;
		itr=itr->next;
		++cntr;
	}
	if(itr->next!=nullptr)
	{
		prev->next=itr->next;
		int data=itr->data;
		free(itr);
		return data;
	}
	else if(cntr==pos)
	{
		prev->next=nullptr;
		int data=itr->data;
		free(itr);
		return data;
	}
	std::cout<<"Item to be deleted is beyond the list.";
	return -1;

	
}

void LinkList::insert(int pos,int data)
{
	if(_head==nullptr)
	{
		return;
	}
	int cntr=1;
	Node* itr=_head;
	while(itr!=nullptr && cntr<pos)
	{
		itr=itr->next;
		++cntr;
	}

	if(itr!=nullptr)
	{
		Node* temp=new Node();
		temp->data=data;
		if(cntr==1)
		{
			std::cout<<"Insertion at the head. Head will get replaced.\n";
			temp->next=_head;
			_head=temp;
		}
		else
		{
			temp->next=itr->next;
			itr->next=temp;
		}
	}
	else
	{
		std::cout<<"Error::Point was outside the link list\n";
	}
	
}

void LinkList::pushBack(int data)
{
	Node* temp=new Node();
	temp->data=data;
	temp->next=nullptr;
	if(_head==nullptr)
	{
		_head=temp;
	}
	else
	{
		// Goto to the last pointer
		Node* itr=_head;
		while(itr->next!=nullptr)
		{
			itr=itr->next;
		}
		itr->next=temp;
	}


}

// Pointer to a pointer because i need to return the pointer back.
void LinkList::recReverse(Node** head)
{
	if(head==nullptr)
		return;
	Node* first=*head;
	Node* rest=first->next;
	if(rest==nullptr)
		return;
	recReverse(&rest);
	first->next->next=first;
	first->next=nullptr;
	*head=rest;
	printList(rest);

}
LinkList::~LinkList(void)
{
}




int main()
{
	LinkList list;
	list.pushBack(10);
	list.pushBack(20);
	list.pushBack(30);
	list.pushBack(40);
	list.insert(4,25);
	list.printList();
	//list.delete_(4);
	list.recReverse(&list._head);
	list.printList();
	return -1;
}