#include<utility>
#include<cmath>
#include <stdlib.h>
#include "node_gen.h"
using namespace std;
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
