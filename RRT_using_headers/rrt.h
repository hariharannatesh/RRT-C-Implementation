#include<utility>
#include<map>
using namespace std;
#ifndef RRT_H_INCLUDED
#define RRT_H_INCLUDED
int rrt(map<int,pair<double,double> > &graph,int radius,vector<pair<double,double> > obstacles,pair<double,double> start, pair<double,double> goal,int iter,vector<int> adj[]);

#endif