#include<vector>
#include<iostream>
#include<utility>
#include "obstacle_gen.h"
using namespace std;
vector<pair<double,double> > obstacle_gen(int n)//Function to input obstacles
{
	vector<pair<double,double> > obstacles;
	for(int i=1;i<=n;i++)
	{
		pair<double,double> p;
		cout<<"Enter obstacle coordinates"<<endl;
		cin>>p.first;
		cin>>p.second;
		obstacles.push_back(p);
		cout<<"Obstacle"<<i<<":"<<p.first<<" "<<p.second<<endl;

	}
	return obstacles;
}