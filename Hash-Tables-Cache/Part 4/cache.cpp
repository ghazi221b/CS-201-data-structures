//include any header files as required
#include <iostream>
#include <fstream>
#include<sstream>
#include "linearProbing.h"
#include "hashfunctions.cpp"
#include <chrono>

using namespace std;

int main()
{
	int option=0;
	
	cout<<"press 1 to do cache and any other digit to not cache"<<endl;
	cin>>option;
	if(option!=1)
	{
		int file;
		ifstream files;
		ifstream filed;
		int snum,dnum;
		string word,comma,filename,s;
		cout<<"secret file number"<<endl;
		filename="secret";
		cin>>file;
		if(file<1||file>3)
		{
			return 0;
		}
		int c=0;
		stringstream ss;
		ss << file;
		s = ss.str();
		string fname=filename+s+".txt";
		files.open(fname.c_str());
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		int dan=0;
		while(!files.eof())
		{
			files>>snum;
			c++;
			filed.open("dictionary.txt");
			while(!filed.eof())
			{
				filed>>dnum>>word;
				/*if(snum==dnum)
				{
					cout<<snum<<" "<<word<<endl;
					break;
				}
				*/
				if(dan==snum)
				{
					cout<<snum<<" "<<word<<endl;
					dan=0;
					break;	

				}
				dan++;
			}
			filed.close();

			files>>comma;
			if(c==3000)
			{
				std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
  				std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() <<std::endl;
				return 0;
			}
		}
		files.close();

		

	}
	else
	{
		HashL dd;
		int file;
		int counter=0;
		ifstream files;
		ifstream filed;
		int snum,dnum;
		string word,comma,filename,s;
		cout<<"secret file number"<<endl;
		filename="secret";
		cin>>file;
		int c=0;
		if(file<1||file>3)
		{
			return 0;
		}
		stringstream ss;
		ss << file;
		s = ss.str();
		string fname=filename+s+".txt";
		files.open(fname.c_str());
		int dan=0;
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		while(!files.eof())
		{
			files>>snum;

			c++;
			stringstream bb;
			bb << snum;
			s = bb.str();
			//cout<<"gah"<<endl;
			block* a=dd.lookup(s,snum);
			//cout<<"bah"<<endl;
			//cout<<c<<endl;
			if(a==NULL)
			{	
				filed.open("dictionary.txt");
				while(!filed.eof())
				{
					filed>>dnum>>word;
					/*if(snum==dnum)
					{
						dd.insert(word,dnum,s);
						counter++;
						cout<<dnum<<" "<<word<<endl;
					}*/

					if(dan==snum)
					{
						dd.insert(word,dnum,s);
						cout<<dnum<<" "<<word<<endl;
						dan=0;
						break;

					}
					dan++;
				}
				filed.close();
				
				files>>comma;
				if(c==3000)
				{
					std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
  					std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() <<std::endl;
					return 0;
				}
			}
			else
			{
				cout<<a->value<<" "<<a->secret<<endl;
				a->usage+=1;
				files>>comma;
				if(c==3000)
				{
					std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();
  					std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds>(end - begin).count() <<std::endl;
					return 0;
				}
			}
		}
	}
}