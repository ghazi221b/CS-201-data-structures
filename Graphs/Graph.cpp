#ifndef GRAPH__CPP
#define GRAPH__CPP
#include "Graph.h"
#include <fstream>
#include <string>
#include <iostream>
#include <queue>
#include <functional>

struct node1
{
    vector<edge> nod;
};
Graph::Graph(string file, bool isUnitLength)
{
	ifstream f;
	string n1,n2;
	node *l,*a,*b;
	edge *p;
	int num;
	bool m=true;
	string s=file+".txt";
	f.open(s.c_str());
	while(!f.eof())
	{
		f>>n1;

		if(n1=="PEOPLE")
		{
			
			continue;
		}
		if(n1=="CONNECTIONS")
		{
			
			m=false;
			continue;
		}
		if(m==false)
		{
			
			f>>n2>>num;
			for(int i=0;i<cities.size();i++)
			{
				if(cities[i]->name==n1)
				{
					a=cities[i];
					break;
				}

			}
			for(int i=0;i<cities.size();i++)
			{
				if(cities[i]->name==n2)
				{
					b=cities[i];
					break;
				}

			}
			
			p=new edge;
			p->Origin=a;
			p->Dest=b;
			if(isUnitLength==false)
			{
				p->weight=num;
			}
			else
			{
				p->weight=1;
			}
			a->edges.push_back(*p);
			p=new edge;
			p->Origin=b;
			p->Dest=a;
			p->weight=num;
			b->edges.push_back(*p);
			arcs.push_back(*p);
			

		}
		if(m==true)
		{
			
			l=new node;
			l->visit=0;
			l->name=n1;
			cities.push_back(l);
		}

	}
	
	
}

void Graph::display(node* temp)
{
	if(temp->visit)
		return;
	
	cout << "Person: " << temp->name;
	temp->visit = 1;

	for(int i=0; i< temp->edges.size(); i++)
	{
		if(!temp->edges[i].Origin->visit || !temp->edges[i].Dest->visit)
		{
		cout << "->" << temp->edges[i].weight << endl;
		display(temp->edges[i].Origin);
		display(temp->edges[i].Dest);
	}
	}
}
void Graph::visit()
{
	for(int i=0;i<cities.size();i++)
	{
		cities[i]->visit=0;
	}
}

bool Graph::Reachable(string start, string dest)
{
	
	node*a=NULL;
	node*b=NULL;
    for(int i=0;i<cities.size();i++)
    {
    	if(cities[i]->name==start)
    	{
    		a=cities[i];
    	}
    	if(cities[i]->name==dest)
    	{
    		b=cities[i];
    	}
	}
	if(a==NULL || b==NULL)
	{
		cout<<"name not found"<<endl;
		return false;
	}

	if(start==dest)
	{
		return true;
	}
    

   	if(a->visit>1)
    {	
   		return false;
    }

    a->visit++;
    int count=0;
    for(int i=0;i<a->edges.size();i++)
    {
        b=a->edges[i].Dest;

        if(Reachable(b->name,dest))
            {
            	count++;
            	break;
            }
	}
	if(count>=1)
	{
		return true;
	}
	else 
	{	
		return false;
	}    



}

v

vector<string> Graph::Dijkstra(string start, string dest, float &d)
{
	node *a;
	node*b;
	int kill=100000;
	typedef pair<int,node*> ham;
	priority_queue< ham, vector <ham> , greater<ham> > pq; 
	//vector<lop> pq;
	if(Reachable(start,dest))
	{
		vector<string> dup;
		for(int i=0;i<cities.size();i++)
		{
			cities[i]->visit=0;
			cities[i]->len=1000000;
		}
		
		for(int i=0;i<cities.size();i++)
		{
			if(start==cities[i]->name)
			{
				a=cities[i];
			}
		}
		pq.push(make_pair(0,a));
		while(!pq.empty())
		{
			int cl;
			node *b=pq.top().second;
			
			int inital=pq.top().first;
			
			b->visit=1;
			dup.push_back(b->name);
			if(b->name==dest)
			{
				
				d=b->len;
				return dup;
				
			}
			
			
			pq.pop();
			for(int i=0;i<b->edges.size();i++)
			{
			
				node *mm=b->edges[i].Dest;
				
				int w=b->edges[i].weight;
				
				if(mm->len>(w+inital))
				{
					mm->len=w+inital;

					b->edges[i].Dest->visit=1;
				pq.push(make_pair(mm->len,mm));
				}
				if(mm->name==dest)
				{
					dup.push_back(dest);
					
					
						d=mm->len;
						return dup;
					
				}
				
			}
		}

		


	}

}

int main()
{
	string name="friends";
	string name1;
	bool km;
	int tf;
	cout<<"checking Reachable-ity"<<endl;
	Graph a(name,true);
	string a1="Mannan";
	string a2="Ali";
	string a3="Trump";

	km=a.Reachable(a1,a2);
	if(km==true)
	{
		cout<<"Mannan and Ali reachable"<<endl;

	}
	else
		cout<<"not reachable"<<endl;
	a.visit();
	km=a.Reachable(a1,a3);
	if(km==true)
	{
		cout<<"Mannan and Trump reachable"<<endl;

	}
	else
		cout<<"not reachable"<<endl;
	a.visit();
	km=a.Reachable(a2,a3);
	if(km==true)
	{
		cout<<"Trump and Ali reachable"<<endl;

	}
	else
		cout<<"not reachable"<<endl;
	
	cout<<"testing unit length distances"<<endl;
	float len;
	int c=0;
	km=1;
	cout<<"between Trump and Ali"<<endl;
	vector<string>hmm=a.Dijkstra(a3,a2,len);
	cout<<"distance is "<<hmm.size()-1<<endl;
	cout<<"between Trump and Mannan"<<endl;
	vector<string>bmm=a.Dijkstra(a3,a1,len);
	int j=bmm.size()-1;
	cout<<"distance is "<<j-1<<endl;
	cout<<"testing friendship"<<endl;
	cout<<"between Trump and Mannan"<<endl;
	km=false;
	Graph b(name,false);
	vector<string>dmm=b.Dijkstra(a3,a1,len);
	cout<<"friendship is "<<len<<endl;
	cout<<"betweenTrump and ALi"<<endl;
	vector<string>lmm=b.Dijkstra(a3,a2,len);
	cout<<"friendship is "<<len-1<<endl;

	



  
}

#endif
