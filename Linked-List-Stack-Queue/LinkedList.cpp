#ifndef __LIST_CPP
#define __LIST_CPP

#include <cstdlib>
#include "LinkedList.h"
#include <iostream>

template <class T>
LinkedList<T>::LinkedList()
{
	head=NULL;
	tail=NULL;

}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
	ListItem<T> *otemp= otherLinkedList.head;
	ListItem<T> *temp2=head;
	ListItem<T> *ntemp;
	T hold;
	if(otemp==NULL)
	{
		head=NULL;
		tail=NULL;
	}
	else
	{
		hold=otemp->value;
		head=new ListItem<T>(hold);
		tail=head;
		otemp=otemp->next;
		

		while(otemp!=NULL)
		{	hold=otemp->value;
			ntemp=new ListItem<T>(hold);
			tail->next=ntemp;
			ntemp->prev=tail;
			tail=ntemp;
			otemp=otemp->next;
		}
	
	}



}

template <class T>
LinkedList<T>::~LinkedList()
{
	ListItem<T> *temp;
	temp=head;
	while(temp!=NULL)
	{
		ListItem<T> *temp2=temp;
		temp=temp->next;
		delete temp2;
	}
	head=NULL;


}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
	ListItem<T> *temp=new ListItem<T>(item);
	temp->prev=NULL;
	temp->next=NULL;
	temp->value=item;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		head->prev=temp;
		temp->next=head;
		head=temp;
	}

}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
	ListItem<T> *temp=new ListItem<T>(item);
	temp->prev=NULL;
	temp->next=NULL;
	temp->value=item;
	if(tail==NULL)
	{
		head=temp;
		tail=temp;
	}
	else
	{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
	}
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{
	ListItem<T> *temp=new ListItem<T>(toInsert);
	ListItem<T> *start=head;
	bool t=false;
	while(start!=NULL)
	{
		if(start->value==afterWhat)
		{
			t=true;
			break;
		}
		else
		{
		start=start->next;
		}
	}
	if(t==true)
	{	
		if(start->next==NULL)
		{
			start->next=temp;
			temp->prev=start;
			tail=temp;
		}
		else
		{
			ListItem<T> *stn=start->next;
			start->next=temp;
			temp->prev=start;
			temp->next=stn;
			stn->prev=temp;

		}
	}

}


template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
	return head;

}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{
	return tail;
}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
	ListItem<T> *start=head;
	bool t=false;
	while(start!=NULL)
	{
		if(start->value==item)
		{
			t=true;
			break;
		}
		else
		{
		start=start->next;
		}
	}
	if(t==true)
	{
		return start;
	}
	else
	{
		return NULL;
	}


}

template <class T>
void LinkedList<T>::deleteElement(T item)
{
	ListItem<T> *start=head;
	bool t=false;
	while(start!=NULL)
	{
		if(start->value==item)
		{
			t=true;
			break;
		}
		else
		{
		start=start->next;
		}
	}
	if(t==true)
	{
		if(start->prev==NULL && start->next==NULL)
		{
			delete start;
			head=NULL;
			tail=NULL;
		}
		else if(start==head)
		{
			ListItem<T> *temp=start;
			start=start->next;
			start->prev=NULL;
			head=start;
			delete temp;
		}
		else if(start==tail)
		{
			ListItem<T> *temp=start;
			start=start->prev;
			start->next=NULL;
			tail=start;
			delete temp;
		}
		else
		{
			ListItem<T> *temp=start;
			start->next->prev=start->prev;
			start->prev->next=start->next;
			delete temp;

		}
	}

}

template <class T>
void LinkedList<T>::deleteHead()
{
	if(head->next==NULL)
	{
		delete head;
		head=NULL;
		tail=NULL;
	}
	else
	{
		ListItem<T> *temp=head;
		head=head->next;
		head->prev=NULL;
		delete temp;
	}
}

template <class T>
void LinkedList<T>::deleteTail()
{
	if(tail->prev==NULL)
	{
		delete tail;
		head=NULL;
		tail=NULL;
	}
	else
	{
		ListItem<T> *temp=tail;
		tail=tail->prev;
		tail->next=NULL;
		delete temp;
	}
}

template <class T>
int LinkedList<T>::length()
{
	int counter=0;
	ListItem<T> *start=head;
	while(start!=NULL)
	{
		start=start->next;
		counter++;
	}
	return counter;

}

#endif
