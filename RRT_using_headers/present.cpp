#include<utility>
#include "distance.h"

bool present(pair<int,int> p1,pair<int,int> goal,int radius) //To check if the node is present within the radius of the goal.
{
	double dist;
	dist=distance(p1,goal);
	if(dist<radius)
		return true;
	else
		return false;

}