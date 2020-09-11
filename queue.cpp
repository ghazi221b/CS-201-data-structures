#ifndef __QUEUE_CPP
#define __QUEUE_CPP
#include "queue.h"

template <class T>
Queue<T>::Queue()
{

}
    
template <class T>
Queue<T>::Queue(Queue<T>& otherQueue)
{
	ListItem<T> *otemp=otherQueue.list.getHead();
	T hold;
	if(otemp!=NULL)
	{
		while(otemp!=NULL)
		{
		hold=otemp->value;
		list.insertAtTail(hold);
		otemp=otemp->next;
		}
	}

}

template <class T>
Queue<T>::~Queue()
{

}

template <class T>
void Queue<T>::enqueue(T item)
{	
	list.insertAtHead(item);
}

template <class T>
T Queue<T>::front()
{
	ListItem<T> *start=list.getTail();
	return start->value;
}

template <class T>
T Queue<T>::dequeue()
{
	ListItem<T> *start=list.getTail();
	T a=start->value;
	list.deleteTail();
	return a;	
}

template <class T>
int Queue<T>::length()
{
	int a=list.length();
	return a;
	
}

template <class T>
bool Queue<T>::isEmpty()
{
	ListItem<T> *start=list.getHead();
	if(start==NULL)
	{
		return true;
	}
	else
		return false;
}


#endif
