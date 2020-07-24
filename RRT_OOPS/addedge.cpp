#include "graphclass.h"
#include<vector>
using namespace std;

int addedge(graphclass g[],int u,int v)
{
	g[u].adj.push_back(v);
	g[v].adj.push_back(u);

	return 0;

}