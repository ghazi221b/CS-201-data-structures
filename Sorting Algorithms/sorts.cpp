#ifndef __SORTS_CPP
#define __SORTS_CPP
#include "sorts.h"
#include "heap.cpp"
#include "list.h"
#include "list.cpp"
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
//=====================================================================================
vector<long> InsertionSort(vector<long> nums)
{	
	long aa[nums.size()];
	std::copy(nums.begin(), nums.end(), aa);
	 int km,j;
    for (int k = 1; k < nums.size(); k++) { 
        km = aa[k]; 
  		j=k;
        while (j > 0) { 
            if(aa[j-1]>km)
            {
            	aa[j]=aa[j-1];
            	j--;
            }
            else
            	{break;}
        } 
        aa[j] = km; 
    } 
    vector<long>hh;
    int nn=0;	
    for(int o=0;o<nums.size();o++)
    {
    	hh.push_back(aa[nn]);
    	nn++;
    }
    return hh;


}

//=====================================================================================
vector<long> MergeSort(vector<long> nums)
{
	
	int length = nums.size();
    List<long> obj_num;

    for (int i = 0; i < length; i++){
        obj_num.insertAtHead(nums[i]);
    }
    ListItem<long> *mm=obj_num.getHead();
    Merge1(&mm);
    for (int i = 0; i < length; i++){
        nums[i] = mm->value;
        mm = mm->next;
    }

    return nums;



}
void Merge1(ListItem <long>**head)
{
	

	ListItem<long>*first=*head;
	ListItem<long> *second=*head;
 
	if(first == NULL || first->next == NULL)
	{
		return;
	}
	else
	{
		while(first->next != NULL)
		{
			first = first->next;
			if(first->next != NULL)
			{
				second=second->next;
				first = first->next;
			}
		}
		
		second=second->next;
		second->prev->next=NULL;
		second->prev=NULL;
		first = *head;
	}
 
	Merge1(&first);
	Merge1(&second);
     
	*head = Merge2(first, second);

}
ListItem <long>* Merge2(ListItem<long> * f,ListItem<long> * s)
{	
	
	ListItem<long> *t;
	ListItem<long> *t2;
	
 
	if(f == NULL)
		return s;
	if(s == NULL)
		return f;
 
	t = s;
 
	
	while (f != NULL)
	{
		t2 = f;
		f = f->next;
		t2->next = NULL;

		if(s->value > t2->value)
		{
			t2->next = s;
			s->prev=t2;
			s = t2;
			t = s;
			continue;
		}
 		
		while(true)
		{
			if(t->next==NULL)
			{
			t->next = t2;
			t2->prev=t;
			t = t->next;
			break;	
			}
			if(((t->next)->value)<=t2->value)
			{
				t=t->next;
			}
			else
			{
				
				t->next->prev=t2;
				t2->next=t->next;
				t2->prev=t;
				t->next=t2;
				break;
			}
		}
		
	}
	return s;


};


//=====================================================================================
vector<long> QuickSortArray(vector<long> nums)
{
	long aa[nums.size()];
	long size=nums.size();
	std::copy(nums.begin(), nums.end(), aa);
	QA1(aa,0,size-1);
	vector<long>hh;
	 for(int o=0;o<nums.size();o++)
    {
    	hh.push_back(aa[o]);
    }
    return hh;
}

