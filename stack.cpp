#ifndef __STACK_CPP
#define __STACK_CPP
#include "stack.h"

template <class T>
Stack<T>::Stack()
{
}
    
template <class T>
Stack<T>::Stack(Stack<T>& otherStack)
{
	ListItem<T> *otemp=otherStack.list.getHead();
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
Stack<T>::~Stack()
{
}

template <class T>
void Stack<T>::push(T item)
{
	list.insertAtHead(item);

}

template <class T>
T Stack<T>::top()
{
	ListItem<T> *start=list.getHead();
	return start->value;
}

template <class T>
T Stack<T>::pop()
{
	ListItem<T> *start=list.getHead();
	T a=start->value;
	list.deleteHead();
	return a;
}

template <class T>
int Stack<T>::length()
{
	int a=list.length();
	return a;
}

template <class T>
bool Stack<T>::isEmpty()
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
