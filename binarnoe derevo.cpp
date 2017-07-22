// binarnoe derevo.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main(void)
{
	int n;
	string as;
	getline(cin, as);
	n = stol(as);
	vector <int> a;
	a.resize(int(pow(2,n+1)-2));
	string inp;
	getline(cin, inp);
	istringstream x_in(inp);
	string buf;
	int counter = 0;
	while (x_in >> buf)
	{
		a[counter] = atol(buf.c_str());
		++counter;
	}
	int lamps = 0;
	for (int k=n;k>0;k--)
	{
		for (int i = int(pow(2, k) - 2); i<int(pow(2, k + 1) - 2); i += 2)
		{
			lamps = lamps + (max(a[i], a[i + 1]) - min(a[i], a[i + 1]));
			a[(i-1) / 2] += max(a[i], a[i + 1]);
		}
	}
	cout << lamps << endl;
	return 0;
}

