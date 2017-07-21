// contest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int Factorial(int n)
{
	int ans = 1;
	if (n == 0){ return ans; }
	for (int i = 1; i <= n; i++)
	{
		ans = ans*i;
	}
	return ans;
}
int fivesin(int n)
{
	int counter = 0;
	while (n % 5 == 0){ n = n / 5; ++counter; }
	return(counter);
}
int Zeros(int n)
{

	int fivesnum = 0;
	for (int k = 1; k <= n; k++)
	{
		fivesnum = fivesnum + fivesin(k);
	}
	return fivesnum;
}
int main(void)
{
	int n;
	//cin >> n;
	//if (n >= 5){ cout << "0" << endl; }
	for (int i = 0; i <= 100;i++)
	{ cout <<i<<" "<< fivesin(i)<<" "<<Zeros(i) % 10 << endl; }
	return 0;
}

