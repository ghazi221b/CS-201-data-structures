#ifndef __HEAP_CPP
#define __HEAP_CPP
#include "heap.h"


MinHeap::MinHeap(int cap)
{
	harr=new int[cap];
	capacity=cap;
	heap_size=0;
}

void MinHeap::MinHeapify(int i)
{	
	int s=i;
	while(i<=heap_size)
	{	

		if(left(i)<heap_size && harr[left(i)]<harr[i])
		{
			s=left(i);
		}
		if(right(i)<heap_size && harr[right(i)]<harr[s])
		{
			s=right(i);
		}
		if(s!=i)
		{	
		int a=harr[s];
		harr[s]=harr[i];
		harr[i]=a;
		i=s;
		}
		else
		{
			return;
		}

	}
}
 
int MinHeap::parent(int i)
{
	return (i-1)/2;
}
 
int MinHeap::left(int i)
{
	return 2*i+1;
}
 
int MinHeap::right(int i)
{
	return 2*i+2;
}
 
int MinHeap::extractMin()
{
	if(heap_size<=0)
	{
		return 0;
	}
	else if(heap_size==1)
	{
		heap_size--;
		return harr[0];
		
	}
	else
	{
		int a = harr[0]; 
    	harr[0] = harr[heap_size-1]; 
    	heap_size--; 
    	MinHeapify(0); 
  		
    	return a; 

	}
	return 0;

}
 
void MinHeap::decreaseKey(int i, int new_val)
{
	harr[i] = new_val; 
	while(i!=0)
		{
			
			if(harr[parent(i)]>harr[i])
			{
				int a=harr[parent(i)];
				harr[parent(i)]=harr[i];
				harr[i]=a;
				i=parent(i);
			}
			else
				{
					break;
				}	
			

		}
  

}
 
int MinHeap::getMin()
{
	return harr[0];
}
 
void MinHeap::deleteKey(int i)
{	
	if(i>=heap_size)
	{
		return;
	}
	decreaseKey(i, -100000); 
    extractMin(); 

}
 
void MinHeap::insertKey(int k)
{	
	if(heap_size<capacity)
	{
		harr[heap_size]=k;
		int i=heap_size;
		heap_size++;
		while(i!=0)
		{
			
			if(harr[parent(i)]>harr[i])
			{
				int a=harr[parent(i)];
				harr[parent(i)]=harr[i];
				harr[i]=a;
				i=parent(i);
			}
			else
			{
				break;
			}	
			

		}
  	}
  	else
  	{
  		cout<<"filled"<<endl;
  	}

}

int* MinHeap::getHeap()
{
	return harr;
}

#endif