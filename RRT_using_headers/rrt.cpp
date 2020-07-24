#include<utility>
#include<map>
#include "distance.h"
#include "add_edge.h"
#include "node_gen.h"
#include "newstep_nodegen.h"
#include "present.h"
#include "nearest.h"
#include "obstaclesearch.h"
using namespace std;
#include<iostream>
int rrt(map<int,pair<double,double> > &graph,int radius,vector<pair<double,double> > obstacles,pair<double,double> start, pair<double,double> goal,int iter,vector<int> adj[])
{
	double step=distance(start,goal)/10.0;//step size is dependent on the distance between start and end node
	for(int i=1;i<=iter-1;i++)
	{
		pair<double,double> node=node_gen(i,start,goal);//Random node generation
		int nnode=nearest(graph,node);// Find the index of the node that is closest to the randomly generated node.
		pair<double,double> newnode=newstep_nodegen(node,graph[nnode],step,goal); //Generating new node along the direction of the random node.
		int it=obstaclesearch(obstacles,newnode,0.0001);
		if(it)
		{
			cout<<"Obstacle found"<<endl;
			continue;
		}
		graph[i]=newnode;

		add_edge(adj,nnode,i);

		if(present(newnode,goal,radius))
		{
			//cout<<"Path Found"<<endl;
			return i;
		}

	}

	return 0;
}