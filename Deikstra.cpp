// contest3.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
int counter;
using namespace std;
struct Node
{
	int index;
	vector<int> links;
	vector<int> routes;
	Node(){ index = counter; counter++; distance = 999999999; }
	int distance;//distance from start
	//bool visited;
	//bool visiting;
};
struct greater{
	bool operator()(const Node& x,const Node& y) const{ return x.distance > y.distance; }
};
int _tmain(int argc, _TCHAR* argv[])
{
	int n,m;
	cin >> n;
	vector <Node> nodes;
	nodes.resize(n);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int to;
		int from;
		int length;
		scanf_s("%d %d %d", &from, &to, &length);
		if (to != from)
		{
			nodes[from].links.push_back(to);
			nodes[from].routes.push_back(length);
			nodes[to].routes.push_back(length);
			nodes[to].links.push_back(from);
		}
	}
	
	int from;
	int to;
	scanf_s("%d %d", &from, &to);
	nodes[from].distance = 0;
	make_heap(nodes.begin(), nodes.end(),greater());
	vector <int> index;
	index.resize(nodes.size());

	int visit_index = 0;//check whether it's really 0(it should ALWAYS be 0)
	while (nodes[0].index!=to)
	{
		for (unsigned int i = 0; i < index.size(); i++)//initialize by -1
		{
			index[i] = -1;
		}
		for (unsigned int i = 0; i < index.size(); i++)
		{
			if (i < nodes.size())
			{
				index[nodes[i].index] = i;
			}

		}
		for (unsigned int i = 0; i < nodes[0].links.size(); i++)
		{
			int newindex = index[nodes[0].links[i]];
			if (newindex > 0)
			{
				nodes[newindex].distance = min(nodes[newindex].distance, nodes[visit_index].distance + nodes[visit_index].routes[i]);
			}
		}
		//nodes[visit_index].visited = True;
		swap(nodes[0], nodes[nodes.size() - 1]);
		nodes.pop_back();
		make_heap(nodes.begin(), nodes.end(), greater());
	}
	//sort by dist
	cout << nodes[0].distance << endl;
	
	return 0;
}

