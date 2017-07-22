// LCA.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int deg_of_2(int x)
{
	return (x <= 0) ? 0 : (x & (x - 1)) == 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//initially we have one cell with index 1
	//then we need to hang each cell on another cell( ADD A B hangs B on A)
	//and then we need to respond to queries a.k.a GET A B, which get least common ancestor of A and B
	
	string ss;
	getline(cin, ss);
	int n=stol(ss);//num of queries
	vector <int> Nodes;//node
	vector <vector<int>> Ancestors;//ancestor of each node:1st,2nd,4th and so on
	Nodes.push_back(1);
	Ancestors.push_back(Nodes);
	//numeration begins from 1 - so we begin from 1 for convenience
	Ancestors.push_back(Nodes);
	Nodes.push_back(1);

	vector <int>  Depth;//depth of the graph
	Depth.push_back(0);
	Depth.push_back(0);
	string command;
	int node;
	int ancestor;
	int N = 1;
	for (int f = 0; f < n;++f)
	{
		getline(cin, command);
		istringstream command_stream(command);
		//command ancestor node
		string buf;
		int j = 0;
		while (command_stream >> buf)
		{
			if (j == 0){ command = buf; }
			if (j == 1){ ancestor = atol(buf.c_str()); }
			if (j == 2){ node = atol(buf.c_str()); }
			++j;
		}
		if (command == "ADD")
		{
			vector <int> ThisNodeAncestors;//1st,2nd,4th and so on
			int node_ans=ancestor;
			bool TillEnd = false;
			for (int i = 1;!TillEnd;i++)
			{
				if (i==1||deg_of_2(i))
				{
					ThisNodeAncestors.push_back(node_ans);
				}
				//update node_ans
				node_ans = Ancestors[node_ans][0];
				if (node_ans == 1){ TillEnd = true; }
			}
			Ancestors.push_back(ThisNodeAncestors);
			Nodes.push_back(node);
			Depth.push_back(Depth[ancestor] + 1);
			++N;
		}
		else if (command == "GET")
		{
			int var1 = ancestor;
			int var2 = node;
			if (Ancestors[var1][0] == var2){ cout << var2 << endl; }
			else if (Ancestors[var2][0] == var1){ cout << var1 << endl; }
			else
			{
				for (int i = min(int(ceil(log(N))),int(Ancestors[var2].size()-1)); i >= 0; i--)//ITERATE FROM DEPTH MAYBE???
				{
					if (Ancestors[var2][i] != Ancestors[var1][0])
					{
						var2 = Ancestors[var2][i];
					}
				}
				cout << Ancestors[var2][0] << endl;
			}
				/*
				Опишем этот процесс подробнее. Пусть L = ⌈logN⌉. Пусть сначала I = L. 
				//Если P[A][I] не является предком B, то присваиваем A = P[A][I], и уменьшаем I.
				//Если же P[A][I] является предком B, то просто уменьшаем I. 
				//Очевидно, что когда I станет меньше нуля, 
				//вершина A как раз и будет являться искомой вершиной - т.е. такой, что A не предок B, но P[A][0] - предок B.

				Теперь, очевидно, ответом на LCA будет являться P[A][0] - т.е. наименьшая вершина среди предков исходной вершины A, являющаяся также и предком B.

				Асимптотика. Весь алгоритм ответа на запрос состоит из изменения I от L = ⌈logN⌉ до 0, а также проверки на каждом шаге за O(1), является ли одна вершина предком другой. Следовательно, на каждый запрос будет найден ответ за O (log N).
				*/
		}
		else break;
	}
	return 0;
}

/*
function preprocess():
int[] p = dfs(0)
for i = 1 to n
dp[i][0] = p[i]
for j = 1 to log(n)
for i = 1 to n
dp[i][j] = dp[dp[i][j - 1]][j - 1]

int lca(int v, int u):
if d[v] > d[u]
swap(v, u)
for i = log(n) downto 0
if d[u] - d[v] \geqslant 2 ^ i
u = dp[u][i]
if v == u
return v
for i = log(n) downto 0
if dp[v][i] != dp[u][i]
v = dp[v][i]
u = dp[u][i]
return p[v]
*/