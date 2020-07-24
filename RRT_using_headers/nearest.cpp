#include<map>
#include<utility>
#include "distance.h"
#include "nearest.h"
using namespace std;
int nearest(map<int,pair<double,double> >graph,pair<double,double> newnode) //Function to find the nearest node present to the random node
{
	map<int,double> d;
	for(auto i=graph.begin();i!=graph.end();i++)
	{
		double dist=distance(i->second,newnode);
		d[i->first]=dist;
	}

	double min_d=100000.0;
	int pos;
	for(auto it=d.begin();it!=d.end();it++)
	{
		if(it->second<min_d)
		{
			min_d=it->second;
			pos=it->first;
		}

	}

	
	return pos;

}