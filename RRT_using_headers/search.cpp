#include<vector>
#include "search.h"
#include <algorithm>
using namespace std;
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