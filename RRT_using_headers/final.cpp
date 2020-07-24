#include<iostream>
#include "distance.h"
#include "add_edge.h"
#include "node_gen.h"
#include "newstep_nodegen.h"
#include "present.h"
#include "nearest.h"
#include "obstaclesearch.h"
#include "obstacle_gen.h"
#include "search.h"
#include "rrt.h"
#include<utility>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	pair<double,double> start; //Starting Point
	pair<double,double> goal; //Ending Point
	int num_obs;//Number of obstacles
	int radius=4;//if the node is within this radius of the goal, then there is a solution.
	int iter;//Number of iterations for which the algorithm has to run.
	map<int, pair<double,double> > graph;//To store the index and the corresponding node.

	cout<<"Enter starting point as X and Y coordinates"<<endl;
	cin>>start.first;
	cin>>start.second;

	cout<<"Enter goal point as X and Y coordinates"<<endl;
	cin>>goal.first;
	cin>>goal.second;

	cout<<"Enter number of obstacles"<<endl;
	cin>>num_obs;
	cout<<"Enter number of nodes"<<endl;
	cin>>iter;
	vector<pair<double,double> > obstacles=obstacle_gen(num_obs); //Function to input obstacles.

	cout<<"Start: "<<start.first<<" "<<start.second<<endl;
	cout<<"Goal: "<<goal.first<<" "<<goal.second<<endl;

	graph[0]=start;

	for(int i=0;i<num_obs;i++)
	{

		cout<<obstacles[i].first<<" "<<obstacles[i].second<<endl;
	}

	vector<int> adj[iter];//Adjacency list of nodes 
	int val=rrt(graph,radius,obstacles,start,goal,iter,adj);//Function where RRT algo is executed.

	if(val)// Returns the index of the node which is present within the radius of the goal
		cout<<"Path Found"<<endl;
	else
	{
		cout<<"Path Not Found"<<endl;
		return 0;
	}

	//cout<<graph.size()<<endl;
	vector<int> results; //stores indices of nodes which are present in the solution
	int pos;

	for(int i=0;i<iter;i++)
	{
		/*for(int j=0;j<adj[i].size();j++)
		{
			cout<<i<<" "<<adj[i][j]<<" ";
			cout<<" "<<graph[adj[i][j]].first<<" x "<<graph[adj[i][j]].second<<" y"<<"->";
		}
		cout<<endl;*/
		auto it=find(adj[i].begin(),adj[i].end(),val);
		if(it!=adj[i].end())
		{
			pos=i;//The index of the node to which the final node is connected.
			break;
			//cout<<"Pos"<<pos<<endl;

		}
	}
	results.push_back(pos);
	results.push_back(val); 

	search(results,adj,results[0]);// Function to find the other nodes of the solution path.
	sort(results.begin(), results.end());


	/*for(int i=0;i<results.size();i++)
		cout<<results[i]<<" ";*/

	for(int i=0;i<results.size();i++)
		cout<<graph[results[i]].first<<" "<<graph[results[i]].second<<endl; //Printing the nodes present in the solution path
	cout<<endl;


	return 0;
}