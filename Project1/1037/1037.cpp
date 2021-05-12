//https://www.acmicpc.net/problem/1037

#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	int total;

	cin >> total;
	int* div = new int[total]; 

	for (int i = 0; i < total; i++)
	{
		cin >> div[i];
	}

	sort(div, div + total);

	cout << div[0] * div[total - 1];

}