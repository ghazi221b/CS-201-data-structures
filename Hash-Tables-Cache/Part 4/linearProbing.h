#include "linearProbing.cpp"
#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include <string>
#include <iostream>

using namespace std;
class block{
    public:
        unsigned long key;
        string value;
        int usage;
        int secret;
        block(unsigned long _key,string _value,int _secret,int _usage){
            this->key = _key;
            this->value = _value;
            this->secret=_secret;
            this->usage=_usage;
        }
};


class HashL{
    private:
        block** hashTable;
        long tableSize;
        unsigned long hash(string value); // return the corresponding key of the value
        long count; // keeps a count of the number of entries in the table.
        //void resizeTable();
    public:
        HashL();
        ~HashL();
        void min();
        void insert(string value,int num,string n);
		block* lookup(string value,int n);
};

#endif