// ostovnoe.cpp: ���������� ����� ����� ��� ����������� ����������.
//


#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

std::vector <int> p;



int dsu_get(int v) {
	cout << " Getting " << v << " it is in " << p[v] << endl;
	if (v == p[v])
	{
		return v;
	}
	else
	{
		p[v]=(dsu_get(p[v]));
		return p[v];
	}
}

void dsu_unite(int a, int b) {
	a = dsu_get(a);
	b = dsu_get(b);
	if (rand() & 1)
		std::swap(a, b);
	if (a != b)
		p[a] = b;
}

int main(void)
{
	int n=4, m=6;
	scanf_s("%d %d", &n, &m);
	vector < pair < int, pair<int, int> > > g; // ��� - ������� 1 - ������� 2
	g.resize(m);
	int len;
	int from;
	int to;
	/*int lens[6] = { 1, 1, 2, 1, 1, 1 };
	int froms[6] = { 1, 1, 1,2, 3, 2 };
	int tos[6] = { 2, 3, 4, 3, 4, 4 };*/
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d %d %d", &from, &to,&len);
		g[i] = { len, { from, to } };
		//g[i] = { lens[i], { froms[i], tos[i] } };
	}
	sort(g.begin(), g.end());
	int cost = 0;
	vector < pair<int, int> > res;
	p.resize(n+1);
	for (int i = 0; i < n+1; ++i)//cells from 1 to n are used
	{
		p[i] = i;
	}
	// ������������ �������� ��������
	for (int i = 0; i < m; ++i)
	{
		int a = g[i].second.first, b = g[i].second.second, l = g[i].first;
		//cout << "From " << a << " To " << b << " cost " << l << endl;
		if (dsu_get(a) != dsu_get(b)) {
			//cout << " a in " << dsu_get(a) << " b in " << dsu_get(b);
			cost += l;
			res.push_back(g[i].second);
			dsu_unite(a, b);
			//cout << " a in " << dsu_get(a) << " b in " << dsu_get(b);
		}
	}//
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i].first<<" "<<res[i].second << endl;
	}
	return 0;
}
