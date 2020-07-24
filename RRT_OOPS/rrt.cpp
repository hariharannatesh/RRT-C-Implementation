#include "graphclass.h"
#include<vector>
#include<utility>
#include<iostream>
#include "addedge.h"
using namespace std;

int rrt(graphclass g[],pair<double,double> start,pair<double,double> goal,vector<pair<double,double> > obstacles,int iterations,int radius)
{
	for(int i=1;i<iterations;i++)
	{
		int pos=g[i].node_gen(g,i,start,goal,obstacles);
		//cout<<i<<": node"<<g[i].node.first<<g[i].node.second<<endl;

		if(g[i].obstacle_flag==1)
		{
			cout<<"Obstacle found"<<endl;
			continue;
		}

		addedge(g,pos,i);

		if(g[i].distance(g[i].node,goal)<radius)
		{
			cout<<"Path Found"<<endl;
			return i;
		}


	}

	return 0;
}