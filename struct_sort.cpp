// contest2.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point
{
	int x;
	int y;
	Point(int x_in, int y_in){ x = x_in; y = y_in; }
	double cos;//we sort by cos
	Point(){ x = 0; y = 0; }
};

bool compare(Point x, Point y){ return x.cos > y.cos; }
int main(void)
{
	int n;
	cin>>n;
	int x, y;
	vector <Point> f;
	f.resize(n);
	int min_x = 0;
	int min_y = 0;
	int min_index = 0;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d", &x, &y);
		//cout << x << " " << y << endl;
		f[i] = Point(x, y);
		if ((x < min_x) || (x == min_x&&y < min_y)){ min_x = x; min_y = y; min_index = i; }
	}
	for (int i = 0; i < n; i++)
	{
		if (f[i].x == min_x&&f[i].y == min_y){ f[i].cos= 1; }
		else
		{
			f[i].cos = double(f[i].y - min_y) / double((f[i].y - min_y)*(f[i].y - min_y) + (f[i].x - min_x)*(f[i].x - min_x));
		}
	}
	sort(f.begin(), f.end(), compare);
	for (int i = 0; i < n; i++)
	{
		cout << f[i].x << " " << f[i].y << endl;
	}
 	return 0;
}

