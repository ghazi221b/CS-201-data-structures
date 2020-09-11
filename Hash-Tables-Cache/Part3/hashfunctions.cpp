#ifndef HASHFUNCTIONS_CPP
#define HASHFUNCTIONS_CPP
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
// this takes in a string and returns a 64bit hash.
unsigned long polyHash(std::string value,int a){

	unsigned long hash=0;
	for(char ch:value)
	{
		hash=a*hash+ch;

	}
	return hash;
}

//does some bitwise operation and generates a 64bit hash.
unsigned long bitHash(std::string value){
	unsigned long bit=0;
	for(char ch:value)
	{
			bit^=(bit<<5)+(bit>>2)+ch;
	}
	return bit;

}
// Size is the size of array maintained by the hashtable.
unsigned long divCompression(unsigned long hash,long size){
	return (((hash))%size);
}
// multiplication addition and division compression. 
unsigned long madCompression(unsigned long hash,long size,int m = 1993,int a = 1637){
	//unsigned long size1=static_cast<unsigned long>(size);
	return(((a*hash+m))%size);
}
#endif
// you may write your own program to test these functions.