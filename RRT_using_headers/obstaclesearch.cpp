#include<vector>
#include<utility>
#include<cmath>
#include "obstaclesearch.h"
using namespace std;
int obstaclesearch(vector<pair<double,double> >obstacles, pair<double,double> newnode,double epsilon=0.0001) //search if there is an obstacle
{
	for(int i=0;i<obstacles.size();i++)
	{
		if(((fabs(obstacles[i].first-newnode.first)<epsilon))&&(fabs(obstacles[i].second-newnode.second)<epsilon))
			return 1;
	}
	return 0;
}
