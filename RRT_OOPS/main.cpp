#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include "graphclass.h"
#include "rrt.h"
#include "search.h"
using namespace std;
int main()
{
	pair<double,double> start;
	pair <double,double> goal;

	vector<pair<double,double> > obstacles;
	int num_obs;

	int iter=10000;
	int radius=4;

	graphclass g[iter];
	//cout<<g[0].obstacle_flag<<endl;

	cout<<"Enter start coordinates"<<endl;
	cin>>start.first>>start.second;

	cout<<"Enter goal coordinates"<<endl;
	cin>>goal.first>>goal.second;

	cout<<"Enter number of obstacles"<<endl;
	cin>>num_obs;

	for(int i=0;i<num_obs;i++)
	{
		cout<<"Enter obstacle coordinates"<<endl;
		pair<double,double> p;
		cin>>p.first>>p.second;

		obstacles.push_back(p);
	}
	g[0].node.first=start.first;
	g[0].node.second=start.second;

	int val=rrt(g,start,goal,obstacles,iter,radius);

	if(!val)
	{
		cout<<"Path not found"<<endl;
		return 0;

	}

	vector<int> results;
	int pos;
	for(int i=0;i<iter;i++)
	{
		if(g[i].obstacle_flag==0)
		{
			auto it=find(g[i].adj.begin(),g[i].adj.end(),val);
			if(it!=g[i].adj.end())
			{
				pos=i;
				break;

			}
		}
	}
	results.push_back(val);
	results.push_back(pos);

	search(results,g,pos);
	sort(results.begin(),results.end());

	for(auto it=results.begin();it!=results.end();it++)
		cout<<g[*it].node.first<<" "<<g[*it].node.second<<endl;
	return 0;





}