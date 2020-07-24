#include<iostream>
#include<utility>
#include<vector>
using namespace std;
#ifndef GRAPHCLASS_H_INCLUDED
#define GRAPHCLASS_H_INCLUDED

class graphclass
{
public:
	vector<int> adj;
	pair<double,double> node;
	int obstacle_flag;

	graphclass();

	double distance(pair<double,double> node,pair<double,double> node2);

	int nearest(graphclass g[],int len,pair<double,double> newnode);

	int node_gen(graphclass g[],int i,pair<double,double> start, pair<double,double> goal,vector<pair<double,double> >obstacles);

	int obstaclesearch(vector<pair<double,double> >obstacles, pair<double,double> newnode);

};

#endif