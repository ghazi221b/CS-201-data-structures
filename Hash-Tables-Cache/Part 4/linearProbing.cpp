#ifndef LINEARPROBING_CPP
#define LINEARPROBING_CPP

#include "linearProbing.h"
#include "hashfunctions.cpp"


HashL::HashL(){
     tableSize = 1000; // you cant change this
    hashTable= new block*[tableSize];
    for(long i=0;i<tableSize;i++)
    {
    	hashTable[i]=NULL;
    }
    count=0;

}

HashL::~HashL(){
    

}

unsigned long HashL :: hash(string value){
	  return madCompression(bitHash(value),tableSize);
}

void HashL::min()
{
	int b;
	for(int i=0;i<tableSize;i++)
	{
		if(hashTable[i]!=NULL)
		{
			int a=hashTable[i]->usage;
			for(int j=i;j<tableSize;j++)
			{
				
				if(hashTable[j]!=NULL)
				{
					if(a==0)
					{
						b=j;
						break;
					}
					if(a>hashTable[j]->usage)
					{
						a=hashTable[j]->usage;
						b=j;
					}
				}
			}
			break;
		}
	}
	delete hashTable[b];
	hashTable[b]=NULL;
	
	count--;
}


void HashL::insert(string value,int num,string n){
	
	if(count==tableSize)
	{	
		min();
	}
  unsigned long index=hash(n);
	if(hashTable[index]!=NULL)
	{
		while(hashTable[index]!=NULL)
		{
			index++;
			index %=tableSize;
		}

		hashTable[index]=new block(index,value,num,0);
		count++;

	}
	else
	{
		hashTable[index]=new block(index,value,num,0);
		count++;
	}
	
	

}



block* HashL::lookup(string value,int n){
unsigned long index=hash(value);
	if(hashTable[index]==NULL)
	{
		return hashTable[index];
	}
	else
	{
		int a=index;
		while(hashTable[index]->secret!=n )
		{
			index++;
			index=index%tableSize;
			if(a==index)
			{
				return NULL;
			}
			if(hashTable[index]==NULL)
			{
				return NULL;
			}

		}
		return hashTable[index];

	}
}
#endif
