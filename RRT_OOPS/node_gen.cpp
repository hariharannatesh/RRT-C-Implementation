#include<iostream>
#include<utility>
#include<vector>
#include<stdlib.h>
#include<cmath>
#include "graphclass.h"
using namespace std;

int graphclass::node_gen(graphclass g[],int i,pair<double,double> start, pair<double,double> goal,vector<pair<double,double> >obstacles)
{
	srand(i);
	pair<double,double> newnode;
	int signx,signy;
	signx=(goal.first-start.first)>=0?1:-1;
	signy=(goal.second-start.second)>=0?1:-1;
	newnode.first=signx*fmod(rand(),(goal.first-start.first)+double(1));
	newnode.second=signy*fmod(rand(),(goal.second-start.second)+double(1));
	//cout<<"Random node"<<newnode.first<<" "<<newnode.second<<endl;

	int pos=graphclass::nearest(g,(i-1),newnode);

	double theta;
	double slope;
	if(newnode.first==g[pos].node.first)
	{
		theta=asin(1.0);

	}
	else
	{
		slope=(newnode.second-g[pos].node.second)/(newnode.first-g[pos].node.first);
		theta=atan(slope);

	}

	double step=graphclass::distance(start,goal)/10.0;

	//cout<<"Step :"<<step<<endl;

	node.first=g[pos].node.first+signx*fabs(cos(theta))*(step);
	node.second=g[pos].node.second+signy*fabs(sin(theta))*(step);
	//cout<<node.first<<" "<<node.second<<endl;

	graphclass::obstaclesearch(obstacles,node);

	return pos;

}