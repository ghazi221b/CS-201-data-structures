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
	
	for (int i = 0 ; i < tableSize ; i++)
      {
            delete hashTable[i] ;
      }
    hashTable = NULL;

}

unsigned long HashL :: hash(string value){
	  return madCompression(bitHash(value),tableSize);
}

void HashL::resizeTable(){
	 int x=tableSize;
	tableSize=tableSize*7;
	block**hashTable1=new block*[tableSize];
	for(int i=0;i<tableSize;i++)
	{
    	hashTable1[i]=NULL;
	}
	block**keep=hashTable;

	for(int i=0;i<x;i++)
	{
    if(hashTable[i]!=NULL)
    {

     int index=hash(hashTable[i]->value);
     int o=0;
    while(hashTable1[index]!=NULL)
    {	o++;
        //index=(index+1)%(tableSize);
		index=(index+o*o)%tableSize;
	}

		hashTable1[index]=new block(index,hashTable[i]->value);

    }

}

	hashTable=hashTable1;
	delete keep;
	keep=NULL;
}

void HashL::insert(string value){
	
  unsigned long index=hash(value);
  int x=0;
	if(hashTable[index]!=NULL)
	{
		while(hashTable[index]!=NULL)
		{
			//index =(index+1)%tableSize;
			x++;
			index=(index+x*x)%tableSize;
		}

		hashTable[index]=new block(index,value);
		count++;

	}
	else
	{
		hashTable[index]=new block(index,value);
		count++;
	}
	if(count*1.0/tableSize>=0.4)
	{
		resizeTable();
	}

}

void HashL::deleteWord(string value){

	 block*temp=lookup(value);
   if(temp!=NULL)
   {
       hashTable[temp->key]=NULL;
       delete temp;
   }
}
block* HashL::lookup(string value){
unsigned long index=hash(value);
	int x=0;
	if(hashTable[index]==NULL)
	{
		return hashTable[index];
	}
	else
	{
		while(hashTable[index]->value!=value)
		{
			//index=(index+1)%tableSize;
			x++;
			index=(index+x*x)%tableSize;
			if(hashTable[index]==NULL)
			{
				return NULL;
			}

		}
		return hashTable[index];

	}
}
#endif
