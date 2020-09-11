#ifndef __TREE_CPP
#define __TREE_CPP
#include "tree.h"
#include <sstream>
#include <cmath>
#include <queue>


// try to make get_node() and get_file() after tree initialization


Tree::Tree(string data)
{
	TreeItem* new_node= new TreeItem();
	new_node->id = 1;
	new_node->latest_data=data;
	root=new_node;
	VCS_node home=VCS_node (data,0);
	new_node -> container.push_back(home);

	// write the rest of the code here
}

Tree::~Tree()
{
}


void Tree::branch(int id)
{
	TreeItem *temp=get_node(id);
	int counter=0;
	counter=temp->child.size();
	if(counter<9)
	{
		TreeItem* new_node= new TreeItem();
		counter++;
		new_node->id=id*10+counter;
		new_node->latest_data=temp->latest_data;
		VCS_node home=VCS_node (temp->latest_data,0);
		new_node ->container.push_back(home);
		temp->child.push_back(new_node);
	}
	else
		return;	
}

void Tree::merge(int src_id,int dst_id)
{
	TreeItem *temp=get_node(src_id);
	TreeItem *otemp=get_node(dst_id);
	if(otemp!=NULL && temp!=NULL)
	{	
	string d=otemp->latest_data+temp->latest_data;
	otemp->latest_data=d;
	
	int jj=otemp->container.size();
	vector<VCS_node>::iterator v;
	for( v=otemp->container.begin() ; v!=otemp->container.end() ; v++ )
	{
		if((*v).time_stamp==(jj-1))
		{
			(*v).data=d;
		}

	}
	merge_state ap;
	ap.src_id=src_id;
	ap.dst_id=dst_id;
	history.push_back(ap);
	}
	
}

void Tree::commit(int src_id,string new_data)
{ 
	TreeItem* km=get_node(src_id);
	string kk=km->latest_data+new_data;
	km->latest_data=kk;
	int a=km->container.size();
	VCS_node ap=VCS_node (kk,a);
	km->container.push_back(ap);
}

string Tree::get_file(int id, int t_stamp)
{
	TreeItem* km=get_node(id);
	if(km!=NULL)
	{
		vector<VCS_node>::iterator v;
		for( v=km->container.begin() ; v!=km->container.end() ; v++ )
		{
			if((*v).time_stamp==t_stamp)
			{
				return (*v).data;
			}

		}
		
	}
	else
		return "";
} 

TreeItem* Tree::get_node(int id)
{
	int a=id;
	int digits=0;
	while(a>0)
	{
		a=a/10;
		digits++;
	}
	TreeItem* ne= root;
	vector<TreeItem*>::iterator v;
	if(digits<2)
	{
		if(id==ne->id)
		{
			return ne;
		}
		else
		{
			return NULL;
		}
	}

	for(int i=2;i<=digits;i++)
	{
			for( v=ne->child.begin() ; v!=ne->child.end() ; v++ )
			{
				a=pow(10,digits-i);
				a=id/a;
				if(id==(*v)->id)
				{
					return *v; 
				}
				else if((*v)->id==a)
				{
					ne=*v;
					break;
				}
				
			}
	}
	return NULL;
} 

vector<merge_state> Tree::merge_history()
{
	return history;
}

void Tree::level_traversal() 
{ 
	
} 


#endif
