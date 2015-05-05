#include "LinkListProbs.h"
//#include "LinkList.h"

LinkListProbs::LinkListProbs(void)
{
}


LinkListProbs::~LinkListProbs(void)
{  
}

void LinkListProbs::reverseInPair(Node** head)
{
	Node* first=*head;
	if(first==nullptr)
		return;
	if(first->next==nullptr)
		return;
	Node* next=first->next->next;
	first->next->next=first;
	reverseInPair(&next);
	*head=first->next;
	first->next=next;
	
}


int main()
{
	LinkList list;
	list.pushBack(10);
	list.pushBack(20);
	list.pushBack(30);
	list.pushBack(40);
//	list.pushBack(50);
	list.printList();
	LinkListProbs probs;
	probs.reverseInPair(&list._head);
	list.printList();
	return -1;
}