void QA1(long *arr,int a,int b)
{
		if(a<b)
		{
			long pa=QA2(arr,a,b);
			QA1(arr,a,pa-1);
			QA1(arr,pa+1,b);
		}
}
long QA2(long *arr, int a,int b)
{
	int c=b/2;
	int median=max(min(arr[a],arr[b]), min(max(arr[a],arr[b]),arr[c]));
	int gg;
	if(median==arr[a])
	{
		gg=a;
	}
	else if(median==arr[b])
	{
		gg=b;
	}
	else if(median==arr[c])
	{
		gg=c;
	}
	swap(arr[gg],arr[b]);
	int pivot=arr[b];
	int index=a;
	for(int i=a;i<b;i++)
	{
		if(arr[i]<=pivot)
		{
			swap(arr[i],arr[index]);
			index++;
		}
	}
	swap(arr[index],arr[b]);
	return index;
}
//=====================================================================================
vector<long> QuickSortList(vector<long> nums)
{
	int length = nums.size();
    List<long> obj_num;

    for (int i = 0; i < length; i++){
        obj_num.insertAtHead(nums[i]);
    }
    srand(time(0));
    ListItem<long> *mm=obj_num.getHead();
    ListItem<long> *tt=obj_num.getTail();
    QL1(mm,tt);
    for (int i = 0; i < length; i++){
        nums[i] = mm->value;
        mm = mm->next;
    }

    return nums;	
}
void QL1(ListItem<long>*head,ListItem<long> * tail)
{
	if(head!=NULL && tail!=NULL && tail->next!=head)
	{
		ListItem<long>*pa=QL2(head,tail);
		QL1(head,pa->prev);
		QL1(pa->next,tail);
	}
}
ListItem<long> *QL2(ListItem<long> *head, ListItem<long> *tail)
{
	
	 srand(time(NULL));
	ListItem<long>*ca=head;
	while(ca!=tail)
	{
		int a=rand()%2;
		ca=ca->next;
		if(a==1)
		{
			break;
		}
	}
	int f=ca->value;
	ca->value=tail->value;
	tail->value=f;
	int x = tail->value;  
  
    
    ListItem<long>*i=head;
  
    
    for (ListItem<long> *j = head; j != tail; j = j->next)  
    {  
        if (j->value <= x)  
        {  
            
  			
            int b=i->value;
            i->value=j->value;
            j->value=b; 
            i=i->next;
        }  
    }  
   
    int b=i->value;
    i->value=tail->value;
    tail->value=b;  
    return i; 
   
   

}

//=====================================================================================
vector<long> HeapSort(vector<long> nums)
{
	MinHeap po(nums.size());
	long aa[nums.size()];
	long size=nums.size();
	std::copy(nums.begin(), nums.end(), aa);
	for(int i=0;i<nums.size();i++)
	{
		po.insertKey(aa[i]);
	}
	vector<long>hh;
	for(int i=0;i<nums.size();i++)
	{
		
    	hh.push_back(po.extractMin());
	}
	return hh;



}

//=====================================================================================
vector<long> QueenOfAllSorts(vector<long> nums)
{
	long aa[nums.size()];
	long length=nums.size();
	std::copy(nums.begin(), nums.end(), aa);
	pair<int,int>*temp;
	pair<int,int> *arr=new pair<int,int>[nums.size()];
	for(int i=0;i<nums.size();i++)
	{
		if(aa[i]<length)
		{
			if(aa[i]<0)
			{
				arr[(aa[i]*(-1))].second++;
			}
			else if(aa[i]>=0)
			{
				arr[aa[i]].first++;
			}

		}
		else
		{
			
			pair<int,int> *arr2=new pair<int,int>[aa[i]*2];
			
			for(int j=0;j<length;j++)
			{
				arr2[j]=arr[j];
			}
			length=aa[i]*2;
			temp=arr;
			arr=arr2;
			delete [] temp;
			i--;
		}

	}
	vector<long>hh;
	for(int i=length-1;i>=0;i--)
	{
		int count=0;
		while(count<arr[i].second)
		{
			hh.push_back(i*-1);
			count++;
		}
	}
	for(int i=0;i<length-1;i++)
	{
		int count=0;
		while(count<arr[i].first)
		{
			hh.push_back(i);
			count++;
		}
	}
	return hh;


}
#endif
//this is not linear time but order of n^2 if n elements are inserted in O(n) then they will all have to be
//sorted in the worst case and that will give us O(n^2).
//we double the size since this will have to be done a few times and gives us the ability to simultaneously handle 
//a greater amount of negative integers too, so at the expense of space this will give us efficiency.