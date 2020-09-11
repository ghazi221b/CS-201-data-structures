#ifndef __DICTIONARY_CPP
#define __DICTIONARY_CPP
#include "dictionary.h"
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <chrono>

Dictionary::Dictionary() {
	wordsTree = NULL; 
}

Dictionary::~Dictionary(){
	delete wordsTree;
    wordsTree = NULL;    
}

void Dictionary::initialize(string wordsFile) {
	string ll; 
	int check=0;
	wordsTree = new BST<string>;
   
   ifstream infile((wordsFile + ".txt").c_str());
    

   while(true)
   {
   		if(infile >> ll);
   		{
   		insertWord(ll);
   		check++;
   		cout<<check<<endl;
   		if(check==12000)
   		{
   			break;
   		}
   		}
   		
   		
   } 
   cout<<"counter is "<<check<<endl;;
   infile.close();

}

bool Dictionary::deleteWord(string word) {
	if(wordsTree==NULL)
		return false;
	
	if(wordsTree->search(word)!=NULL)
	{
		wordsTree->delete_node(word);
		return true;
	}

	return false;
}
bool Dictionary::editWord(string oldWord, string newWord) {
	if(wordsTree==NULL)
	{
		return false;
	}
	else
	{
		if(wordsTree->search(oldWord)!=NULL)
		{
			wordsTree->delete_node(oldWord);
			wordsTree->insert(newWord,newWord);
			return true;
		}
		else
		{
			return false;
		}

	}

	return false;
}
bool Dictionary::insertWord(string word) {
	if(wordsTree==NULL)
	{
		return false;
	}
	else
	{
		wordsTree->insert(word,word);
		return true;
	}
	return false;
}
node<string>* Dictionary::findWord(string word) {
	
    clock_t t;
    t = clock();
    // TODO your code here
    auto start = std::chrono::steady_clock::now();
    node<string> *a= wordsTree->search(word);

    auto end = std::chrono::steady_clock::now();
    auto total_time = std::chrono::duration_cast<chrono::microseconds>(end - start).count();

    t = clock() - t;
    if (a){
        double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
        cout << "findWord() took " << total_time << " µs to search for " << word << endl;
        return a;
    }
    else {
        return NULL; // TODO
    }
}

#endif

int main() {
	Dictionary k;
	k.initialize("words");
	string p;
	bool mm;
	int a=99;
	
	while(true)
	{
		cout<<"press 1 to enter words, 2 to delete words,3 to search words,4 to edit words, 5 to exit"<<endl;
		cin>>a;

		if(a==1)
		{
			cout<<"tell word"<<endl;
			cin>>p;
			mm=k.insertWord(p);
			if(mm==true)
			{
				cout<<"word good to go"<<endl;
			}
			else
			{
				cout<<"sad life"<<endl;
			}

		}
		else if(a==2)
		{
			cout<<"tell word"<<endl;
			cin>>p;
			mm=k.deleteWord(p);
			if(mm==true)
			{
				cout<<"word good to go"<<endl;
			}
			else
			{
				cout<<"sad life"<<endl;
			}

		}
		else if(a==3)
		{
			cout<<"tell word"<<endl;
			cin>>p;
			node<string> *df=k.findWord(p);
			if(df==NULL)
			{
				cout<<"nope"<<endl;
			}
			else
			{
				cout<<"yip"<<endl;
			}

		}
		else if(a==4)
		{
			string pp;
			cout<<"old word"<<endl;
			cin>>p;
			cout<<"new word"<<endl;
			cin>>pp;
			mm=k.editWord(p,pp);
			if(mm==true)
			{
				cout<<"goodjb"<<endl;
			}
			else
			{
				cout<<"nope"<<endl;
			}
		}
		else if(a==5)
		{
			break;
		}
	}
	return 0;
}
