#include<utility>
#include<cmath>
#include "distance.h"
using namespace std;
double distance(pair<double,double> p1,pair<double,double> p2)//Function to calculate the euclidean distance
{
	double dist=sqrt((pow((p1.first-p2.first),2))+(pow((p1.second-p2.second),2)));
	return dist;
}