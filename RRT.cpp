#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
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

pair<double,double> node_gen(int i,pair<double,double> start, pair<double,double> goal) //Function to generate the random node.
{
	srand(i);
	pair<double,double> node;
	int signx,signy;
	signx=(goal.first-start.first)>=0?1:-1;
	signy=(goal.second-start.second)>=0?1:-1;
	node.first=signx*fmod(rand(),(goal.first-start.first)+double(1));
	node.second=signy*fmod(rand(),(goal.second-start.second)+double(1));

	//cout<<"Random node "<<node.first<<" "<<node.second<<endl;

	return node;
}

double distance(pair<double,double> p1,pair<double,double> p2)//Function to calculate the euclidean distance
{
	double dist=sqrt((pow((p1.first-p2.first),2))+(pow((p1.second-p2.second),2)));
	return dist;
}

bool present(pair<int,int> p1,pair<int,int> goal,int radius) //To check if the node is present within the radius of the goal.
{
	double dist;
	dist=distance(p1,goal);
	if(dist<radius)
		return true;
	else
		return false;

}

int nearest(map<int,pair<double,double> >graph,pair<double,double> newnode) //Function to find the nearest node present to the random node
{
	map<int,double> d;
	for(auto i=graph.begin();i!=graph.end();i++)
	{
		double dist=distance(i->second,newnode);
		d[i->first]=dist;
	}

	double min_d=100000.0;
	int pos;
	for(auto it=d.begin();it!=d.end();it++)
	{
		if(it->second<min_d)
		{
			min_d=it->second;
			pos=it->first;
		}

	}

	
	return pos;

} 

int add_edge(vector<int> adj[],int u,int v)//Adding the nodes to adjacecncy list
{
	adj[u].push_back(v);
	adj[v].push_back(u);

	return 0;
}

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

int obstaclesearch(vector<pair<double,double> >obstacles, pair<double,double> newnode,double epsilon=0.0001) //search if there is an obstacle
{
	for(int i=0;i<obstacles.size();i++)
	{
		if(((fabs(obstacles[i].first-newnode.first)<epsilon))&&(fabs(obstacles[i].second-newnode.second)<epsilon))
			return 1;
	}
	return 0;
}

int rrt(map<int,pair<double,double> > &graph,int radius,vector<pair<double,double> > obstacles,pair<double,double> start, pair<double,double> goal,int iter,vector<int> adj[])
{
	double step=distance(start,goal)/10.0;//step size is dependent on the distance between start and end node
	for(int i=1;i<=iter-1;i++)
	{
		pair<double,double> node=node_gen(i,start,goal);//Random node generation
		int nnode=nearest(graph,node);// Find the index of the node that is closest to the randomly generated node.
		pair<double,double> newnode=newstep_nodegen(node,graph[nnode],step,goal); //Generating new node along the direction of the random node.
		int it=obstaclesearch(obstacles,newnode);
		if(it)
		{
			cout<<"Obstacle found"<<endl;
			continue;
		}
		graph[i]=newnode;

		add_edge(adj,nnode,i);

		if(present(newnode,goal,radius))
		{
			//cout<<"Path Found"<<endl;
			return i;
		}

	}

	return 0;
}

int search(vector<int> &results,vector<int> adj[],int pos)
{
	if(pos==0)
		return 0;
	
	for(int i=0;i<pos;i++)
	{
		auto it=find(adj[i].begin(),adj[i].end(),pos);
		if(it!=adj[i].end())
		{
			pos=i;
			break;
		}
	}

	results.push_back(pos);
	search(results,adj,pos);
	return 0;

}



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