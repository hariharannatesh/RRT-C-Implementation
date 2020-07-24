#include "graphclass.h"
#include <utility>
#include <vector>
using namespace std;

int graphclass::obstaclesearch(vector<pair<double,double> >obstacles, pair<double,double> newnode)
{
	for(int i=0;i<obstacles.size();i++)
	{
		if(graphclass::distance(obstacles[i],newnode)<0.01)
		{
			obstacle_flag=1;
			return obstacle_flag;
		}
	}
}
