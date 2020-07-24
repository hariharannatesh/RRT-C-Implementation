#include <vector>
#include "add_edge.h"
using namespace std;
int add_edge(vector<int> adj[],int u,int v)//Adding the nodes to adjacecncy list
{
	adj[u].push_back(v);
	adj[v].push_back(u);

	return 0;
}