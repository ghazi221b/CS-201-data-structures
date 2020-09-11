#ifndef VCS_CPP
#define VCS_CPP
#include "VCS.h"
#include <string>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
//chose stack as it allows us to easily undo and redo
//the complexity is order of 1 too since we only need to move the top of the stack to undo and redo
//this advanatge is lost when we use queue.
//base constructor, init
VCS::VCS(string fname)
{	
	filename=fname;
	curr_size=0;
}

//destructor
VCS::~VCS()
{
	VCS_node a;
	string ae;
	while(container2.isEmpty()==false)
	{
		ae=redo();
	}
	while(container1.isEmpty()==false)
	{
		a=container1.pop();
	}
}


//time to commit
void VCS::commit(string msg)
{
	string data;
	ifstream infile;
	string nam=filename+".txt"; 
    infile.open(nam.c_str());  
    getline(infile,data);
    infile.close();
    VCS_node a;
    a.message=msg;
    a.time_stamp=curr_size;
    container1.push(a);
    ofstream outfile;
	string s;
	stringstream ss;
	ss << curr_size;
	s = ss.str();
    nam=filename+s+".txt";
    outfile.open(nam.c_str());
   	outfile << data;
   	outfile.close();
   	curr_size++;


}

//print status of every version
void VCS::status()
{	
	VCS_node a;
	string ae;
	while(container2.isEmpty()==false)
	{
		ae=redo();
	}
	while(container1.isEmpty()==false)
	{
		a=container1.top();
		cout<<a.message<<a.time_stamp<<endl;
		ae=undo();
	}
}

//goes one step back
string VCS::undo()
{
	string data;
	VCS_node b=container1.pop();
	container2.push(b);
	VCS_node a=container1.top();
	int size=a.time_stamp;
	string s;
	stringstream ss;
	ss << size;
	s = ss.str();
	ifstream infile;
	ofstream outfile;
	string nam=filename+s+".txt"; 
	string nam2=filename+".txt";
    outfile.open(nam2.c_str());
    infile.open(nam.c_str());
    string ae;
    while(getline(infile,data))
    {	
    outfile<<data;
    ae=data;
	}
    infile.close();
    outfile.close();
    return ae;

	
}

//one step ahead
string VCS::redo()
{
	string data;
	VCS_node b=container2.pop();
	container1.push(b);
	int size=b.time_stamp;
	string s;
	stringstream ss;
	ss << size;
	s = ss.str();
	ifstream infile;
	ofstream outfile;
	string nam=filename+s+".txt"; 
	string nam2=filename+".txt";
    outfile.open(nam2.c_str());
    infile.open(nam.c_str());
    string ae;
    while(getline(infile,data))
    {	
    outfile<<data;
    ae=data;
	}
    infile.close();
    outfile.close();
    return ae;
	
}

//goes t_stamp step back or ahead
string VCS::revert(int t_stamp)
{
	string bn;
	VCS_node b;
	string data;
	while(container2.isEmpty()==false)
	{
		bn=redo();
	}
	VCS_node a=container1.top();
	if(a.time_stamp==t_stamp)
	{
	int size=a.time_stamp;
	string s;
	stringstream ss;
	ss << size;
	s = ss.str();
	ifstream infile;
	ofstream outfile;
	string nam=filename+s+".txt"; 
	string nam2=filename+".txt";
    outfile.open(nam2.c_str());
    infile.open(nam.c_str());
    string ae;
    while(getline(infile,data))
    {	
    outfile<<data;
    ae=data;
	}
    infile.close();
    outfile.close();
    return ae;
	}
	else if(a.time_stamp>t_stamp)
	{
		while(container1.isEmpty()==false)
		{
			string ae=undo();
			b=container1.top();
			if(t_stamp==b.time_stamp)
			{
				break;
			}
		}
	int size=b.time_stamp;
	string s;
	stringstream ss;
	ss << size;
	s = ss.str();
	ifstream infile;
	ofstream outfile;
	string nam=filename+s+".txt"; 
	string nam2=filename+".txt";
    outfile.open(nam2.c_str());
    infile.open(nam.c_str());
    string ae;
    while(getline(infile,data))
    {	
    outfile<<data;
    ae=data;
	}
    infile.close();
    outfile.close();
    return ae;

	}

}

#endif