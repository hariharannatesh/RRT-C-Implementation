#include<vector>
#include "graphclass.h"
#include<algorithm>
using namespace std;

int search(vector<int> &results,graphclass g[],int pos)
{
	if(pos==0)
		return 0;
	for(int i=0;i<pos;i++)
	{
		if(g[i].obstacle_flag==0)
		{
			auto it=find(g[i].adj.begin(),g[i].adj.end(),pos);
			if(it!=g[i].adj.end())
			{
				pos=i;
				break;
			}
		}
	}
	results.push_back(pos);
	search(results,g,pos);
}