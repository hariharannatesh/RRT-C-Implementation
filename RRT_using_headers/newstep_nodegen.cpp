#include<utility>
#include<cmath>
#include "newstep_nodegen.h"
using namespace std;
pair<double,double> newstep_nodegen(pair<double,double> node,pair<double,double> start,double step,pair<double,double> goal) //generating new node along the direction of randomly generated node
{
	double theta;
	double slope;
	if(node.first==start.first)
	{
		theta=asin(1.0);

	}
	else
	{
		slope=(node.second-start.second)/(node.first-start.first);
		theta=atan(slope);

	}
	pair<double,double> newnode;
	int signx,signy;// to indicate in which direction the node should be generated.
	signx=(goal.first-start.first)>=0?1:-1;
	signy=(goal.second-start.second)>=0?1:-1;
	newnode.first=start.first+signx*fabs(cos(theta))*(step);
	newnode.second=start.second+signy*fabs(sin(theta))*(step);
	//cout<<newnode.first<<" "<<newnode.second<<endl;

	return newnode;

}