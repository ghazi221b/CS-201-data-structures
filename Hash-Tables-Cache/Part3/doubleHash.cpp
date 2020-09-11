#ifndef DOUBLEHASH_CPP
#define DOUBLEHASH_CPP
#include "doubleHash.h"
#include "hashfunctions.cpp"
HashD::HashD(){
    tableSize = 10000; // you cant change this
    count = 0;
    hashTable = new block*[tableSize];
    for (long i = 0; i < tableSize; i++){
        hashTable[i] = NULL;
    }
    count=0;
}

HashD::~HashD(){

for (int i = 0 ; i < tableSize ; i++)
      {
            delete hashTable[i] ;
      }
    hashTable = NULL;

}
unsigned long HashD :: hash1(string value){
	return madCompression(bitHash(value), tableSize);
}
unsigned long HashD :: hash2(string value){
	return 23-madCompression(bitHash(value), 23);
}


void HashD::resizeTable(){

	int z=tableSize;
	tableSize=tableSize*7;
	block**hashTable1=new block*[tableSize];
	int counter,index,y=0;
	for(int i=0;i<tableSize;i++)
	{
    	hashTable1[i]=NULL;
	}
	

	for(int i=0;i<z;i++)
	{
    if(hashTable[i]!=NULL)
    {
     counter=0;
     index=hash1(hashTable[i]->value);
     y=hash2(hashTable[i]->value);
     
  
    while(hashTable1[index]!=NULL)
    {	
    	counter++;
        index=(index+counter*y)%(tableSize);
	}

		hashTable1[index]=new block(index,hashTable[i]->value);
	
	
    }

}
	block**keep=hashTable;
	hashTable=hashTable1;
	delete keep;
	keep=NULL;

}

void HashD::insert(string value){
	int counter = 0;
    unsigned long index = hash1(value);
	unsigned long y = hash2(value);
	if(hashTable[index]!=NULL)
	{
	while(hashTable[index]!=NULL)
	{
		counter++;
		index=(index+counter*y)%tableSize;
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

void HashD::deleteWord(string value){
	block* place=lookup(value);
	
	if(place!=NULL)
	{
		

		hashTable[place->key]=NULL;
		delete place;
		
	}
}

block* HashD::lookup(string value){
	unsigned long index=hash1(value);
	unsigned long y=hash2(value);
	int counter=0;
	if(hashTable[index]==NULL)
	{
		return hashTable[index];
	}
	else
	{
		while(hashTable[index]->value!=value)
		{
			counter++;
			index=(index+counter*y)%tableSize;
			if(hashTable[index]==NULL)
			{
				return NULL;
			}

		}
		return hashTable[index];

	}
	

}

#endif