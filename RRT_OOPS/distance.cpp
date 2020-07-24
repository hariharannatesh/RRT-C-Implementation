#include<iostream>
#include<utility>
#include<vector>
#include<cmath>
#include "graphclass.h"

double graphclass::distance(pair <double,double> node,pair<double,double> node2)
{
	double dist;
	dist=sqrt((pow((node.first-node2.first),2))+(pow((node.second-node2.second),2)));
	return dist;
}