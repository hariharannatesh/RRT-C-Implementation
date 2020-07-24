#include<map>
#include<vector>
#include<utility>
#include "graphclass.h"
using namespace std;

int graphclass::nearest(graphclass g[],int len,pair<double,double> newnode)
{
	map<int,double> d;
	for(int i=0;i<=len;i++)
	{
		if(g[i].obstacle_flag==0)
		{
			double dist=distance(g[i].node,newnode);
			d[i]=dist;
		}

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